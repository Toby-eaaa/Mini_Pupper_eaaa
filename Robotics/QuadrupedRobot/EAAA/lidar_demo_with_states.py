import os

import okdoLidar

from UDPComms import Publisher, Subscriber, timeout

import time

## Configurable ##
MESSAGE_RATE = 20

joystick_pub = Publisher(8830,65530)
joystick_subcriber = Subscriber(8840, timeout=0.01)

cycle_counter = 0

# Read state of the minipupper
def read_from_txt():
    file1 = open("/home/ubuntu/Robotics/QuadrupedRobot/StanfordQuadruped/State.txt", "r")
    StringTemp = file1.read()
    file1.close()
    return StringTemp

# Activate trot
def walk():
    state = read_from_txt()
    if state == "0" or state == "1":
        msg['L1'] = 1 
        joystick_pub.send(msg) 
        time.sleep(0.1)
        msg['L1'] = 0  
        joystick_pub.send(msg)
        time.sleep(0.1)

    msg['R1'] = 1 
    joystick_pub.send(msg) 
    time.sleep(0.1)
    msg['R1'] = 0  
    joystick_pub.send(msg)

# Stop trot
def stop():
    if state == "1" or state == "2":
        msg['L1'] = 1 
        joystick_pub.send(msg) 
        time.sleep(0.1)
        msg['L1'] = 0  
        joystick_pub.send(msg)
        time.sleep(0.1)

msg = {
    "ly": 0,    #range from -1 to 1
    "lx": 0,    #range from -1 to 1
    "rx": 0,    #range from -1 to 1
    "ry": 0,    #range from -1 to 1
    "L2": 0,    #0 or 1
    "R2": 0,    #0 or 1
    "R1": 0,    #0 or 1
    "L1": 0,    #0 or 1
    "dpady": 0, #-1 or 0 or 1
    "dpadx": 0, #-1 or 0 or 1
    "x": 0,     #0 or 1
    "square": 0,    #0 or 1
    "circle": 0,    #0 or 1
    "triangle": 0,  #0 or 1
    "message_rate": MESSAGE_RATE,
}



# Activating trot
walk()

while True:
    dat = okdoLidar.getFrame()

    # dat consist of 3 arrays, angle, distance, confidence
   
    dat_len = len(dat[0])


    for i in range(dat_len):

        # The lidars range can be a bit high, so to limit interference we have our first check on distance (dat[1][i]) and confidence (dat[2][i][2])
        if (((dat[1][i]) < 100) & (dat[2][i][2] > 200)):

            # Here we check on the angles dat[0][i]
            match dat:
                case _ if((dat[0][i])> 90) & ((dat[0][i]) <= 250):
                    print("venstre")
                    msg['rx'] = -0.1
                    msg['ly'] = 0.0
                case _ if((dat[0][i]) >= 290):
                    print("højre")
                    msg['rx'] = 0.1
                    msg['ly'] = 0.0
                case _ if((dat[0][i])>250) & ((dat[0][i]) < 290):
                    print("RUN!")
                    msg['rx'] = 0.0
                    msg['ly'] = 0.0
                case _ if((dat[0][i])>250) & ((dat[0][i]) < 290):
                    print("RUN!")
                    msg['rx'] = 0.0
                    msg['ly'] = 0.0
                case _ if((dat[0][i])< 90) & ((dat[0][i]) >= 0):
                    print("højre")
                    msg['rx'] = 0.1
                    msg['ly'] = 0.0
        

        joystick_pub.send(msg)
        #time.sleep(0.1)
        
        
