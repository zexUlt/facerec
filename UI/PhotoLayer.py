import wx
from shutil import copy2
from UI.MainLayer import MainLayer as ML

class PhotoCtrl(wx.Panel):
    def __init__(self, parent):
        super(PhotoCtrl, self).__init__(parent=parent)

        self.PhotoMaxSize = 240

        self.createWidgets(parent)

    def createWidgets(self, parent):
        instructions = 'Browse for an image'
        img = wx.Image(240, 240)
        self.imageCtrl = wx.StaticBitmap(self, wx.ID_ANY,
                                         wx.Bitmap(img))

        instructLbl = wx.StaticText(self, label=instructions)
        self.photoTxt = wx.TextCtrl(self, size=(200, -1))
        browseBtn = wx.Button(self, label='Browse')
        browseBtn.Bind(wx.EVT_BUTTON, self.onBrowse)

        self.mainSizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer = wx.BoxSizer(wx.HORIZONTAL)

        self.mainSizer.Add(wx.StaticLine(self, wx.ID_ANY),
                           0, wx.ALL | wx.EXPAND, 5)
        self.mainSizer.Add(instructLbl, 0, wx.ALL, 5)
        self.mainSizer.Add(self.imageCtrl, 0, wx.ALL, 5)
        self.sizer.Add(self.photoTxt, 0, wx.ALL, 5)
        self.sizer.Add(browseBtn, 0, wx.ALL, 5)
        self.mainSizer.Add(self.sizer, 0, wx.ALL, 5)

        self.SetSizer(self.mainSizer)
        self.mainSizer.Fit(parent)

        self.Layout()

    def onBrowse(self, evt):
        wildcard = "PNG files (*.png)|*.png"
        dialog = wx.FileDialog(None, "Choose a file",
                               wildcard=wildcard,
                               style=wx.FD_OPEN)
        if dialog.ShowModal() == wx.ID_OK:
            self.photoTxt.SetValue(dialog.GetPath())
        dialog.Destroy()
        self.onView()

    def onView(self):
        filepath = self.photoTxt.GetValue()

        # Add filepath of the photo to local pathlist
        ML.photos.append(filepath)
        # Copy chosen photo to database
        copy2(filepath, "~/facenet/database/")

        img = wx.Image(filepath, wx.BITMAP_TYPE_ANY)

        W = img.GetWidth()
        H = img.GetHeight()
        if W > H:
            NewW = self.PhotoMaxSize
            NewH = self.PhotoMaxSize * H / W
        else:
            NewH = self.PhotoMaxSize
            NewW = self.PhotoMaxSize * H / W
        img = img.Scale(NewW, NewH)

        self.imageCtrl.SetBitmap(wx.Bitmap(img))
        self.Refresh()
