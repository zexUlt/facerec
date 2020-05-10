#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "popup.h"

#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>


SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsWindow)
{
    ui->setupUi(this);

//    qDebug() << this->ui->layoutWidget->children();

    popup = new PopUp(this);

    QDir rootDirectory = QDir::currentPath();
    DebugConsole(this, "eye.log").log("Current root is: [" + rootDirectory.absolutePath() + "]");

    bool isFound = false;
    for(auto file : rootDirectory.entryList()){
        if(file.contains("config")){
            isFound = true;
            configName = file;
        }
    }

    if(!isFound){
        this->setConfigDefaults();
    }

    LoadSettings();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

QString SettingsWindow::getPath(const QString& currentPath, bool isFile)
{
    QFileDialog dialog;
    QString dirPath;

    DebugConsole(this, "eye.log").log("Current path is: [" + currentPath + "]");

    if(currentPath.contains(".")){
        int posDelim;
        if(currentPath.contains('\\')){
            posDelim = currentPath.lastIndexOf('\\');
        } else {
            posDelim = currentPath.lastIndexOf('/');
        }
        dirPath = currentPath.chopped(currentPath.size() - posDelim);
    } else {
        dirPath = currentPath;
    }

    if(QDir(dirPath).exists()){
        dialog.setDirectory(dirPath);
    } else {
       QMessageBox::warning(this, tr("Directory doesn't exists"), tr("There is no such directory on this path"));

    }
    QFileDialog::FileMode fm = isFile ? QFileDialog::FileMode::AnyFile : QFileDialog::Directory;
    dialog.setFileMode(fm);
    dialog.setOption(QFileDialog::ShowDirsOnly, false);
    dialog.exec();
    return isFile ? dialog.selectedFiles()[0] : dialog.directory().path();
}

void SettingsWindow::on_browseRootBtn_clicked()
{

   QString path = getPath(ui->rootPathEntry->text(), false);
   DebugConsole(this, "eye.log").log("Root path changed from: [" + ui->rootPathEntry->text() + "] To: [" + path + "]");
   ui->rootPathEntry->setText(path);

}

void SettingsWindow::on_browsePhotoBtn_clicked()
{
    QString path = getPath(ui->photoPathEntry->text(), false);
    DebugConsole(this, "eye.log").log("Photo path changed from: [" + ui->photoPathEntry->text() + "] To: [" + path + "]");
    ui->photoPathEntry->setText(path);
}

void SettingsWindow::on_browseVideoBtn_clicked()
{
    QString path = getPath(ui->videoPathEntry->text(), false);
    DebugConsole(this, "eye.log").log("Video path changed from: [" + ui->videoPathEntry->text() + "] To: [" + path + "]");
    ui->videoPathEntry->setText(path);
}

void SettingsWindow::on_browsePyBtn_clicked()
{
    QString path = getPath(ui->pyModulePathEntry->text(), true);
    DebugConsole(this, "eye.log").log("Py path changed from: [" + ui->pyModulePathEntry->text() + "] To: [" + path + "]");
    ui->pyModulePathEntry->setText(path);
}

void SettingsWindow::on_browseOutBtn_clicked()
{
    QString path = getPath(ui->outFolderPathEntry->text(), false);
    ds.setOutputPath(path);
    DebugConsole(this, "eye.log").log("Output path changed from: [" + ui->outFolderPathEntry->text() + "] To: [" + path + "]");
    ui->outFolderPathEntry->setText(path);
}

void SettingsWindow::setConfigDefaults()
{
    QJsonObject config;
    QString rootPath(QDir::currentPath());
    QString photoPath = rootPath + "/database";
    QString videoPath = rootPath + "/videodatabase";

    config[ui->rootPathEntry->objectName()] = rootPath;
    config[ui->photoPathEntry->objectName()] = photoPath;
    config[ui->videoPathEntry->objectName()] = videoPath;

    QString saveCfgName(rootPath + "/config.json");
    QFileInfo CfgInfo(saveCfgName);
    QDir::setCurrent(CfgInfo.path());
    QFile jsonCfg(saveCfgName);
    if(!jsonCfg.open(QIODevice::WriteOnly)){
        this->configName = QString();
    }

    jsonCfg.write(QJsonDocument(config).toJson(QJsonDocument::Indented));
    this->configName = jsonCfg.fileName();
}

void SettingsWindow::UpdateConfig(const QList< QPair<QString, QString> >& param)
{
    QFile configFile;
    configFile.setFileName(this->configName);
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);

    DebugConsole(this, "eye.log").log("Config content");
    DebugConsole(this, "eye.log").log("Config content: " + configFile.readAll() + "]");
    QJsonParseError JsonParseError;
    QJsonDocument jsonCfg = QJsonDocument::fromJson(configFile.readAll(), &JsonParseError);
//    qDebug() << "Json READ ~~~ " << jsonCfg;
    configFile.close();

    configFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    QJsonObject RootObject = jsonCfg.object();
    for(auto obj : param){
        RootObject.remove(obj.first);
        RootObject.insert(obj.first, obj.second);
    }
    jsonCfg.setObject(RootObject);
//    qDebug() << "Json WRITE ~~~ " << jsonCfg;
    configFile.write(jsonCfg.toJson(QJsonDocument::Indented));
    configFile.close();
}

void SettingsWindow::LoadSettings()
{
    QFile config = QFile(this->configName);
    DebugConsole(this, "eye.log").log("Configuration file: [" + configName + "]");
    config.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = config.readAll();
    QJsonDocument jsonCfg = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject cfgObject = jsonCfg.object();
    ui->rootPathEntry->setText(cfgObject["rootPathEntry"].toString());
    ui->photoPathEntry->setText(cfgObject["photoPathEntry"].toString());
    ui->videoPathEntry->setText(cfgObject["videoPathEntry"].toString());
    ui->pyModulePathEntry->setText(cfgObject["pyModulePathEntry"].toString());
}



void SettingsWindow::on_SaveBtn_clicked()
{

    auto childrenList = this->findChildren<QLineEdit*>();
    QList< QPair<QString, QString> > paramsToUpdate;
    for(auto child : childrenList){
        DebugConsole(this, "eye.log").log("Param: [" + child->objectName() + "] Value: [" + child->text() + "]");
        paramsToUpdate.append(QPair<QString, QString>(child->objectName(), child->text()));
    }

    this->UpdateConfig(paramsToUpdate);
//    for(auto obj : this->ui->layoutWidget->children()){
//        auto target = qobject_cast<QLineEdit*>(obj);
//        qDebug() << obj;
//        if(target != nullptr){
//            DebugConsole(this, "eye.log").log("Target found.");
//            this->UpdateConfig(target->objectName(), target->text());
//        }
//    }

    DebugConsole(this, "eye.log").log("Settings saved");

    this->popup->setPopupText("Saved!");
    popup->show();
}

