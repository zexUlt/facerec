#ifndef GALLERY_H
#define GALLERY_H

#include "datastorage.h"

#include <QDialog>
#include <QString>
#include <QImage>

class QTimer;

namespace Ui {
class Gallery;
}

class Gallery : public QDialog
{
    Q_OBJECT

public:
    explicit Gallery(QWidget *parent = nullptr);
    ~Gallery();

public slots:
    void updateImageList();

private slots:
    void on_PrevBtn_clicked();

    void on_NextBtn_clicked();

private:

    QTimer* timer;
    DataStorage ds;
    int currentImage;
    QString targetDirectory;
    QVector<QString> images;
    Ui::Gallery *ui;
};

#endif // GALLERY_H
