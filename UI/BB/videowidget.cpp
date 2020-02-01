#include "videowidget.h"
#include "videoframegrabber.h"

#include <QtWidgets>
#include <QGraphicsVideoItem>
#include <QVideoFrame>

int VideoWidget::ResID = 0;
std::vector<VidContainer> VideoWidget::vidProps;

VideoWidget::VideoWidget(QWidget *parent) :
    QWidget(parent)
{
    ResID++;
    widgetID = ResID;

    m_mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    VideoFrameGrabber* grabber = new VideoFrameGrabber(this);

//    start = new QTimeEdit(this);
//    end = new QTimeEdit(this);

    vidPreview = new QLabel;
    vidPreview->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    vidPreview->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    QAbstractButton* openButton = new QPushButton(tr("Open..."));
    connect(openButton, &QAbstractButton::clicked, this, &VideoWidget::openFile);

    QAbstractButton* deleteButton = new QPushButton(tr("Delete"));
    connect(deleteButton, &QAbstractButton::clicked, this, &VideoWidget::remove);

    m_mediaPlayer->setMuted(true); // Mute player

    m_mediaPlayer->setVideoOutput(grabber);

    connect(grabber, SIGNAL(frameAvailable(QImage)), this, SLOT(processFrame(QImage)));

    QBoxLayout* controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(deleteButton);
    controlLayout->addWidget(start);

    QBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(vidPreview);
    layout->addLayout(controlLayout);
}

void VideoWidget::processFrame(QImage img)
{
    qDebug() << "lol";

    vidPreview->setMinimumSize(img.width(), img.height());
    vidPreview->setMaximumSize(img.width(), img.height());
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

bool VideoWidget::isPlayerAvailable() const
{
    return m_mediaPlayer->isAvailable();
}

void VideoWidget::openFile()
{
    if(timesLoaded > 0){
        vidPreview->clear();
    }

    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    const QStringList supportedMimeTypes = m_mediaPlayer->supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted){
        auto path = fileDialog.selectedUrls().constFirst();
        load(path);
    }
}

void VideoWidget::load(const QUrl &url)
{
    auto cont = new VidContainer(url.fileName());
    SendToStorage(*cont); // Sending video props packed into structure

    this->timesLoaded++;
    m_mediaPlayer->setMedia(url);

    m_mediaPlayer->setPosition(5000); // Setting media playback to 5th sec
    m_mediaPlayer->play();
    m_mediaPlayer->pause();
}

void VideoWidget::remove()
{
    auto wid = static_cast<VideoWidget*>(sender()->parent());

    delete wid;
}

void VideoWidget::SendToStorage(const VidContainer &cont)
{
    VideoWidget::vidProps.push_back(cont);
}
