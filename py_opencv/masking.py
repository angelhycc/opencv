import cv2 as cv
import numpy as np


img = cv.imread("photos/dog1.jpg")
img = cv.resize(img, (int(img.shape[1] * 0.2), int(img.shape[0]*0.2)), interpolation=cv.INTER_LINEAR)
cv.imshow("dog",img)

blank = np.zeros(img.shape[:2], dtype='uint8')
cv.imshow('blank', blank)
circle_mask = cv.circle(blank.copy(), (img.shape[1]//2, img.shape[0]//2 + 45), 100, 255, -1)
cv.imshow('mask', circle_mask)
rectangle = cv.rectangle(blank.copy(), (300, 300),(400, 400), 255, -1)
weird_shape = cv.bitwise_and(rectangle, circle_mask)


masked_img = cv.bitwise_and(img, img, mask=circle_mask)
cv.imshow("masked img", masked_img)

weirdshape_img = cv.bitwise_and(img, img, mask=weird_shape)
cv.imshow("weird shape", weirdshape_img)

cv.waitKey(0)