import serial
import time 

puertoSerie = serial.Serial('/dev/ttyUSB0', 9600)

try:
    while True:
        print("Send data")
        puertoSerie.write('A')
        time.sleep(1)

except KeyboardInterrupt:
    print("except launch")