import cv2 as cv
import numpy as np

img = cv.imread('photos/dog2.jpg')

cv.imshow('dog', img)

"""Translation"""
def translate(img, x, y):
    transMat = np.float32([[1, 0, x], [0,1,y]])
    dimensions = (img.shape[1], img.shape[0]) # width, height
    return cv.warpAffine(img, transMat, dimensions)

"""Rotation"""
def rotate(img, angle, roPoint = None):
    (height, width) = img.shape[:2]
    if roPoint == None:
        roPoint = (width//2, height//2)
    rotMat = cv.getRotationMatrix2D(roPoint, angle, 1.0)
    dimenstions = (width, height)
    return cv.warpAffine(img, rotMat, dimenstions)

# TRANSLATION neg x = left, neg y = up
translatedImg = translate(img, -100, 100)
cv.imshow('translated', translatedImg)

# ROTATION neg = clockwise
rotated = rotate(img, -45)
cv.imshow('rotated', rotated)
rotated_rotated = rotate(rotated, 45)
cv.imshow('rotated-rotated', rotated_rotated)

# RESIZING
resized = cv.resize(img, (500, 500), interpolation=cv.INTER_LINEAR)
cv.imshow('resized', resized)

# FLIPPING
flipped = cv.flip(img, -1) # flip code 0 = vertical flip, 1 = horizontal flip, -1 = both
cv.imshow('flipped', flipped)

# CROPPING
cropped = img[200:400, 300:400]
cv.imshow('cropped', cropped)

cv.waitKey(0)