#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "videowidget.h"
#include "datastorage.h"
#include "settingswindow.h"
#include "debugconsole.h"

#include <QObject>
#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSlider;
class QFileDialog;
class QPushButton;
class QVBoxLayout;
class QMessageBox;
class QJsonObject;
class QJsonArray;
class QJsonDocument;
class QJsonValue;
class QLineEdit;
class QScrollBar;

class MainWindow : public QMainWindow
{
    friend class VideoWidget;
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addImageBtn_clicked();
    void on_addVidBtn_clicked();

    void on_runButton_clicked();

    void on_actionSettings_triggered();

    void on_actionLog_triggered();

private:
    QString PackToJSON() const;
    void ApplySettingsConfig();
    void onSettingsClosed();
    void SliderToMax();

/** Defaults Paths BEGIN **/
    QString pdbPhoto;
    QString pdbVideo;
    QString pRoot;
    QString pPyProcess;
    QString pLog;
/** Defaults Paths END **/

    DataStorage ds;
    QVector<QPixmap> images;
    Ui::MainWindow *ui;
    QVBoxLayout* vbox;
    QString pPhoto;

    SettingsWindow* settings;
};
#endif // MAINWINDOW_H
