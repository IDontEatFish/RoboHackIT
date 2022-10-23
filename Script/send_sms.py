from twilio.rest import Client
from credentials import account_sid, auth_token, my_cell, my_twilio
from datetime import datetime


def send_sms(command):
    client = Client(account_sid, auth_token)

    my_msg = f'Watch out someone triggered your alarm named {command}! Time: {datetime.now().strftime("%d/%m/%Y %H:%M:%S")}'


    message = client.messages.create(to=my_cell, from_=my_twilio, body=my_msg)

