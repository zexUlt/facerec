#pragma once

#include <QWidget>

class VideoFrameGrabber : public QAbstractVideoSurface
{
    Q_OBJECT
public:
    VideoFrameGrabber();
};

