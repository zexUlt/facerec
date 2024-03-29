#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include "datastorage.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QDir>
#include <QBoxLayout>
#include <QLabel>
#include <QTimeEdit>

class QAbstractButton;
class QSlider;
class QGraphicsVideoItem;
class MainWindow;

namespace Ui {
class VideoWidget;
}

class VideoWidget : public QWidget
{
    friend class MainWindow;
    Q_OBJECT

public:
    explicit VideoWidget(QWidget *parent = nullptr, MainWindow* _m_window = nullptr);
    ~VideoWidget();

    static int ResID;

    int getID();

    void load(const QUrl& url);
    bool isPlayerAvailable() const;

private slots:
    void processFrame(QImage img);

    void on_openBtn_clicked();

    void on_deleteBtn_clicked();

private:
    void SendToStorage(const DataStorage& cont);
    void ApplySettings();

    /* Default paths BEGIN */
    QString pdbVideo;
    /* Default paths END */

    // Path to video in "this" widget
    QString pVideo;

    DataStorage ds;
    MainWindow* m_window;
    QMediaPlayer *m_mediaPlayer = nullptr;
    QGraphicsVideoItem *m_videoItem = nullptr;
    int widgetID = 0;
    int timesLoaded = 0;
    Ui::VideoWidget *ui;
};

#endif // VIDEOWIDGET_H
