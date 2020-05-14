/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *vidPreview;
    QPushButton *openBtn;
    QPushButton *deleteBtn;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));
        VideoWidget->setEnabled(true);
        VideoWidget->resize(475, 335);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(VideoWidget->sizePolicy().hasHeightForWidth());
        VideoWidget->setSizePolicy(sizePolicy);
        VideoWidget->setMinimumSize(QSize(0, 0));
        VideoWidget->setMaximumSize(QSize(475, 350));
        VideoWidget->setBaseSize(QSize(0, 0));
        gridLayout = new QGridLayout(VideoWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 19, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        vidPreview = new QLabel(VideoWidget);
        vidPreview->setObjectName(QString::fromUtf8("vidPreview"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(vidPreview->sizePolicy().hasHeightForWidth());
        vidPreview->setSizePolicy(sizePolicy1);
        vidPreview->setMinimumSize(QSize(457, 281));
        vidPreview->setMaximumSize(QSize(457, 281));
        vidPreview->setBaseSize(QSize(0, 0));
        vidPreview->setFrameShadow(QFrame::Raised);
        vidPreview->setScaledContents(true);
        vidPreview->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(vidPreview, 0, 0, 1, 3);

        openBtn = new QPushButton(VideoWidget);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        sizePolicy1.setHeightForWidth(openBtn->sizePolicy().hasHeightForWidth());
        openBtn->setSizePolicy(sizePolicy1);
        openBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
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
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/icons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        openBtn->setIcon(icon);
        openBtn->setIconSize(QSize(16, 24));

        gridLayout->addWidget(openBtn, 1, 0, 1, 1);

        deleteBtn = new QPushButton(VideoWidget);
        deleteBtn->setObjectName(QString::fromUtf8("deleteBtn"));
        sizePolicy1.setHeightForWidth(deleteBtn->sizePolicy().hasHeightForWidth());
        deleteBtn->setSizePolicy(sizePolicy1);
        deleteBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color:#872626;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color:#751616;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"    background-color: #a63232;\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid #202020;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/icons/recycling-bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        deleteBtn->setIcon(icon1);
        deleteBtn->setIconSize(QSize(24, 24));

        gridLayout->addWidget(deleteBtn, 1, 2, 1, 1);


        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QCoreApplication::translate("VideoWidget", "Form", nullptr));
        vidPreview->setText(QString());
        openBtn->setText(QCoreApplication::translate("VideoWidget", "Open", nullptr));
        deleteBtn->setText(QCoreApplication::translate("VideoWidget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
