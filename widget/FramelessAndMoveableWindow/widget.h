#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QMouseEvent;
class QLabel;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    bool m_bPressed;
    QPoint m_point;
    QLabel *label;

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // WIDGET_H
