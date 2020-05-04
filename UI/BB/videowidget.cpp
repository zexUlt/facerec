#include "videowidget.h"
#include "ui_videowidget.h"

#include "videoframegrabber.h"
#include "mainwindow.h"

#include <QtWidgets>
#include <QGraphicsVideoItem>
#include <QVideoFrame>

int VideoWidget::ResID = 0;
QVector<VidContainer> VideoWidget::vidProps;

VideoWidget::VideoWidget(QWidget *parent, MainWindow* _m_window) :
    QWidget(parent),
    ui(new Ui::VideoWidget)
{
    ui->setupUi(this);

    QImage placeholder = QImage(":/rec/img/placeholders/video_placeholder_lighter_dark.png");
    placeholder = placeholder.scaledToWidth(ui->vidPreview->width(), Qt::SmoothTransformation);
    placeholder = placeholder.scaledToHeight(ui->vidPreview->height(), Qt::SmoothTransformation);
    ui->vidPreview->setPixmap(QPixmap::fromImage(placeholder));
    qDebug() << placeholder.width() << placeholder.height();

    ResID++;
    widgetID = ResID;

    m_window = std::move(_m_window);

    m_mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    VideoFrameGrabber* grabber = new VideoFrameGrabber(this);

    m_mediaPlayer->setMuted(true);
    m_mediaPlayer->setVideoOutput(grabber);

    connect(grabber, SIGNAL(frameAvailable(QImage)), this, SLOT(processFrame(QImage)));
}

void VideoWidget::processFrame(QImage img)
{
    img = img.scaledToWidth(this->ui->vidPreview->width(), Qt::SmoothTransformation);
    img = img.scaledToHeight(this->ui->vidPreview->height(), Qt::SmoothTransformation);
    this->ui->vidPreview->setPixmap(QPixmap::fromImage(img));
    qDebug() << img.width() << img.height();
}

int VideoWidget::getID()
{
    return this->widgetID;
}

bool VideoWidget::isPlayerAvailable() const
{
    return this->m_mediaPlayer->isAvailable();
}

void VideoWidget::on_openBtn_clicked()
{
    QFileDialog fileDialog(this);
    ApplySettings();
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));

    const QStringList supportedMimeTypes = m_mediaPlayer->supportedMimeTypes();

    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);

    fileDialog.setDirectory(this->pdbVideo);
    if (fileDialog.exec() == QDialog::Accepted){
        auto urlToVideo = fileDialog.selectedUrls().constFirst();
        load(urlToVideo);
    }
}

void VideoWidget::on_deleteBtn_clicked()
{
    auto wid = static_cast<VideoWidget*>(sender()->parent());

    delete wid;
}

void VideoWidget::load(const QUrl &url)
{
    auto cont = new VidContainer(url.toString().remove(0, 8));
    SendToStorage(*cont); // Sending video props packed into structure

    if(timesLoaded > 0){
        this->ui->vidPreview->clear();
    }

    this->timesLoaded++;
    m_mediaPlayer->setMedia(url);

    m_mediaPlayer->setPosition(15000); // Setting media playback to 5th sec
    m_mediaPlayer->play();
    m_mediaPlayer->pause();
}

void VideoWidget::SendToStorage(const VidContainer &cont)
{
    VideoWidget::vidProps.push_back(cont);
}

void inline VideoWidget::ApplySettings()
{
    this->pdbVideo = this->m_window->pdbVideo;
}

VideoWidget::~VideoWidget()
{
    delete ui;
}




