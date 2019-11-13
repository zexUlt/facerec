from mainlayer import MainLayer
from tkinter import *
  

class PhotoLayer(MainLayer): 
    def __init__(self, tk_o):
        self.tk_path = StringVar()
        
        self.frame = Frame(tk_o, width=512, height=512)
        self.lb_frame = Frame(self.frame)
        self.lb = Listbox(self.lb_frame)
        self.lb.bind('<<ListboxSelect>>', self.cursorSelect)
        
        self.popup_menu = Menu(self.lb_frame, tearoff=0)
        self.popup_menu.add_command(label='print', command=self.printtext)
        self.popup_menu.add_command(label='fuck off!', command=quit)
        
        self.input_form = Entry(self.frame, textvariable=self.tk_path)
        self.addtolist_but = Button(self.frame, text="submit", command=self.update_list)

        self.frame.pack(fill=BOTH)
        self.lb_frame.pack(fill=BOTH)
        self.input_form.pack(fill=BOTH)
        self.addtolist_but.pack(fill=BOTH)
        self.lb.pack(fill=BOTH)
        MainLayer.__init__(self)
    
    def save_path(self, path):
        self.photos.append(path)
        
    def update_list(self):
        self.save_path(self.tk_path.get())
        self.lb.insert(END, self.tk_path.get())
        self.input_form.delete(0,END)
    
    def cursorSelect(self, event):
        x = self.frame.winfo_pointerx()
        y = self.frame.winfo_pointery()      
        self.popup_menu.post(x,y)
        

    def printtext(self):
        print(self.lb.get(self.lb.curselection()))

    # --- Send photo to database 
    # def sender(self): 
