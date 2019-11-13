from mainlayer import MainLayer
from tkinter import *


class PhotoLayer(MainLayer): 
	def __init__(self, tk_o):
		self.tk_path = StringVar()
		
		self.frame = Frame(tk_o)
		self.lb_frame = Frame(self.frame)
		self.lb = Listbox(self.lb_frame)

		self.p_input = Entry(self.frame, textvariable=self.tk_path)
		self.p_send = Button(self.frame, text="submit", command=lambda: self.update_list())

		self.frame.pack(side=LEFT)
		self.lb_frame.pack()
		self.lb.pack()
		self.p_input.pack(side=LEFT)
		self.p_send.pack(side=RIGHT)
		MainLayer.__init__(self)
	
	def save_path(self, path):
		self.photos.append(path)
	# --- Send photo to database 
	# def sender(self): 
		
	def update_list(self):
		self.save_path(self.tk_path.get())
		for path in self.photos:
			self.lb.insert(END, path)
	
	# def show_list(self):
	#     for i in photos:
