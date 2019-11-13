from tkinter import *
from mainlayer import MainLayer
from photolayer import PhotoLayer
from videolayer import VideoLayer
from tkinter.ttk import Separator

def main():
    root = Tk()
    photo = PhotoLayer(root)

    Separator(root, orient=VERTICAL).grid(padx=10,sticky=N+S,column=1,row=0)

    video = VideoLayer(root)
    root.mainloop()
    print(MainLayer.photos)

if __name__ == "__main__":
    main()