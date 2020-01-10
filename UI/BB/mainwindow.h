#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "videowidget.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    std::vector<QPixmap> images;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addImageBtn_clicked();
    void on_addVidBtn_clicked();

private:
    Ui::MainWindow *ui;
    QVBoxLayout* vbox;
    QVector<QString> photos;
    QVector<QString> videos;

};
#endif // MAINWINDOW_H
