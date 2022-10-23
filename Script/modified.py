from send_sms import send_sms
import time



def read_file():
    with open(r"C:\Users\Niki\minecraft.log", "r") as f:
        SMRF1 = f.readlines()
    return SMRF1

pTime = time.time()



initial = read_file()
while True:
    current = read_file()
    if initial != current:
        for line in current:
            if line not in initial:
                if time.time() - pTime > 5:
                    send_sms(line[41:])
                    pTime = time.time()
                

        initial = current