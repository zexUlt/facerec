/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionSettings;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QWidget *VideoPanel;
    QSpacerItem *verticalSpacer_3;
    QLabel *imgPanel;
    QPushButton *addVidBtn;
    QSpacerItem *verticalSpacer_2;
    QPushButton *runButton;
    QPushButton *addImageBtn;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuTools;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 490);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 490));
        MainWindow->setMaximumSize(QSize(1000, 490));
        MainWindow->setBaseSize(QSize(944, 427));
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("* {\n"
"	font:  \"Franklin Gothic Demi\";\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"\n"
"QMainWindow {\n"
"	background-color: #222\n"
"}"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(530, 330));
        scrollArea->setBaseSize(QSize(483, 320));
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea{background-color: #f00;}\n"
""));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 528, 391));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("QWidget{ background-color:#222;}"));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        VideoPanel = new QWidget(scrollAreaWidgetContents);
        VideoPanel->setObjectName(QString::fromUtf8("VideoPanel"));
        VideoPanel->setMinimumSize(QSize(0, 0));
        VideoPanel->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(VideoPanel);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 2, 2, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 1, 3, 1);

        imgPanel = new QLabel(centralwidget);
        imgPanel->setObjectName(QString::fromUtf8("imgPanel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(imgPanel->sizePolicy().hasHeightForWidth());
        imgPanel->setSizePolicy(sizePolicy2);
        imgPanel->setMinimumSize(QSize(320, 360));
        imgPanel->setMaximumSize(QSize(320, 360));
        imgPanel->setBaseSize(QSize(320, 320));
        imgPanel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(imgPanel, 0, 0, 2, 1);

        addVidBtn = new QPushButton(centralwidget);
        addVidBtn->setObjectName(QString::fromUtf8("addVidBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addVidBtn->sizePolicy().hasHeightForWidth());
        addVidBtn->setSizePolicy(sizePolicy3);
        addVidBtn->setBaseSize(QSize(100, 0));
        addVidBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color:#677cc5;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"   background-color:#5b6fb0;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"    background-color: #7998ff;\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid #202020;\n"
"}\n"
"\n"
""));

        gridLayout->addWidget(addVidBtn, 2, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 3, 3, 1);

        runButton = new QPushButton(centralwidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(runButton->sizePolicy().hasHeightForWidth());
        runButton->setSizePolicy(sizePolicy4);
        runButton->setMinimumSize(QSize(0, 410));
        runButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"    background-color: rgb(43, 43, 43);\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid #202020;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        runButton->setIcon(icon);
        runButton->setIconSize(QSize(32, 64));
        runButton->setFlat(false);

        gridLayout->addWidget(runButton, 0, 4, 3, 1);

        addImageBtn = new QPushButton(centralwidget);
        addImageBtn->setObjectName(QString::fromUtf8("addImageBtn"));
        sizePolicy2.setHeightForWidth(addImageBtn->sizePolicy().hasHeightForWidth());
        addImageBtn->setSizePolicy(sizePolicy2);
        addImageBtn->setBaseSize(QSize(0, 0));
        QPalette palette;
        QBrush brush(QColor(250, 250, 250, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(121, 152, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(195, 143, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush3);
        QBrush brush4(QColor(20, 14, 28, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush4);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush6(QColor(29, 84, 92, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush4);
        QBrush brush7(QColor(208, 208, 208, 128));
        brush7.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        addImageBtn->setPalette(palette);
        addImageBtn->setMouseTracking(false);
        addImageBtn->setFocusPolicy(Qt::TabFocus);
        addImageBtn->setLayoutDirection(Qt::LeftToRight);
        addImageBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color:#677cc5;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"   background-color:#5b6fb0;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"    background-color: #7998ff;\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid #202020;\n"
"}\n"
"\n"
""));
        addImageBtn->setAutoRepeat(false);
        addImageBtn->setAutoDefault(false);
        addImageBtn->setFlat(false);

        gridLayout->addWidget(addImageBtn, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 21));
        menuBar->setStyleSheet(QString::fromUtf8("QMenu:hover{\n"
"	background-color: #fafafa;\n"
"	color: #252525;\n"
"}\n"
"\n"
"QMenuBar {\n"
"	background-color: #252525;\n"
"	color: #fafafa;\n"
"}"));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QString::fromUtf8("menuTools"));
        MainWindow->setMenuBar(menuBar);
#if QT_CONFIG(shortcut)
        imgPanel->setBuddy(scrollArea);
#endif // QT_CONFIG(shortcut)

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        addImageBtn->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Demonstration", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
#if QT_CONFIG(whatsthis)
        VideoPanel->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
        imgPanel->setText(QString());
        addVidBtn->setText(QCoreApplication::translate("MainWindow", "Add new video", nullptr));
        runButton->setText(QString());
        addImageBtn->setText(QCoreApplication::translate("MainWindow", "Load image", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Tools", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
