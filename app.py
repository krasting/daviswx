from flask import Flask
app = Flask(__name__)

# get current obs
import daviswx
O = daviswx.getobs.current()

@app.route('/')
def hello():
    msg = "Hello World!  The current temperature is: "+str(O.rtOutsideTemp)
    return msg

if __name__ == '__main__':
    app.run("0.0.0.0", port=80, debug=True)
