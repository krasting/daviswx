from flask import Flask
from flask_apscheduler import APScheduler
import datetime
import os
import time

app = Flask(__name__)

# get current obs
import daviswx
O = daviswx.getobs.current()
time.sleep(10)


#function executed by scheduled job
def my_job(hostname,port):
    global O
    O = daviswx.getobs.current()


@app.route('/')
def hello():
    msg = "Hello World!  The current temperature is: "+str(O.rtOutsideTemp)+\
        ' at '+O.rtObsTime.strftime('%Y-%m-%d %H:%M' )
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
