import os

from UDPComms import Publisher, Subscriber, timeout

import time

## Configurable ##
MESSAGE_RATE = 20

joystick_pub = Publisher(8830,65530)
joystick_subcriber = Subscriber(8840, timeout=0.01)

# Functiom to read from txt file. 
# 0 = Deactivated
# 1 = Activated
# Run_robot_with_states will update the state in the txt file.
def read_from_txt():
	file1 = open("/home/ubuntu/Robotics/QuadrupedRobot/StanfordQuadruped/State.txt", "r")
	StringTemp = file1.read()
	file1.close()
	return StringTemp

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

 ######################################################################
         #########
         ########
         #######
         ######
         #####                      SEQENCER HERE
         ####                           !
         ###                            V
         ##
         #  
#START  of the SEQENCER ##################   KNN  ####################

#Run function to read sate from txt
state = read_from_txt()

while True :
    if state == "0":
        if cycle_counter == 40:
            msg['L1'] = 1           #simulate L1 button press
        if cycle_counter == 42:
            msg['L1'] = 0           #simulate L1 button release
    
    if cycle_counter == 50:    
        msg['rx'] = 0.3         #Look left (Right stick)
    if cycle_counter == 70:    
        msg['rx'] = 0          #Look back to 0
  
    if cycle_counter == 90:    
        msg['rx'] = -0.3        #Look right
    if cycle_counter == 110:    
        msg['rx'] = 0           #Look back to 0

    if cycle_counter == 130:    
        msg['ry'] = 0.4         #Look up
    if cycle_counter == 150:
        msg['ry'] = -0          #Look back to 0

    if cycle_counter == 170:    
        msg['ry'] = -0.4        #Look down
    if cycle_counter == 190:
        msg['ry'] = 0           #Look back to 0

   
    if cycle_counter == 200:    
        msg['dpady'] = 1        #Rise up
    if cycle_counter == 220:
        msg['dpady'] = 0        #stop

    if cycle_counter == 230:    
        msg['dpady'] = -1       #Lower down
    if cycle_counter == 250:
        msg['dpady'] = 0        #stop

    if cycle_counter == 260:    
        msg['dpadx'] = 1        #tilt right
    if cycle_counter == 270:
        msg['dpadx'] = 0        #stop

    if cycle_counter == 280:    
        msg['dpadx'] = -1        #tilt left
    if cycle_counter == 300:
        msg['dpadx'] = 0        #stop

    if cycle_counter == 310:    
        msg['dpadx'] = 1        #tilt right
    if cycle_counter == 320:
        msg['dpadx'] = 0        #stop



    if cycle_counter == 410:
        msg['R1'] = 1           #simulate R1 button press(Trot mode activate)
    if cycle_counter == 412:
        msg['R1'] = 0           #simulate R1 button release


    if cycle_counter == 420:    
        msg['ly'] = 0.5         #Walk forward (left stick up)
    if cycle_counter == 440:    
        msg['ly'] = 0           #Stop (left stik at 0)

    if cycle_counter == 460:    
        msg['ly'] = -0.5         #Walk back (left stick down)
    if cycle_counter == 480:    
        msg['ly'] = 0            #Stop (left stik at 0)

    if cycle_counter == 500:    
        msg['lx'] = 0.5         #Walk right (left stick right)
    if cycle_counter == 520:    
        msg['lx'] = 0           #Stop (left stik at 0)

    if cycle_counter == 540:    
        msg['lx'] = -0.5         #Walk back (left stick left)
    if cycle_counter == 560:    
        msg['lx'] = 0            #Stop (left stik at 0)


    if cycle_counter == 562:
        msg['R1'] = 1           #simulate R1 button press(Trot mode stop)
    if cycle_counter == 564:
        msg['R1'] = 0           #simulate R1 button release

    if cycle_counter == 580:
        msg['square'] = 1        #simulate square button press
    if cycle_counter == 582:
        msg['square'] = 0        #simulate square button release


    if cycle_counter == 584:
        msg['L1'] = 1           #simulate L1 button press
    if cycle_counter == 586:
        msg['L1'] = 0           #simulate L1 button release

    if cycle_counter == 600:
        #cycle_counter = 0      #If a loop is wanted
        exit()


    cycle_counter = cycle_counter + 1
    joystick_pub.send(msg)

    time.sleep(1 / MESSAGE_RATE)
