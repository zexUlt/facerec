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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QPushButton *SaveBtn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *browsePyBtn;
    QPushButton *browseRootBtn;
    QLabel *label;
    QLabel *label_4;
    QPushButton *browseVideoBtn;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_5;
    QLineEdit *rootPathEntry;
    QLineEdit *videoPathEntry;
    QSpacerItem *verticalSpacer;
    QLineEdit *photoPathEntry;
    QLineEdit *pyModulePathEntry;
    QPushButton *browsePhotoBtn;

    void setupUi(QWidget *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(753, 200);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsWindow->sizePolicy().hasHeightForWidth());
        SettingsWindow->setSizePolicy(sizePolicy);
        SettingsWindow->setMinimumSize(QSize(753, 200));
        SettingsWindow->setMaximumSize(QSize(753, 200));
        SettingsWindow->setBaseSize(QSize(753, 180));
        SettingsWindow->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"	background-color: #222;\n"
"	color: #fff;\n"
"}"));
        SaveBtn = new QPushButton(SettingsWindow);
        SaveBtn->setObjectName(QString::fromUtf8("SaveBtn"));
        SaveBtn->setGeometry(QRect(590, 160, 151, 31));
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
        layoutWidget = new QWidget(SettingsWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 731, 136));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        browsePyBtn = new QPushButton(layoutWidget);
        browsePyBtn->setObjectName(QString::fromUtf8("browsePyBtn"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(browsePyBtn->sizePolicy().hasHeightForWidth());
        browsePyBtn->setSizePolicy(sizePolicy1);
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

        browseRootBtn = new QPushButton(layoutWidget);
        browseRootBtn->setObjectName(QString::fromUtf8("browseRootBtn"));
        sizePolicy1.setHeightForWidth(browseRootBtn->sizePolicy().hasHeightForWidth());
        browseRootBtn->setSizePolicy(sizePolicy1);
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

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        browseVideoBtn = new QPushButton(layoutWidget);
        browseVideoBtn->setObjectName(QString::fromUtf8("browseVideoBtn"));
        sizePolicy1.setHeightForWidth(browseVideoBtn->sizePolicy().hasHeightForWidth());
        browseVideoBtn->setSizePolicy(sizePolicy1);
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

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 4, 1);

        rootPathEntry = new QLineEdit(layoutWidget);
        rootPathEntry->setObjectName(QString::fromUtf8("rootPathEntry"));
        sizePolicy1.setHeightForWidth(rootPathEntry->sizePolicy().hasHeightForWidth());
        rootPathEntry->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(rootPathEntry, 0, 2, 1, 1);

        videoPathEntry = new QLineEdit(layoutWidget);
        videoPathEntry->setObjectName(QString::fromUtf8("videoPathEntry"));
        sizePolicy1.setHeightForWidth(videoPathEntry->sizePolicy().hasHeightForWidth());
        videoPathEntry->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(videoPathEntry, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 3, 4, 1);

        photoPathEntry = new QLineEdit(layoutWidget);
        photoPathEntry->setObjectName(QString::fromUtf8("photoPathEntry"));
        sizePolicy1.setHeightForWidth(photoPathEntry->sizePolicy().hasHeightForWidth());
        photoPathEntry->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(photoPathEntry, 1, 2, 1, 1);

        pyModulePathEntry = new QLineEdit(layoutWidget);
        pyModulePathEntry->setObjectName(QString::fromUtf8("pyModulePathEntry"));
        sizePolicy1.setHeightForWidth(pyModulePathEntry->sizePolicy().hasHeightForWidth());
        pyModulePathEntry->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pyModulePathEntry, 3, 2, 1, 1);

        browsePhotoBtn = new QPushButton(layoutWidget);
        browsePhotoBtn->setObjectName(QString::fromUtf8("browsePhotoBtn"));
        sizePolicy1.setHeightForWidth(browsePhotoBtn->sizePolicy().hasHeightForWidth());
        browsePhotoBtn->setSizePolicy(sizePolicy1);
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


        retranslateUi(SettingsWindow);

        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QCoreApplication::translate("SettingsWindow", "Form", nullptr));
        SaveBtn->setText(QCoreApplication::translate("SettingsWindow", "Save", nullptr));
        label_2->setText(QCoreApplication::translate("SettingsWindow", "Path to photo database", nullptr));
        browsePyBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        browseRootBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        label->setText(QCoreApplication::translate("SettingsWindow", "Path to root directory", nullptr));
        label_4->setText(QCoreApplication::translate("SettingsWindow", "Path to processing python module", nullptr));
        browseVideoBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
        label_3->setText(QCoreApplication::translate("SettingsWindow", "Path to video database", nullptr));
        browsePhotoBtn->setText(QCoreApplication::translate("SettingsWindow", "Browse", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
