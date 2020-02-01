#include "mainwindow.h"
#include "ui_mainwindow.h"

/** TODO:
 * *Main quests*
 * 1. Pack data to JSON
 * 2. Send path to JSON file to python script and run
 * *Side quests*
 * 1. Make success/fail popups after video/photo upload
 * 2. Create progress bar for JSON packing
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
            this->photo = filename;
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
}

QUrl MainWindow::PackToJSON()
{
    QJsonObject dataToSend, videoObj;
    dataToSend["photo"] = this->photo;
    for(auto x : VideoWidget::vidProps){
        videoObj.insert(x.videoName, QJsonArray({0, 0}));
    }

    dataToSend["video"] = videoObj;

    QString saveFileName("/home/zexult/Documents/JsonTest.json");
    QFileInfo fileInfo(saveFileName);
    QDir::setCurrent(fileInfo.path());
    QFile jsonFile(saveFileName);
    if(!jsonFile.open(QIODevice::WriteOnly)){
        return QUrl();
    }

    jsonFile.write(QJsonDocument(dataToSend).toJson(QJsonDocument::Indented));
    return jsonFile.fileName();
}

//QJsonArray MainWindow::QVectorToJSON(QVector<VidContainer> vect)
//{
//    QJsonArray jsonArray;
//    std::copy(vect.begin(), vect.end(), std::back_inserter(jsonArray));

//    return jsonArray;
//}

void MainWindow::on_runButton_clicked() // Pack to JSON and send to python
{
    PackToJSON();
    ui->statusbar->showMessage("Running neural network...", 10000);
    // sending to python will be here
}
