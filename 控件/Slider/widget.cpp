#include "widget.h"
#include "ui_widget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(this);

    int nMin = 0;
    int nMax = 100;
    int nStep = 10;

    QSpinBox *spinBox = new QSpinBox(this);
    spinBox->setMinimum(nMin);
    spinBox->setMaximum(nMax);
    spinBox->setSingleStep(nStep);

    QSlider *slider = new QSlider(this);
    slider->setOrientation(Qt::Horizontal);
    slider->setMinimum(nMin);
    slider->setMaximum(nMax);
    slider->setSingleStep(nStep);

    slider->setTickInterval(20);
    slider->setTickPosition(QSlider::TicksAbove);

    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    spinBox->setValue(50);

    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(slider);
    setLayout(mainLayout);
    //设置刻度时不再使用样式表
    //setStyle("style.qss");
}

void Widget::setStyle(const QString &style)
{
    QFile qss(":/qss/" + style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}

Widget::~Widget()
{
    delete ui;
}
