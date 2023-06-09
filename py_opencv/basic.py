import cv2 as cv

def rescaleFrame(frame, scale=0.75):
    # works for Photos, Videos, Live Videos
    width = int(frame.shape[1]*scale)
    height = int(frame.shape[0]*scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

img = cv.imread('photos/dog1.jpg')
# img = rescaleFrame(img, 0.25)
cv.imshow('Dog', img)

""" 1. Convert to Greyscale """
gray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
# cv.imshow('gray', gray)

""" 2. Blur Image (removing noise) """
blur = cv.GaussianBlur(img, (7,7), cv.BORDER_DEFAULT)
# cv.imshow('blur', blur)

""" 3. Edge Cascade """
canny = cv.Canny(img, 125, 175)
# cv.imshow('canny', canny)

""" 4. Dilate Image """
dilate = cv.dilate(canny, (7,7), iterations=3)
# cv.imshow('dilated', dilate)

""" 5. Eroding """
eroded = cv.erode(dilate, (7,7), iterations=3)
# cv.imshow('erode',eroded)

""" 6. Resize """
resize = cv.resize(img, (500,500), interpolation= cv.INTER_AREA) # INTER_CUBIC(better resolution, takes longer), INTER_LINEAR == for enlarging 
cv.imshow('resize', resize)

""" 7. Crop """
crop = img[50:200, 200:400]
cv.imshow('crop', crop)


cv.waitKey(0)
