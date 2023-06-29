import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

img = cv.imread("photos/dog1.jpg")
img = cv.resize(img, (int(img.shape[1] * 0.2), int(img.shape[0]*0.2)), interpolation=cv.INTER_LINEAR)
cv.imshow("dog",img)

blank = np.zeros(img.shape[:2], dtype='uint8')
cv.imshow('blank', blank)

circle_mask = cv.circle(blank.copy(), (img.shape[1]//2, img.shape[0]//2 + 45), 100, 255, -1)
cv.imshow('circle mask', circle_mask)

gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
cv.imshow('gray', gray)

maskedimg = cv.bitwise_and(gray, gray, mask=circle_mask)
cv.imshow('mask', maskedimg)

gray_hist0 = cv.calcHist([gray], [0], None, [256], [0, 256])
gray_hist = cv.calcHist([gray], [0], circle_mask, [256], [0, 256])

# plt.figure()
# plt.title('gray scale histogram')
# plt.xlabel('bins')
# plt.ylabel('num of pixels')
# plt.plot(gray_hist)
# plt.plot(gray_hist0)
# plt.xlim([0, 256])
# plt.show()

# color histogram
plt.figure()
plt.title('gray scale histogram')
plt.xlabel('bins')
plt.ylabel('num of pixels')
colors = ('b', 'g', 'r')
for i, col in enumerate(colors):
    hist = cv.calcHist([img], [i], circle_mask, [256], [0,256])
    plt.plot(hist, color=col)
    plt.xlim(0, 256)
plt.show()



cv.waitKey(0)