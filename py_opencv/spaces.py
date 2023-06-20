import cv2 as cv 
# import matplotlib.pyplot as plt
import numpy as np 



img = cv.imread("photos/dog2.jpg")
cv.imshow("dog", img)

# plt.imshow(img)
# plt.show()

""" gray scale """
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('gray', gray)

""" BGR to HSV hue saturation value"""
hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
cv.imshow ('hsv', hsv)

""" BGR to LAB """
lab = cv.cvtColor(img, cv.COLOR_BGR2LAB)
cv.imshow('lab', lab)

""" BGR to RGB """ # Open cv default is bgr, matplot lib is rgb 
rgb = cv.cvtColor(img, cv.COLOR_BGR2RGB)
cv.imshow('rgb', rgb)
# plt.imshow(rgb)
# plt.show()

# can do all the inverses, only cannot convert grayscale to hsv directly 
""" HSV to BGR """
hsv_bgr = cv.cvtColor(hsv, cv.COLOR_HSV2BGR)
cv.imshow('hsv2bgr', hsv_bgr)

""" LAB to BGR """
lab_bgr = cv.cvtColor(lab, cv.COLOR_LAB2BGR)
cv.imshow('lab_bgr', lab_bgr)

cv.waitKey(0)