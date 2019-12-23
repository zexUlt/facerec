import wx
from UI.PhotoLayer import PhotoCtrl
from UI.VideoLayer import VideoCtrl


class MyApp(wx.App):
    def __init__(self):
        super().__init__(clearSigInt=True)

        self.InitMainFrame()

    @staticmethod
    def InitMainFrame():
        frame = MainFrame(parent=None, title="MainFrame", pos=(100, 200))
        frame.Show()


class MainFrame(wx.Frame):
    def __init__(self, parent, title, pos):
        super(MainFrame, self).__init__(parent=parent, title=title, pos=pos)
        self.onInit()

    def onInit(self):
        self.vbox = wx.BoxSizer(wx.VERTICAL)
        Ppanel = PhotoCtrl(self)
        Vpanel = VideoCtrl(self)
        self.vbox.Add(Ppanel, flag=wx.EXPAND | wx.ALL)
        self.vbox.Add(Vpanel, flag=wx.EXPAND | wx.ALL)

        self.vbox.Show(self, show=True, recursive=True)
        self.vbox.Layout()
        self.vbox.Fit(self)


if __name__ == '__main__':
    app = MyApp()
    app.MainLoop()
