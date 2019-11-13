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
        self.root = tk_o
        
        self.frame = Frame(tk_o, width=512, height=512)
        self.lb_frame = Frame(self.frame)
        self.lb = Listbox(self.lb_frame)
        self.lb.bind('<<ListboxSelect>>', self.cursorSelect)
        
        self.popup_menu = Menu(self.lb_frame, tearoff=0)
        self.popup_menu.add_command(label='delete', command=self.delete)
        self.popup_menu.add_command(label='fuck off!', command=quit)
        
        self.input_form = Entry(self.frame, textvariable=self.tk_path)
        self.browse = Button(self.frame, text="Browse", command=self.browse, **Style.BUT_ALIAS_2)
        self.addtolist_but = Button(self.frame, text="Add photo", command=self.update_map, **Style.BUT_ALIAS_1)
        self.load_but = Button(self.frame, text="Load photos", command=self.sender, **Style.BUT_ALIAS_1)

        self.frame.grid(column=3,row=0)
        self.lb_frame.grid(row=0,column=0, columnspan=2, sticky=W+E)
        self.input_form.grid(row=1, sticky=W+E)
        self.addtolist_but.grid(row=2, sticky=W+E, columnspan=2)
        self.load_but.grid(row=3, sticky=W+E, columnspan=2)
        self.browse.grid(row=1, column=1)
        self.lb.grid(columnspan=2, sticky=W+E)

    def save_video(self,path,stime,etime):
        self.videos.update({path: {stime, etime}})

    def update_map(self):
        return None    
    def sender(self):
        return None 
    def browse(self):
        return None 
    def delete(self):
        return None 
    def cursorSelect(self, event):
        return None 