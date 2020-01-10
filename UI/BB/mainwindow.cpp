#include "mainwindow.h"
#include "ui_mainwindow.h"

/** TODO:
 * 1. Проверить правильность удаления виджета.
 * 2. Сделать превью видео вместо самого видео.
 * 2.1. Разобраться с граббером
 * 3. Создать хранилище для путей фото и видео.
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    vbox = new QVBoxLayout;

    ui->VideoPanel->setLayout(vbox);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addImageBtn_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("*.png *.jpg *.jpeg *.bmp *.gif"));

    if(QString::compare(filename, QString()) != 0){
        QImage img;
        bool valid = img.load(filename);

        if(valid){
            img = img.scaledToWidth(ui->imgPanel->width(), Qt::SmoothTransformation);
            img = img.scaledToHeight(ui->imgPanel->height(), Qt::SmoothTransformation);
            ui->imgPanel->setPixmap(QPixmap::fromImage(img));
        } else {
            QMessageBox::warning(this, "Warning", "Cannot upload file");
        }
    }
}

void MainWindow::on_addVidBtn_clicked()
{
    VideoWidget *wid = new VideoWidget; // Creating new custom videowidget


    wid->show(); // Use this to show your widgets

    this->vbox->addWidget(wid); // Adding new widget to global layout
    qDebug() << wid->parent()->property("whatsThis");
}
