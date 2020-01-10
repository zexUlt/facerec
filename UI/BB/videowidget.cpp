#include "videowidget.h"
#include "videoframegrabber.h"

#include <QtWidgets>
#include <QGraphicsVideoItem>
#include <QVideoFrame>

int VideoWidget::ResID = 0;

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent)
{
    ResID++;
    widgetID = ResID;

    m_mediaPlayer = new QMediaPlayer(this);
    VideoFrameGrabber* grabber = new VideoFrameGrabber(this);
//    const QRect screenGeometry = QApplication::desktop()->screenGeometry(this);
//    m_videoItem = new QGraphicsVideoItem;
//    m_videoItem->setSize(QSizeF(screenGeometry.width() / 3, screenGeometry.height() / 2));

//    QGraphicsScene* scene = new QGraphicsScene(this);
//    QGraphicsView* graphicsView = new QGraphicsView(scene);

//    scene->addItem(m_videoItem);

    QAbstractButton* openButton = new QPushButton(tr("Open..."));
    connect(openButton, &QAbstractButton::clicked, this, &VideoWidget::openFile);

    QAbstractButton* deleteButton = new QPushButton(tr("Delete"));
    connect(deleteButton, &QAbstractButton::clicked, this, &VideoWidget::remove);

    m_mediaPlayer->setMuted(true); // Mute player

    m_mediaPlayer->play();
    m_mediaPlayer->setPosition(5000); // Setting media playback to 5th sec
    m_mediaPlayer->pause();

    m_mediaPlayer->setVideoOutput(grabber);

    connect(grabber, SIGNAL(frameAvailable(QImage)), this, SLOT(processFrame(QImage)));

    m_playButton = new QPushButton;
    m_playButton->setEnabled(false);
    m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

//    connect(m_playButton, &QAbstractButton::clicked, this, &VideoWidget::play);

    m_positionSlider = new QSlider(Qt::Horizontal);
    m_positionSlider->setRange(0, 0);

//    connect(m_positionSlider, &QAbstractSlider::sliderMoved,
//            this, &VideoWidget::setPosition);

    QBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(deleteButton);
    controlLayout->addWidget(m_playButton);
    controlLayout->addWidget(m_positionSlider);

    QBoxLayout* layout = new QVBoxLayout(this);
//    layout->addWidget(graphicsView);
//    layout->addWidget(vidPreview);
    layout->addLayout(controlLayout);

    m_mediaPlayer->stop();

//    connect(m_mediaPlayer, &QMediaPlayer::stateChanged,
//            this, &VideoWidget::mediaStateChanged);
//    connect(m_mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoWidget::durationChanged);
//    connect(m_mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoWidget::positionChanged);
}

void VideoWidget::processFrame(QImage img)
{
    QLabel* vidPreview = new QLabel;

    vidPreview->setPixmap(QPixmap::fromImage(img));

}

VideoWidget::~VideoWidget()
{
    for(auto child : this->children())
        delete child;
}

int VideoWidget::getID()
{
    return this->widgetID;
}

QSize VideoWidget::sizeHint() const
{
    return (m_videoItem->size() * qreal(3) / qreal(2)).toSize();
}

bool VideoWidget::isPlayerAvailable() const
{
    return m_mediaPlayer->isAvailable();
}

void VideoWidget::openFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    const QStringList supportedMimeTypes = m_mediaPlayer->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted)
        load(fileDialog.selectedUrls().constFirst());
}

void VideoWidget::load(const QUrl &url)
{
    m_mediaPlayer->setMedia(url);
    m_playButton->setEnabled(true);
}

void VideoWidget::play()
{
    switch (m_mediaPlayer->state()) {
    case QMediaPlayer::PlayingState:
        m_mediaPlayer->pause();
        break;
    default:
        m_mediaPlayer->play();
        break;
    }
}

void VideoWidget::mediaStateChanged(QMediaPlayer::State state)
{
    switch(state) {
    case QMediaPlayer::PlayingState:
        m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        m_playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void VideoWidget::positionChanged(qint64 position)
{
    m_positionSlider->setValue(position);
}

void VideoWidget::durationChanged(qint64 duration)
{
    m_positionSlider->setRange(0, duration);
}

void VideoWidget::setPosition(int pos)
{
    m_mediaPlayer->setPosition(pos);
}

void VideoWidget::remove()
{
    auto wid = static_cast<VideoWidget*>(sender()->parent());

    delete wid;
}
