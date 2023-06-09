import cv2 as cv 
import numpy as np

blank = np.zeros((500,500, 3), dtype='uint8') # data type of an image
cv.imshow('blank', blank)

""" 1. Paint an image"""
green = blank.copy()
green [:] = 0, 255, 0
cv.imshow('Green', green)

""" 2. Paint certain areas"""
area = blank.copy()
area[200:300, 200:400] = 0, 0, 255
cv.imshow('Area', area)

""" 3. Draw Rectangles """
rectangle = blank.copy()
# rectangle(image to draw on, left upper corner, right lower corner, color, thickness)
cv.rectangle(rectangle, (0,0), (250, 500), (255, 0, 0), thickness=2) # thickness = cv.FILLED === thickness = -1
cv.imshow('rectangle', rectangle)

""" 4. Draw Circles """
circle = blank.copy()
# circle (image to draw on, center, radius, color, thickness)
cv.circle(circle, (250, 250), 40, (0, 255, 0), 3) 
cv.imshow('circle', circle)

""" 5. Draw a Line """
line = blank.copy()
# line (image to draw on, starting point, end point, color, thickness)
cv.line(line, (0, 0), (250, 250), (255, 0, 255), 3)
cv.imshow('line', line)

""" 6. Write Text """
text = blank.copy()
# text (image to draw on, text, starting point, font, fontsize, color, thickness)
cv.putText(text, 'Hello', (225, 225), cv.FONT_HERSHEY_TRIPLEX, 1.0, (0, 255, 255), 2)
cv.imshow('text', text)



cv.waitKey(0)