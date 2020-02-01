#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "videowidget.h"
#include "vidcontainer.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    friend class VideoWidget;
    Q_OBJECT
    std::vector<QPixmap> images;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addImageBtn_clicked();
    void on_addVidBtn_clicked();

    void on_runButton_clicked();

private:
    QUrl PackToJSON();
//    QJsonArray QVectorToJSON(QVector<VidContainer>);

    Ui::MainWindow *ui;
    QVBoxLayout* vbox;
    QString photo;
};
#endif // MAINWINDOW_H
