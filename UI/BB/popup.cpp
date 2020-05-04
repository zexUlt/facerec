#include "popup.h"

#include <QString>
#include <QTimer>
#include <QPaintEvent>
#include <QPainter>
#include <QDesktopWidget>

PopUp::PopUp(QWidget* _parent)
    : QWidget(_parent)
{
    parent = _parent;
    setWindowFlags(Qt::FramelessWindowHint |
                   Qt::Tool |
                   Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_ShowWithoutActivating);

    anim.setTargetObject(this);
    anim.setPropertyName("popupOpacity");
    connect(&anim, &QAbstractAnimation::finished, this, &PopUp::hide);

    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    label.setStyleSheet("QLabel { color : white; "
                        "margin-top: 6px;"
                        "margin-bottom: 6px;"
                        "margin-left: 10px;"
                        "margin-right: 10px; }");

    layout.addWidget(&label, 0, 0);
    setLayout(&layout);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &PopUp::hideAnimation);
}

void PopUp::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect roundedRect;
    roundedRect.setX(rect().x() + 5);
    roundedRect.setY(rect().y() + 5);
    roundedRect.setWidth(rect().width() - 10);
    roundedRect.setHeight(rect().height() - 10);

    painter.setBrush(QBrush(QColor(0, 0, 0, 180)));
    painter.setPen(Qt::NoPen);

    painter.drawRoundedRect(roundedRect, 10, 10);
}

void PopUp::setPopupText(const QString& text)
{
    this->label.setText(text);
    adjustSize();
}

void PopUp::show()
{
    setWindowOpacity(.0);

    this->anim.setDuration(150);
    this->anim.setStartValue(.0);
    this->anim.setEndValue(1.);

    setGeometry(this->parent->geometry().x() + this->parent->geometry().width()/2 - width(),
                this->parent->geometry().y() + this->parent->geometry().height()/2 - height(),
                width()*2,
                height()*2);

    QWidget::show();

    this->anim.start();
    this->timer->start(1000);
}

void PopUp::hideAnimation()
{
    this->timer->stop();
    this->anim.setDuration(1000);
    this->anim.setStartValue(1.);
    this->anim.setEndValue(0.);
    this->anim.start();
}

void PopUp::hide()
{
    if(getPopupOpacity() == 0.){
        QWidget::hide();
    }
}

void PopUp::setPopupOpacity(float opacity)
{
    this->popupOpacity = opacity;
    setWindowOpacity(opacity);
}

float PopUp::getPopupOpacity() const
{
    return this->popupOpacity;
}
