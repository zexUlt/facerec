#ifndef POPUP_H
#define POPUP_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>

class QPaintEvent;
class QString;
class QTimer;

class PopUp : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(float popupOpacity READ getPopupOpacity WRITE setPopupOpacity)

    void setPopupOpacity(float opacity);
    float getPopupOpacity() const;

public:
    explicit PopUp(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

public slots:
    void setPopupText(const QString& text);
    void show();

private slots:
    void hideAnimation();
    void hide();

private:
    QWidget* parent;
    QLabel label;
    QGridLayout layout;
    QPropertyAnimation anim;
    float popupOpacity;
    QTimer* timer;

};

#endif // POPUP_H
