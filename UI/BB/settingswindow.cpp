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

    popup = new PopUp(this);

    QDir rootDirectory = QDir::currentPath();

    bool isFound = false;
    for(auto file : rootDirectory.entryList()){
        if(file.contains("config")){
            isFound = true;
            this->configName = file;
        }
    }

    if(!isFound){
        this->setConfigDefaults();
    }

    this->LoadSettings();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

QString SettingsWindow::getPath(const QString& currentPath, bool isFile)
{
    QFileDialog dialog;
    QString dirPath;

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
   ui->rootPathEntry->setText(path);
//   this->UpdateConfig(ui->rootPathEntry->objectName(), path);
}

void SettingsWindow::on_browsePhotoBtn_clicked()
{
    QString path = getPath(ui->photoPathEntry->text(), false);
    ui->photoPathEntry->setText(path);
//    this->UpdateConfig(ui->photoPathEntry->objectName(), path);
}

void SettingsWindow::on_browseVideoBtn_clicked()
{
    QString path = getPath(ui->videoPathEntry->text(), false);
    ui->videoPathEntry->setText(path);
//    this->UpdateConfig(ui->videoPathEntry->objectName(), path);
}

void SettingsWindow::on_browsePyBtn_clicked()
{
    QString path = getPath(ui->pyModulePathEntry->text(), true);
    ui->pyModulePathEntry->setText(path);
//    this->UpdateConfig(ui->pyModulePathEntry->objectName(), path);
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

void SettingsWindow::UpdateConfig(const QString& param, const QString& value)
{
    QFile configFile;
    configFile.setFileName(this->configName);
    configFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonParseError JsonParseError;
    QJsonDocument jsonCfg = QJsonDocument::fromJson(configFile.readAll(), &JsonParseError);
    configFile.close();

    configFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    QJsonObject RootObject = jsonCfg.object();
    RootObject.remove(param);
    RootObject.insert(param, value);
    jsonCfg.setObject(RootObject);
    configFile.write(jsonCfg.toJson(QJsonDocument::Indented));
    configFile.close();
}

void SettingsWindow::LoadSettings()
{
    QFile config = QFile(this->configName);
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
    for(auto obj : this->children()){
        auto target = dynamic_cast<QLineEdit*>(obj);
        if(target != NULL){
            this->UpdateConfig(target->objectName(), target->text());
        }
    }

    this->popup->setPopupText("Saved!");
    popup->show();
}
