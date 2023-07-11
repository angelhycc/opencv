import cv2 as cv
import numpy as np


img = cv.imread("photos/dog1.jpg")
img = cv.resize(img, (int(img.shape[1] * 0.2), int(img.shape[0]*0.2)), interpolation=cv.INTER_LINEAR)
cv.imshow("dog",img)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('gray', gray)

# Laplacian
lap = cv.Laplacian(gray, cv.CV_64F)
lap = np.uint8(np.absolute(lap))
cv.imshow("laplacian", lap)

# Sobel Gradient Magnitude Representation
sobelx = cv.Sobel(gray, cv.CV_64F, 1, 0)
sobely = cv.Sobel(gray, cv.CV_64F, 0, 1)
cv.imshow("sobelx", sobelx)
cv.imshow("sobely", sobely)
# combine
combine_sobel = cv.bitwise_or(sobelx, sobely)
cv.imshow("sobel", combine_sobel)

# canny 
canny = cv.Canny(gray, 150, 175)
cv.imshow('canny', canny)

cv.waitKey(0)