from tkinter import *
from mainlayer import MainLayer
from photolayer import PhotoLayer

root = Tk()
photos = PhotoLayer(root)
root.mainloop()
print(MainLayer.photos)