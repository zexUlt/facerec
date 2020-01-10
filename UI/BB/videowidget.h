#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QDir>

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

    QSize sizeHint() const override;

public slots:
    void openFile();
    void play();

private slots:
    void processFrame(QImage img);
    void mediaStateChanged(QMediaPlayer::State state);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);
    void remove();

private:
    QMediaPlayer *m_mediaPlayer = nullptr;
    QGraphicsVideoItem *m_videoItem = nullptr;
    QAbstractButton *m_playButton = nullptr;
    QSlider *m_positionSlider = nullptr;
    int widgetID = 0;

};

#endif // VIDEOWIDGET_H
