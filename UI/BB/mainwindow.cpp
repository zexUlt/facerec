#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLineEdit>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QScrollBar>

/** TODO:
 * *Main quests*
 * 1. Create flexible settings menu DONE
 * 1.1. Make flags(?) to choose file or directory DONE
 * 1.2. Apply settings to PhotoWidget and VideoWidget DONE
 * *Side quests*
 * 1. Make success/fail popups after video/photo upload
 * 2. Create progress bar for JSON packing
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), settings(new SettingsWindow(this))
{
    ui->setupUi(this);

    QFile styleSheetFile(":/rec/style/ScrollBar.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    ui->scrollArea->verticalScrollBar()->setStyleSheet(styleSheet);

    auto PhotoPlaceholder = QImage(":/rec/img/placeholders/photo_placeholder_lighter_dark.png");

    PhotoPlaceholder = PhotoPlaceholder.scaledToWidth(ui->imgPanel->width(), Qt::SmoothTransformation);
    PhotoPlaceholder = PhotoPlaceholder.scaledToHeight(ui->imgPanel->height(), Qt::SmoothTransformation);
    ui->imgPanel->setPixmap(QPixmap::fromImage(PhotoPlaceholder));

    vbox = new QVBoxLayout;

    ui->VideoPanel->setLayout(vbox);
    ApplySettingsConfig();
    connect(settings, &SettingsWindow::finished, this, &MainWindow::onSettingsClosed);
    connect(ui->scrollArea->verticalScrollBar(), &QScrollBar::rangeChanged, this, &MainWindow::SliderToMax);

    pLog = "eye.log";

    DebugConsole(this, pLog).log("Program started");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ApplySettingsConfig()
{
    QFile configFile = QFile(this->settings->configName);
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument configJson = QJsonDocument::fromJson(configFile.readAll());
    QJsonObject RootObject = configJson.object();
    this->pdbPhoto = RootObject.find("photoPathEntry").value().toString();
    this->pRoot = RootObject.find("rootPathEntry").value().toString();
    this->pPyProcess = RootObject.find("pyModulePathEntry").value().toString();
    this->pdbVideo = RootObject.find("videoPathEntry").value().toString();

}

void MainWindow::on_addImageBtn_clicked()
{

    QFileDialog dialog;
    dialog.setDirectory(this->pdbPhoto);
    QString filename = dialog.getOpenFileName(this, tr("Choose"), "", tr("*.png *.jpg *.jpeg *.bmp *.gif"));

    if(QString::compare(filename, QString()) != 0){
        QImage img;
        bool valid = img.load(filename);

        if(valid){
            this->ui->imgPanel->clear();
            this->pPhoto = filename;
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
    VideoWidget *wid = new VideoWidget(nullptr, this); // Creating new custom videowidget

    wid->show(); // Use this to show your widgets

    this->vbox->addWidget(wid); // Adding new widget to global layout
}

void MainWindow::SliderToMax()
{
    auto vertScrollBar = dynamic_cast<QScrollBar*>(ui->scrollArea->verticalScrollBar());
    vertScrollBar->setValue(vertScrollBar->maximum());
}

QString MainWindow::PackToJSON() const
{
    QJsonObject dataToSend, videoObj;
    dataToSend["photo"] = this->pPhoto;
    for(auto videoPath : ds.getVideoName()){
        videoObj.insert(videoPath, QJsonArray({0, 0}));
    }

    dataToSend["video"] = videoObj;
    dataToSend["out"] = ds.getOutputPath();

    QString saveFileName(this->pRoot + "/JsonTest.json");
    QFileInfo fileInfo(saveFileName);
    QDir::setCurrent(fileInfo.path());
    QFile jsonFile(saveFileName);
    if(!jsonFile.open(QIODevice::WriteOnly)){
        return QString();
    }

    jsonFile.write(QJsonDocument(dataToSend).toJson(QJsonDocument::Indented));
    return jsonFile.fileName();
}

void MainWindow::on_runButton_clicked() // Pack to JSON and send to python
{
    if(this->pPhoto.isEmpty() || ds.getVideoName().isEmpty()){
        QMessageBox::warning(this, tr("Not enough data!"), tr("Photo or at least one video is requiered."));
    } else {
        QString jsonPath = PackToJSON();
        if(QUrl(jsonPath).isValid()){
            ui->statusbar->showMessage("Data sent!", 10000);
        }
        ui->statusbar->showMessage("Running neural network...", 10000);
        QString pythonCall = "python " + this->pPyProcess + " " + jsonPath;

        system(pythonCall.toStdString().c_str());
    }
}

void MainWindow::on_actionSettings_triggered()
{
//    this->settings = new SettingsWindow(this);
    this->settings->exec();
}

void MainWindow::onSettingsClosed()
{
    ApplySettingsConfig();
}

void MainWindow::on_actionLog_triggered()
{
}
