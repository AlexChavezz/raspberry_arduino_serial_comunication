import json
from flask import Flask, jsonify
import serial
serial_port = serial.Serial('/dev/ttyUSB0', 9600)

def encodeAndSend(code):
    data = code.encode()
    serial_port.write(data)    


server = Flask(__name__)
@server.route("/<string:action>")
def home(action):
    if action == "ahead":
        encodeAndSend('A')
    elif action == "left":
        encodeAndSend('L')
    elif action == "right":
        encodeAndSend('R')
    elif action == "back":
        encodeAndSend('B')
    elif action == "stop":
        encodeAndSend('S')
    elif action == "frontLightsON":
        encodeAndSend('W')
    elif action == "frontLightsOFF":
        encodeAndSend('Q')
    elif action == "backLightsON":
        encodeAndSend('E')
    elif action == "backLightsOFF":
        encodeAndSend('D')

    return jsonify({"action": "not found"})
        


if __name__ == "__main__":
    server.run(host="0.0.0.0")
