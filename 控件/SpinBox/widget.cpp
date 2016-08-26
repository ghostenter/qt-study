#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QSpinBox *spinBox = new QSpinBox(this);

    spinBox->setRange(20, 200);
    spinBox->setSingleStep(10);
    spinBox->setValue(150);
    spinBox->setPrefix("$");
    spinBox->setSuffix("%");
    spinBox->setWrapping(true);
    spinBox->setSpecialValueText("Automatic");

    connect(spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
                [=](int value)
            {
                qDebug() << "Value : "  << value;
                qDebug() << "Text : "  << spinBox->text();
            });

            connect(spinBox, static_cast<void(QSpinBox::*)(const QString &)>(&QSpinBox::valueChanged),
                [=](const QString &text)
            {
                qDebug() << "Text Value : "  << text;
                qDebug() << "Clean Text : " << spinBox->cleanText();
            });

    QDoubleSpinBox *doubleSpinBox = new QDoubleSpinBox(this);
    doubleSpinBox->setRange(0, 20);
    doubleSpinBox->setValue(1);
    doubleSpinBox->setDecimals(3);
    doubleSpinBox->setSingleStep(0.005);

    mainLayout->addWidget(spinBox);
    mainLayout->addWidget(doubleSpinBox);
    setLayout(mainLayout);
}

Widget::~Widget()
{
    delete ui;
}
