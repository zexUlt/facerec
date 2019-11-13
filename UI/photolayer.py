from mainlayer import MainLayer
from mainlayer import Style
from tkinter import *
from tkinter import filedialog
from shutil import copy2
  

class PhotoLayer(MainLayer): 
    def __init__(self, tk_o):
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
        self.addtolist_but = Button(self.frame, text="Add photo", command=self.update_list, **Style.BUT_ALIAS_1)
        self.load_but = Button(self.frame, text="Load photos", command=self.sender, **Style.BUT_ALIAS_1)

        self.frame.pack(fill=BOTH)
        self.lb_frame.pack(fill=BOTH)
        self.input_form.pack(side=LEFT)
        self.addtolist_but.pack(fill=BOTH)
        self.load_but.pack(fill=BOTH)
        self.browse.pack(side=RIGHT)
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
    
    def browse(self):
        self.root.filename = filedialog.askopenfilename(initialdir = "~/",title="Select file", filetypes=(("JPEG/JPG files","*.jpeg | *.jpg"),("PNG files", "*.png")))
        self.input_form.insert(0, self.root.filename)

    # --- Delete an item from photos[] and listbox
    def delete(self):
        item = self.lb.get(ANCHOR)
        self.photos.remove(item)
        self.lb.delete(ANCHOR)

    # --- Send photo to database 
    def sender(self): 
        for src in self.photos:
            copy2(src, "/home/zexult/facenet/database")