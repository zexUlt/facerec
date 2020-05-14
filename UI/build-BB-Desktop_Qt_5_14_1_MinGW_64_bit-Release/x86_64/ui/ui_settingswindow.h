/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *widget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *outFolderPathEntry;
    QLabel *label_3;
    QPushButton *browsePhotoBtn;
    QPushButton *browsePyBtn;
    QLabel *label;
    QLineEdit *photoPathEntry;
    QLabel *label_2;
    QLineEdit *videoPathEntry;
    QSpacerItem *verticalSpacer_5;
    QPushButton *browseVideoBtn;
    QLineEdit *pyModulePathEntry;
    QLabel *label_4;
    QPushButton *browseRootBtn;
    QLineEdit *rootPathEntry;
    QSpacerItem *verticalSpacer;
    QPushButton *browseOutBtn;
    QFrame *line;
    QPushButton *SaveBtn;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(1000, 270);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsWindow->sizePolicy().hasHeightForWidth());
        SettingsWindow->setSizePolicy(sizePolicy);
        SettingsWindow->setMinimumSize(QSize(1000, 270));
        SettingsWindow->setMaximumSize(QSize(1002, 270));
        SettingsWindow->setBaseSize(QSize(753, 180));
        SettingsWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"	background-color: #222;\n"
"	color: #fff;\n"
"}"));
        verticalLayout = new QVBoxLayout(SettingsWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(SettingsWindow);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(984, 150));
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 982, 207));
        widget = new QWidget(scrollAreaWidgetContents);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 961, 201));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 951, 191));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        outFolderPathEntry = new QLineEdit(layoutWidget);
        outFolderPathEntry->setObjectName(QString::fromUtf8("outFolderPathEntry"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(outFolderPathEntry->sizePolicy().hasHeightForWidth());
        outFolderPathEntry->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(outFolderPathEntry, 4, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        browsePhotoBtn = new QPushButton(layoutWidget);
        browsePhotoBtn->setObjectName(QString::fromUtf8("browsePhotoBtn"));
        sizePolicy2.setHeightForWidth(browsePhotoBtn->sizePolicy().hasHeightForWidth());
        browsePhotoBtn->setSizePolicy(sizePolicy2);
        browsePhotoBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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

        gridLayout->addWidget(browsePhotoBtn, 1, 4, 1, 1);

        browsePyBtn = new QPushButton(layoutWidget);
        browsePyBtn->setObjectName(QString::fromUtf8("browsePyBtn"));
        sizePolicy2.setHeightForWidth(browsePyBtn->sizePolicy().hasHeightForWidth());
        browsePyBtn->setSizePolicy(sizePolicy2);
        browsePyBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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

        gridLayout->addWidget(browsePyBtn, 3, 4, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        photoPathEntry = new QLineEdit(layoutWidget);
        photoPathEntry->setObjectName(QString::fromUtf8("photoPathEntry"));
        sizePolicy2.setHeightForWidth(photoPathEntry->sizePolicy().hasHeightForWidth());
        photoPathEntry->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(photoPathEntry, 1, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        videoPathEntry = new QLineEdit(layoutWidget);
        videoPathEntry->setObjectName(QString::fromUtf8("videoPathEntry"));
        sizePolicy2.setHeightForWidth(videoPathEntry->sizePolicy().hasHeightForWidth());
        videoPathEntry->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(videoPathEntry, 2, 2, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 5, 1);

        browseVideoBtn = new QPushButton(layoutWidget);
        browseVideoBtn->setObjectName(QString::fromUtf8("browseVideoBtn"));
        sizePolicy2.setHeightForWidth(browseVideoBtn->sizePolicy().hasHeightForWidth());
        browseVideoBtn->setSizePolicy(sizePolicy2);
        browseVideoBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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

        gridLayout->addWidget(browseVideoBtn, 2, 4, 1, 1);

        pyModulePathEntry = new QLineEdit(layoutWidget);
        pyModulePathEntry->setObjectName(QString::fromUtf8("pyModulePathEntry"));
        sizePolicy2.setHeightForWidth(pyModulePathEntry->sizePolicy().hasHeightForWidth());
        pyModulePathEntry->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(pyModulePathEntry, 3, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        browseRootBtn = new QPushButton(layoutWidget);
        browseRootBtn->setObjectName(QString::fromUtf8("browseRootBtn"));
        sizePolicy2.setHeightForWidth(browseRootBtn->sizePolicy().hasHeightForWidth());
        browseRootBtn->setSizePolicy(sizePolicy2);
        browseRootBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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

        gridLayout->addWidget(browseRootBtn, 0, 4, 1, 1);

        rootPathEntry = new QLineEdit(layoutWidget);
        rootPathEntry->setObjectName(QString::fromUtf8("rootPathEntry"));
        sizePolicy2.setHeightForWidth(rootPathEntry->sizePolicy().hasHeightForWidth());
        rootPathEntry->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(rootPathEntry, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 5, 1);

        browseOutBtn = new QPushButton(layoutWidget);
        browseOutBtn->setObjectName(QString::fromUtf8("browseOutBtn"));
        sizePolicy2.setHeightForWidth(browseOutBtn->sizePolicy().hasHeightForWidth());
        browseOutBtn->setSizePolicy(sizePolicy2);
        browseOutBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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

        gridLayout->addWidget(browseOutBtn, 4, 4, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        line = new QFrame(SettingsWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("Line {\n"
"	border: 1px solid #FFF;\n"
"}"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        SaveBtn = new QPushButton(SettingsWindow);
        SaveBtn->setObjectName(QString::fromUtf8("SaveBtn"));
        SaveBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color:#21733e;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:#0b5e29;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"    background-color: #329c58;\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid #202020;\n"
"}"));

        verticalLayout->addWidget(SaveBtn);


        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Settings", nullptr));
        label_5->setText(QCoreApplication::translate("SettingsWindow", "Output path", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsWindow", "Path to video database", nullptr));
        browsePhotoBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        browsePyBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        label->setText(QCoreApplication::translate("SettingsWindow", "Path to root directory", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsWindow", "Path to photo database", nullptr));
        browseVideoBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsWindow", "Path to processing python module", nullptr));
        browseRootBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        browseOutBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        SaveBtn->setText(QCoreApplication::translate("SettingsWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
