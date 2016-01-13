import RPi.GPIO as GPIO
import time
import os
ledPin       = 18
buttonPin    = 23

GPIO.setmode(GPIO.BCM)
GPIO.setup(ledPin, GPIO.OUT)
GPIO.setup(buttonPin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

on_time = 0.1 # time led is ON in seconds
off_time = 0.1 # time led is OFF in seconds
counter = 0


while counter <=60:
    GPIO.output(ledPin, GPIO.HIGH)
    time.sleep(on_time)
    GPIO.output(ledPin, GPIO.LOW)
    time.sleep(off_time)
    input_state = GPIO.input(buttonPin)
    counter += 1
    if input_state == False:
        print('Button Pressed')
        os.system ("cat /home/pi/iotpos/printing/spool > /dev/ttyAMA0")
        time.sleep(0.2)
        break;
GPIO.cleanup()
exit()
