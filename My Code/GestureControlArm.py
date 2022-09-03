import cv2
import cvzone
from testFile import HandDetector


cap = cv2.VideoCapture(0)
detector = HandDetector(maxHands=1)
mySerial = cvzone.SerialObject("COM11", 9600, 1)

while True:
    success, img = cap.read()
    img = detector.findHands(img)
    bbox = detector.findPosition(img)
    lmList = detector.findPosition(img)
    if lmList:
        fingers = detector.fingersUp()
        print(fingers)
        mySerial.sendData(fingers)
    cv2.imshow("Image", img)
    cv2.waitKey(1)