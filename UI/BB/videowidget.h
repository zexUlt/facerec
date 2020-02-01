#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "vidcontainer.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QDir>
#include <QBoxLayout>
#include <QLabel>
#include <QTimeEdit>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
class QAbstractButton;
class QSlider;
class QGraphicsVideoItem;
QT_END_NAMESPACE

class VideoWidget : public QWidget
{
    friend class MainWindow;
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);
    ~VideoWidget();
    static int ResID;

    int getID();

    void load(const QUrl &url);
    bool isPlayerAvailable() const;

public slots:
    void openFile();

private slots:
    void processFrame(QImage img);
    void remove();

private:
    void SendToStorage(const VidContainer& cont);

    QLabel* vidPreview = nullptr;
    QMediaPlayer *m_mediaPlayer = nullptr;
    QGraphicsVideoItem *m_videoItem = nullptr;
    QTimeEdit *start, *end;
    int widgetID = 0;
    int timesLoaded = 0;
    static std::vector<VidContainer> vidProps;
};

#endif // VIDEOWIDGET_H
