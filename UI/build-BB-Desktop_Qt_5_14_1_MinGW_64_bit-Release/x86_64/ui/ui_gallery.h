/********************************************************************************
** Form generated from reading UI file 'gallery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GALLERY_H
#define UI_GALLERY_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gallery
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *PrevBtn;
    QLabel *label;
    QPushButton *NextBtn;

    void setupUi(QWidget *Gallery)
    {
        if (Gallery->objectName().isEmpty())
            Gallery->setObjectName(QString::fromUtf8("Gallery"));
        Gallery->setWindowModality(Qt::WindowModal);
        Gallery->resize(1106, 554);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Gallery->sizePolicy().hasHeightForWidth());
        Gallery->setSizePolicy(sizePolicy);
        Gallery->setMinimumSize(QSize(854, 500));
        Gallery->setMaximumSize(QSize(1182, 978));
        Gallery->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"	background-color: #222;\n"
"	color: #fff;\n"
"}"));
        verticalLayout = new QVBoxLayout(Gallery);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(108, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer_2);

        label_2 = new QLabel(Gallery);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(108, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_2->addItem(verticalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        PrevBtn = new QPushButton(Gallery);
        PrevBtn->setObjectName(QString::fromUtf8("PrevBtn"));
        PrevBtn->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PrevBtn->sizePolicy().hasHeightForWidth());
        PrevBtn->setSizePolicy(sizePolicy1);
        PrevBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.522727, stop:0 rgba(43, 43, 43, 135), stop:1 rgba(0, 0, 0, 0));\n"
"	border: 1px solid #202020;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.522727, stop:0 rgba(43, 43, 43, 216), stop:1 rgba(0, 0, 0, 0));\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid rgb(13, 13, 13);\n"
"	border-left: 2px solid #202020;\n"
"	border-bottom:  2px solid #202020;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/icons/prev.png"), QSize(), QIcon::Normal, QIcon::Off);
        PrevBtn->setIcon(icon);
        PrevBtn->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(PrevBtn);

        label = new QLabel(Gallery);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/rec/img/placeholders/photo_placeholder_lighter_dark.png")));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        NextBtn = new QPushButton(Gallery);
        NextBtn->setObjectName(QString::fromUtf8("NextBtn"));
        NextBtn->setEnabled(false);
        sizePolicy1.setHeightForWidth(NextBtn->sizePolicy().hasHeightForWidth());
        NextBtn->setSizePolicy(sizePolicy1);
        NextBtn->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.522727, stop:0 rgba(43, 43, 43, 135), stop:1 rgba(0, 0, 0, 0));\n"
"	border: 1px solid #202020;\n"
"}\n"
"\n"
"QPushButton {\n"
"	line-height: 20px;\n"
"    font-size: 12px;\n"
"    padding: 6px 15px;\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.522727, stop:0 rgba(43, 43, 43, 216), stop:1 rgba(0, 0, 0, 0));\n"
"    color: #fafafa;\n"
"    font-family: sans-serif;\n"
"    border-radius: .25em;\n"
"    border: 1px solid rgb(13, 13, 13);\n"
"	border-left: 2px solid #202020;\n"
"	border-bottom:  2px solid #202020;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/icons/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        NextBtn->setIcon(icon1);
        NextBtn->setIconSize(QSize(64, 64));

        horizontalLayout->addWidget(NextBtn);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Gallery);

        QMetaObject::connectSlotsByName(Gallery);
    } // setupUi

    void retranslateUi(QWidget *Gallery)
    {
        Gallery->setWindowTitle(QCoreApplication::translate("Gallery", "Preview", nullptr));
        label_2->setText(QString());
        PrevBtn->setText(QString());
        label->setText(QString());
        NextBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Gallery: public Ui_Gallery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GALLERY_H
