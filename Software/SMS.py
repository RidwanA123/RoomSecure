import serial
import time
import os
from twilio.rest import Client
import base64

arduino = serial.Serial('COM4',9600,timeout=0.1)
def send_sms():
    text = ("Someone or Something Entered your room! Go Check it out!")
    account_sid = "AC1d20c171fb735b195dadb5144e1c7cfe"
    auth_token = "e41f64ab63da5cca7b56795baad1e667"
    client = Client(account_sid, auth_token)

    message = client.messages \
        .create(
            body=text,
            from_='+16108903881',
            to='+15197215818'
        )
while True:
    trigger = arduino.readline().strip().decode("utf-8")
    if trigger == "TRIPPED":
        send_sms()


        
