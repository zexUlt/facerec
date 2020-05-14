#include "gallery.h"
#include "ui_gallery.h"

#include <QStringList>
#include <QDir>
#include <QTimer>
#include <QTime>
#include <QFileInfo>

#include <QDebug>

Gallery::Gallery(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Gallery)
{
    ui->setupUi(this);

    currentImage = -1;
    targetDirectory = ds.getOutputPath();

    auto timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Gallery::updateImageList);
    connect(this, &QDialog::finished, timer, &QTimer::stop);
    timer->start(1000);

    QDir dir(targetDirectory);
    for(auto entry : dir.entryList()){
        if(!entry.startsWith(".") && !this->images.contains(this->targetDirectory + R"(\)" + entry)){
            this->images.append(this->targetDirectory + R"(\)" + entry);
        }

        if(this->images.size() == 1){
            this->currentImage = 0;
            QString imageNameRaw = QFileInfo(this->images[currentImage]).fileName();
            imageNameRaw = imageNameRaw.remove(".jpg");
            QString imageName = imageNameRaw.replace("_", " ");
            imageName = imageName.toUpper();

            this->ui->label->setPixmap(QPixmap::fromImage(QImage(images[currentImage])));
        }

        if(this->images.size() > 1){
            this->ui->NextBtn->setEnabled(true);
        }
    }
    this->show();
}

Gallery::~Gallery()
{
    delete ui;
}

void Gallery::updateImageList()
{
    QDir dir(targetDirectory);
    for(auto entry : dir.entryList()){
        if(!entry.startsWith(".") && !this->images.contains(this->targetDirectory + R"(\)" + entry)){
            this->images.append(this->targetDirectory + R"(\)" + entry);
        }

        if(this->images.size() == 1){
            this->currentImage = 0;
            QString imageNameRaw = QFileInfo(this->images[currentImage]).fileName();
            imageNameRaw = imageNameRaw.remove(".jpg");
            QString imageName = imageNameRaw.replace("_", " ");
            imageName = imageName.toUpper();

            this->ui->label_2->setText(imageName);
            QImage img = QImage(this->images[currentImage]);

            img = img.scaledToWidth(this->ui->label->width(), Qt::SmoothTransformation);
            img = img.scaledToHeight(this->ui->label->height(), Qt::SmoothTransformation);
            this->ui->label->setPixmap(QPixmap::fromImage(img));
        }
    }

    if(this->images.size() > 1 && currentImage != this->images.size() - 1){
        this->ui->NextBtn->setEnabled(true);
    }
}

void Gallery::on_PrevBtn_clicked()
{
    currentImage--;
    if(currentImage == 0){
        this->ui->PrevBtn->setEnabled(false);
    }else{
        this->ui->PrevBtn->setEnabled(true);
    }

    if(currentImage < this->images.size() - 1){
        this->ui->NextBtn->setEnabled(true);
    }

    QString imageNameRaw = QFileInfo(this->images[currentImage]).fileName();
    imageNameRaw = imageNameRaw.remove(".jpg");
    QString imageName = imageNameRaw.replace("_", " ");
    imageName = imageName.toUpper();
    this->ui->label_2->setText(imageName);

    QImage img = QImage(this->images[currentImage]);

    img = img.scaledToWidth(this->ui->label->width(), Qt::SmoothTransformation);
    img = img.scaledToHeight(this->ui->label->height(), Qt::SmoothTransformation);

    this->ui->label->clear();
    this->ui->label->setPixmap(QPixmap::fromImage(img));
}

void Gallery::on_NextBtn_clicked()
{
    currentImage++;
    if(this->currentImage == this->images.size() - 1){
        this->ui->NextBtn->setEnabled(false);
    } else {
        this->ui->NextBtn->setEnabled(true);
    }

    if(currentImage > 0){
        this->ui->PrevBtn->setEnabled(true);
    }

    QString imageNameRaw = QFileInfo(this->images[currentImage]).fileName();
    imageNameRaw = imageNameRaw.remove(".jpg");
    QString imageName = imageNameRaw.replace("_", " ");
    imageName = imageName.toUpper();
    this->ui->label_2->setText(imageName);

    QImage img = QImage(this->images[currentImage]);

    img = img.scaledToWidth(this->ui->label->width(), Qt::SmoothTransformation);
    img = img.scaledToHeight(this->ui->label->height(), Qt::SmoothTransformation);

    this->ui->label->clear();
    this->ui->label->setPixmap(QPixmap::fromImage(QImage(img)));
}
