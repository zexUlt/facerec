import cv2

vs = cv2.VideoCapture('videodatabase/test.mp4')

ret, img = vs.read()
print(img)
# img = cv2.imread('database/Anvar.png')
cv2.imshow(winname="Image", mat=img)
cv2.waitKey(0)
cv2.destroyAllWindows()

cv2.imwrite('out_test/frame.jpg', img)
print(vs.isOpened())

