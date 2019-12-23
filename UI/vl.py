from tkinter import *
from tkinter import filedialog
from mainlayer import MainLayer
from mainlayer import Style
from shutil import copy2

class VideoLayer(MainLayer):
    def __init__(self, tk_o):
        super().__init__()

        self.setupUI(tk_o)

    def setupUI(self, tk_o):
        self.tk_path = StringVar()
        self.stime_min = StringVar()
        self.stime_sec = StringVar()
        self.etime_min = StringVar()
        self.etime_sec = StringVar()
        self.root = tk_o
        
        self.frame = Frame(tk_o, width=512, height=512)
        self.lb_frame = Frame(self.frame)
        self.lb = Listbox(self.lb_frame)
        self.lb.bind('<<ListboxSelect>>', self.cursorSelect)
        
        self.popup_menu = Menu(self.lb_frame, tearoff=0)
        self.popup_menu.add_command(label='delete', command=self.delete)
        self.popup_menu.add_command(label='fuck off!', command=quit)
        
        self.input_path = Entry(self.frame, textvariable=self.tk_path)
        self.input_stime_min = Spinbox(self.frame, from_=0, to=59, textvariable=self.stime_min, **Style.SPINBOX)
        self.input_stime_sec = Spinbox(self.frame, from_=0, to=59, textvariable=self.stime_sec, **Style.SPINBOX)
        self.input_etime_min = Spinbox(self.frame, from_=0, to=59, textvariable=self.etime_min, **Style.SPINBOX)
        self.input_etime_sec = Spinbox(self.frame, from_=0, to=59, textvariable=self.etime_sec, **Style.SPINBOX)
        self.browse = Button(self.frame, text="Browse", command=self.fbrowse, **Style.BUT_ALIAS_2)
        self.addtolist_but = Button(self.frame, text="Add photo", command=self.update_map, **Style.BUT_ALIAS_1)
        self.load_but = Button(self.frame, text="Load photos", command=self.sender, **Style.BUT_ALIAS_1)

        self.frame.grid(column=3,row=0)
        self.lb_frame.grid(row=0,column=0, columnspan=5, sticky=W+E)
        self.input_path.grid(row=1,column=0, sticky=W+E)
        self.input_stime_min.grid(row=1,column=1)
        self.input_stime_sec.grid(row=1,column=2)
        self.input_etime_min.grid(row=1,column=3)
        self.input_etime_sec.grid(row=1,column=4)
        self.addtolist_but.grid(row=2, sticky=W+E, columnspan=2)
        self.load_but.grid(row=3, sticky=W+E, columnspan=2)
        self.browse.grid(row=1, column=5)
        self.lb.grid(columnspan=5, sticky=W+E)

    def save_video(self,path,stime,etime):
        self.videos.update({path: {stime, etime}})

    def update_map(self):
        self.save_video(self.tk_path,self.stime,self.etime)
        self.lb.insert(END,self.tk_path,self.stime,self.etime)
        self.input_path.delete(0,END)
        self.input_stime.delete(0,END)
        self.input_etime.delete(0,END)

    def sender(self):
        return None 
    def fbrowse(self):
        return None 
    def delete(self):
        return None 
    def cursorSelect(self, event):
        return None 