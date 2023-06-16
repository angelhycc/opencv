import cv2 as cv
import numpy as np

img = cv.imread("photos/dog1.jpg")
img = cv.resize(img, (int(img.shape[1] * 0.2), int(img.shape[0]*0.2)), interpolation=cv.INTER_LINEAR)
cv.imshow("dog",img)

blank = np.zeros(img.shape, dtype='uint8')
cv.imshow('blank', blank)


gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow("gray", gray)

"""One way to find contours"""
# blur = cv.GaussianBlur(gray, (5,5), cv.BORDER_DEFAULT)
# cv.imshow("blur", blur)
# canny = cv.Canny(blur, 125, 175)
# cv.imshow("canny", canny)

# """Threshold way"""
ret, thresh = cv.threshold(gray, 125, 255, cv.THRESH_BINARY)
cv.imshow("thresh", thresh)

# contour = py list of coordinates of the contours, hierarchies = heirarchical relationshiop of the contours 
contours, hierarchies = cv.findContours(thresh, cv.RETR_LIST, cv.CHAIN_APPROX_NONE) 
# RETR LIST = list of all contours, RETR_EXTERNAL = only the external contours RETR_TREE = all hierarchical contours
# CHAIN_APPROX_SIMPLE = compresses the contours 
cv.drawContours(blank, contours, -1, (0, 0, 255), 1)
cv.imshow('drawn', blank)

print(len(contours), " contours found")


cv.waitKey(0)