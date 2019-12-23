import wx
import wx.lib.scrolledpanel as scrolled


class VideoCtrl(wx.Panel):
    def __init__(self, parent):
        super(VideoCtrl, self).__init__(parent=parent)

        self.VideoPreviewMaxSize = 120


class VideoItem(wx.Panel):
    def __init__(self, parent):
        super(VideoItem, self).__init__(parent=parent)

        self.CreateWidgets(parent)

    def CreateWidgets(self, parent):
        TopPanel = scrolled.ScrolledPanel(self)
        PromptButton = wx.Button(self, label="Prompt")
        browseButton = wx.Button(self, label="Browse")
        self.vbox = wx.BoxSizer(wx.VERTICAL)
        


    def CreateItem(self):
        pass
