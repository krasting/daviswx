from flask import Flask, render_template, request
from flask_apscheduler import APScheduler
import datetime
import daviswx
import os
import pandas as pd
from pandas.plotting import register_matplotlib_converters
import time

import matplotlib
matplotlib.use('Agg')

import base64
import io
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

register_matplotlib_converters()
plt.rcParams.update({'font.size': 12})
matplotlib.rcParams['timezone'] = 'US/Eastern'

app = Flask(__name__)

def make_plot(x):
    _x = x.copy()
    _x = convert_timezone(_x)
    fig = plt.figure(figsize=(8,4.5))                                                                                 
    ax = plt.subplot(1,1,1)
    # plot the data
    plt.plot(_x.index,_x.rtOutsideTemp,'b',linewidth=2)
    # add title and format tick labels
    ax.text(0.02,1.02,'Temperature',transform=ax.transAxes)
    myFmt = mdates.DateFormatter('%H:%M')
    ax.xaxis.set_major_formatter(myFmt)
    # add grid lines
    plt.grid(True)
    # save the figure and return the text
    imgdata = io.BytesIO()
    plt.savefig(imgdata,bbox_inches='tight')
    uri = 'data:image/png;base64,' + base64.b64encode(imgdata.getvalue()).decode('utf-8').replace('\n', '')
    plt.close('all')
    del fig
    del imgdata
    return '<img src = "%s"/>' % uri

def filter_dataframe(df):
    onedayago = datetime.datetime.utcnow() - datetime.timedelta(hours=24)
    df = df[df.index >= onedayago]
    df = df.drop_duplicates()
    df = df.sort_values(by='rtObsTime',ascending=False)
    df.to_pickle('./obs_dataframe.pkl')
    return df

def convert_timezone(x):
    dti = x.index
    dti = dti.tz_localize(datetime.timezone.utc)
    dti = dti.tz_convert('US/Eastern')
    _x = x.copy()
    _x.index = dti
    return _x

# setup a testing mode
if os.path.exists('./test_data.pkl'):
    production_mode = False
else:
    production_mode = True

# get current obs
O = daviswx.getobs.current()
if production_mode is True:
    if os.path.exists('./obs_dataframe.pkl'):
        df = pd.read_pickle("./obs_dataframe.pkl")
    else:
        df = pd.DataFrame(O.__dict__,index=[O.rtObsTime,])
    time.sleep(10)
else:
    df = pd.read_pickle('./test_data.pkl')
img = make_plot(df)

def update_wunderground(O):
    dateutc = datetime.utcnow().strftime('%Y-%m-%d %H:%M:%S').replace(':','%3A').replace(' ','+')
    #upload_url = 'http://weatherstation.wunderground.com/weatherstation/updateweatherstation.php'
    upload_url = 'https://rtupdate.wunderground.com/weatherstation/updateweatherstation.php'
    WU_STATION_ID = ''
    WU_PASSWORD = ''
    url = upload_url+"?ID="+WU_STATION_ID+"&PASSWORD="+WU_PASSWORD+"&dateutc=" + \
          dateutc + "&tempf=" + str(O.rtOutsideTemp) + "&humidity=" + str(O.rtOutsideHum) + \
          "&dailyrainin=" + str(O.rtDayRain) + "&baromin=" + str(O.rtBaroCurr) + \
          "&dewptf=" + str(O.rtOutsideDew) +"&action=updateraw"
    pwsstatus = urllib.urlopen(url)

#function executed by scheduled job
def my_job(hostname,port):
    global O
    global df
    global img
    O = daviswx.getobs.current()
    df = df.append(pd.DataFrame(O.__dict__,index=[O.rtObsTime,]))
    df = filter_dataframe(df)
    img = make_plot(df)

@app.route('/')
def hello():
    return render_template('current.html', \
             temp=str(O.rtOutsideTemp), \
             humidity=str(O.rtOutsideHum), \
             barometer=str(O.rtBaroCurr), \
             raintoday=str(O.rtDayRain), \
             plot=img,\
             dataframe = df[['rtOutsideTemp','rtOutsideHum']].to_html())

if __name__ == '__main__':
    if production_mode is True:
        scheduler = APScheduler()
        hostname = os.environ['DAVIS_HOSTNAME']
        port = os.environ['DAVIS_PORT']
        scheduler.add_job(func=my_job, args=[hostname,port], id='job', \
            trigger='cron', minute='*/5')
        scheduler.start()
    # reloader == False below to prevent double-execution of scheduler jobs
    app.run("0.0.0.0", port=80, debug=True, use_reloader=False)
