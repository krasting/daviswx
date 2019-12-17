from flask import Flask
from flask_apscheduler import APScheduler
import datetime
import os
import pandas as pd
import time

app = Flask(__name__)

# get current obs
import daviswx
O = daviswx.getobs.current()
df = pd.DataFrame(O.__dict__,index=[O.rtObsTime,])
time.sleep(10)

def filter_dataframe(df):
    onedayago = datetime.datetime.utcnow() - datetime.timedelta(hours=24)
    df = df[df.index >= onedayago]
    df = df.drop_duplicates()
    return df

#function executed by scheduled job
def my_job(hostname,port):
    global O
    global df
    O = daviswx.getobs.current()
    df = df.append(pd.DataFrame(O.__dict__,index=[O.rtObsTime,]))
    df = filter_dataframe(df)

@app.route('/')
def hello():
    msg = "Hello World!  The current temperature is: "+str(O.rtOutsideTemp)+\
        ' at '+O.rtObsTime.strftime('%Y-%m-%d %H:%M' )
    msg = df[['rtOutsideTemp','rtOutsideHum']].to_html()
    return msg

if __name__ == '__main__':
    scheduler = APScheduler()
    hostname = os.environ['DAVIS_HOSTNAME']
    port = os.environ['DAVIS_PORT']
    scheduler.add_job(func=my_job, args=[hostname,port], id='job', \
        trigger='cron', minute='*/5')
    scheduler.start()
    # reloader == False below to prevent double-execution of scheduler jobs
    app.run("0.0.0.0", port=80, debug=True, use_reloader=False)
