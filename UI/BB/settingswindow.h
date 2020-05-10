#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "debugconsole.h"
#include "datastorage.h"

#include <QDialog>


namespace Ui {
class SettingsWindow;
}

class QFileDialog;
class QJsonObject;
class QJsonDocument;
class QMessageBox;
class PopUp;

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    QString configName;

private slots:
    void on_browseRootBtn_clicked();

    void on_browsePhotoBtn_clicked();

    void on_browseVideoBtn_clicked();

    void on_browsePyBtn_clicked();

    void on_SaveBtn_clicked();

    void on_browseOutBtn_clicked();

private:

    DataStorage ds;
    QString getPath(const QString&, bool);
    void setConfigDefaults();
    void UpdateConfig(const QList< QPair<QString, QString> >&);
    void LoadSettings();

    Ui::SettingsWindow *ui;
    PopUp* popup;
};

#endif // SETTINGSWINDOW_H
