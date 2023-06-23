# import the opencv library
import cv2 as cv

  
  
# define a video capture object
vid = cv.VideoCapture(0)
  
def rescaleFrame(frame, scale=0.75):
    # works for Photos, Videos, Live Videos
    width = int(frame.shape[1]*scale)
    height = int(frame.shape[0]*scale)
    dimensions = (width, height)

    return cv.resize(frame, dimensions, interpolation=cv.INTER_AREA)

while(True):
      
    # Capture the video frame
    # by frame
    ret, frame = vid.read()
    # Display the resulting frame
    frame = rescaleFrame(frame, 0.25)

    cv.imshow('frame', frame)

    # the 'q' button is set as the
    # quitting button you may use any
    # desired button of your choice
    if cv.waitKey(1) & 0xFF == ord('q'):
        break
  
# After the loop release the cap object
vid.release()
# Destroy all the windows
cv.destroyAllWindows()