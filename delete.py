from tkinter import *

master = Tk()

listbox = Listbox(master)
listbox.pack()

listbox.insert(END, "a list entry")

for item in ["one", "two", "three", "four"]:
    listbox.insert(END, item)

b = Button(master, text="Delete", command=lambda listbox=listbox: listbox.delete(ANCHOR))
b.pack()
mainloop()
