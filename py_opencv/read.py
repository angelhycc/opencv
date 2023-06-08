import cv2 as cv

"""Reading Images"""
# img = cv.imread('photos/dog2.jpg')
# cv.imshow('DOg', img)
# cv.waitKey(0)


"""Reading Videos"""
capture = cv.VideoCapture('videos/vid1.mp4') # web cam referenced by int 0 
while True:
    isTrue, frame = capture.read()
    cv.imshow('video', frame)

    if cv.waitKey(20) & 0xFF == ord('d'):
        break
capture.release()
cv.destroyAllWindows()

