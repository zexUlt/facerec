#include "mainwindow.h"

#include <QApplication>
#include <windows.h>

int main(int argc, char *argv[])
{
//#ifdef Q_OS_WIN32
//    if (AttachConsole(ATTACH_PARENT_PROCESS) || AllocConsole()) {
//        FILE *out = stdout;
//        FILE *err = stderr;

//        freopen_s(&out, "CONOUT$", "w", stdout);
//        freopen_s(&err, "CONOUT$", "w", stderr);
//    }
//#endif
    QApplication a(argc, argv);
    MainWindow w(nullptr);
    w.show();
    return a.exec();
}
