import RPi.GPIO as GPIO
import time
import os

GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(23, GPIO.IN, pull_up_down=GPIO.PUD_UP)

on_time = 0.1 # time led is ON in seconds
off_time = 0.1 # time led is OFF in seconds
counter = 0 


while counter <=60:
    GPIO.output(18, GPIO.HIGH)
    time.sleep(on_time)
    GPIO.output(18, GPIO.LOW)
    time.sleep(off_time)
    input_state = GPIO.input(23)
    counter += 1
    if input_state == False:
        print('Button Pressed')
        os.system ("cat /home/pi/iotpos/printing/spool > /dev/ttyAMA0")
        GPIO.cleanup()
        time.sleep(0.2)
        exit()
GPIO.cleanup()
exit()

