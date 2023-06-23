import cv2 as cv
import numpy as np

img = cv.imread("photos/dog1.jpg")
img = cv.resize(img, (int(img.shape[1] * 0.2), int(img.shape[0]*0.2)), interpolation=cv.INTER_LINEAR)
cv.imshow("dog",img)

# Averaging 
average = cv.blur(img, (3,3))
cv.imshow("averaged ", average)

# Gaussian
gaussian = cv.GaussianBlur(img, (3,3), 0)
cv.imshow("gaussian", gaussian)

# median blur
median = cv.medianBlur(img, 3)
cv.imshow("median", median)

# bilateral blurring (most effective) blurred, but also preserve edges
bilateral = cv.bilateralFilter(img, 5, 100, 100)
cv.imshow("bilateral", bilateral)

cv.waitKey(0)