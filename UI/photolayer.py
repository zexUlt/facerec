from mainlayer import MainLayer
from tkinter import *
  

class PhotoLayer(MainLayer): 
    def __init__(self, tk_o):
        self.tk_path = StringVar()
        
        self.frame = Frame(tk_o)
        self.lb_frame = Frame(self.frame)
        self.lb = Listbox(self.lb_frame)

        self.input_form = Entry(self.frame, textvariable=self.tk_path)
        self.addtolist_but = Button(self.frame, text="submit", command=self.update_list)

        self.lb.pack()
        self.frame.pack(side=LEFT)
        self.input_form.pack(side=LEFT)
        self.addtolist_but.pack(side=RIGHT)
        MainLayer.__init__(self)
    
    def save_path(self, path):
        self.photos.append(path)
        
    def update_list(self):
        self.lb.insert(END, self.save_path(self.tk_path.get()))
    
    # def show_list(self):
    #     for i in photos:
    # --- Send photo to database 
    # def sender(self): 
