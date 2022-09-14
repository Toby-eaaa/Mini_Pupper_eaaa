import blobconverter
#import cv2  # cv2 bliver brugt til at vise camera
import depthai as dai
import time

from numpy import interp

from UDPComms import Publisher, Subscriber, timeout


class HostSync:
    def __init__(self):
        self.arrays = {}
    def add_msg(self, name, msg):
        if not name in self.arrays:
            self.arrays[name] = []
        self.arrays[name].append(msg)
    def get_msgs(self, seq):
        ret = {}
        for name, arr in self.arrays.items():
            for i, msg in enumerate(arr):
                if msg.getSequenceNum() == seq:
                    ret[name] = msg
                    self.arrays[name] = arr[i:]
                    break
        return ret





## Configurable ##
MESSAGE_RATE = 20

joystick_pub = Publisher(8830,65530)
joystick_subcriber = Subscriber(8840, timeout=0.02)

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
# Functiom to read from txt file. 
# 0 = Deactivated
# 1 = Activated
# Run_robot_with_states will update the state in the txt file.


def create_pipeline():
    print("Creating pipeline...")
    pipeline = dai.Pipeline()

    # ColorCamera
    print("Creating Color Camera...")
    cam = pipeline.create(dai.node.ColorCamera)
    cam.setPreviewSize(300, 300)
    cam.setResolution(dai.ColorCameraProperties.SensorResolution.THE_1080_P)
    cam.setVideoSize(1080,1080)
    cam.setInterleaved(False)

    cam_xout = pipeline.create(dai.node.XLinkOut)
    cam_xout.setStreamName("frame")
    cam.video.link(cam_xout.input)

    # NeuralNetwork
    print("Creating Face Detection Neural Network...")
    face_det_nn = pipeline.create(dai.node.MobileNetDetectionNetwork)
    face_det_nn.setConfidenceThreshold(0.5)
    face_det_nn.setBlobPath(blobconverter.from_zoo(
        name="face-detection-retail-0004",
        shaves=6,
    ))
    # Link Face ImageManip -> Face detection NN node
    cam.preview.link(face_det_nn.input)

    objectTracker = pipeline.create(dai.node.ObjectTracker)
    objectTracker.setDetectionLabelsToTrack([1])  # track only person
    # possible tracking types: ZERO_TERM_COLOR_HISTOGRAM, ZERO_TERM_IMAGELESS, SHORT_TERM_IMAGELESS, SHORT_TERM_KCF
    objectTracker.setTrackerType(dai.TrackerType.ZERO_TERM_COLOR_HISTOGRAM)
    # take the smallest ID when new object is tracked, possible options: SMALLEST_ID, UNIQUE_ID
    objectTracker.setTrackerIdAssignmentPolicy(dai.TrackerIdAssignmentPolicy.SMALLEST_ID)

    # Linking
    face_det_nn.passthrough.link(objectTracker.inputDetectionFrame)
    face_det_nn.passthrough.link(objectTracker.inputTrackerFrame)
    face_det_nn.out.link(objectTracker.inputDetections)
    # Send face detections to the host (for bounding boxes)

    pass_xout = pipeline.create(dai.node.XLinkOut)
    pass_xout.setStreamName("pass_out")
    objectTracker.passthroughTrackerFrame.link(pass_xout.input)

    tracklets_xout = pipeline.create(dai.node.XLinkOut)
    tracklets_xout.setStreamName("tracklets")
    objectTracker.out.link(tracklets_xout.input)
    print("Pipeline created.")
    return pipeline

def run(device, Sand_old):

    face_xy = {
    "x": 0,
    "y": 0
    }
    
    frame_q = device.getOutputQueue("frame")
    tracklets_q = device.getOutputQueue("tracklets")
    pass_q = device.getOutputQueue("pass_out")
    sync=HostSync()
    
    sync.add_msg("color", frame_q.get())

    # Used to control time between readings from cam
    Sand_now = time.time()
    if (Sand_now-Sand_old >= 0.00):
        Sand_old = time.time()

        nn_in = tracklets_q.tryGet()

        if nn_in is not None:
            seq = pass_q.get().getSequenceNum()
            msgs = sync.get_msgs(seq)

            for t in nn_in.tracklets:
                
                t.roi.x -= t.roi.width / 10
                t.roi.y -= t.roi.height / 7
                face_xy['x'] =t.roi.x
                face_xy['y'] =t.roi.y

                return face_xy
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
#############################
#            |              #
#            |              #
#            |              #
#            y              #
#------------|x-------------#
#            |              #
#            |              #
#            |              #
#############################

with dai.Device(create_pipeline()) as device:
    coords_from_program = {
        "x": 0,
        "y": 0
        }
    

    
    msg['L1'] = 1           #simulate L1 button press
    joystick_pub.send(msg) 
    time.sleep(0.1)
    msg['L1'] = 0
    joystick_pub.send(msg)

    Sand_old = 0

    def convert(coord):
        return interp(coord, [0,1], [-0.5,0.5])
        

    while True:
        coords_from_program = run(device, Sand_old) 
        if coords_from_program is not None:
            x = coords_from_program["x"]
            y = coords_from_program["y"]
            #print("X: ", x)  # print coordinates
            #print("Y: ", y)
            msg['rx'] = convert(x)
            msg['ry'] = convert(y) * -1
            
            joystick_pub.send(msg)  


