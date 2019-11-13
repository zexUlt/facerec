from mainlayer import MainLayer
from tkinter import *
  

class PhotoLayer(MainLayer): 
    def __init__(self, tk_o):
        self.tk_path = StringVar()
        
        self.frame = Frame(tk_o)
        self.lb_frame = Frame(self.frame)
        self.lb = Listbox(self.lb_frame)
        self.lb.bind('<<ListboxSelect>>', self.currSelect)
        
        self.input_form = Entry(self.frame, textvariable=self.tk_path)
        self.addtolist_but = Button(self.frame, text="submit", command=self.update_list)

        self.frame.pack(side=LEFT)
        self.lb_frame.pack()
        self.input_form.pack(side=LEFT)
        self.addtolist_but.pack(side=RIGHT)
        self.lb.pack()
        MainLayer.__init__(self)
    
    def save_path(self, path):
        self.photos.append(path)
        
    def update_list(self):
        self.save_path(self.tk_path.get())
        self.lb.insert(END, self.tk_path.get())
        self.input_form.delete(0,END)
    
    def currSelect(self, evt):
        print(self.lb.get(self.lb.curselection()))

    # --- Send photo to database 
    # def sender(self): 
