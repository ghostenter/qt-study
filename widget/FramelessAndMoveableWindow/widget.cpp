#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | windowFlags());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_bPressed = true;
        m_point = event->pos();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    m_bPressed = false;
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed) {
//        qDebug() << "1:" << event->pos();
//        qDebug() << "2:" << m_point;
        move(event->pos() - m_point + pos());
    }
//    qDebug() << "pos:" << pos().x();
//    qDebug() << "cursor:" << cursor().pos().x();
//    qDebug() << "event-pos:" << event->pos().x();
//    qDebug() << "event-globalpos:" << event->globalPos().x();
}
