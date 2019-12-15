from flask import Flask
from flask_apscheduler import APScheduler
import datetime
import time

app = Flask(__name__)

# get current obs
import daviswx
O = daviswx.getobs.current()
time.sleep(10)

#function executed by scheduled job
def my_job(text):
    global O
    O = daviswx.getobs.current()

@app.route('/')
def hello():
    msg = "Hello World!  The current temperature is: "+str(O.rtOutsideTemp)+' at '+O.rtObsTime.strftime('%Y-%m-%d %H:%M' )
    return msg

if __name__ == '__main__':
    scheduler = APScheduler()
    scheduler.add_job(func=my_job, args=['job run'], trigger='interval', id='job', seconds=300)
    scheduler.start()
    app.run("0.0.0.0", port=80, debug=True)
