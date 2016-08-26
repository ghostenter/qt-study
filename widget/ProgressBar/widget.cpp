#include "widget.h"
#include "ui_widget.h"
#include <QProgressBar>
#include <QVBoxLayout>
#include <QFile>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout();

    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->setRange(0, 0);
    progressBar->setInvertedAppearance(true);

    QProgressBar *progressBar1 = new QProgressBar(this);
    progressBar1->setOrientation(Qt::Horizontal);
    progressBar1->setMinimum(0);
    progressBar1->setMaximum(100);
    progressBar1->setValue(50);

    QProgressBar *progressBar2 = new QProgressBar(this);
    progressBar2->setOrientation(Qt::Horizontal);
    //progressBar2->setRange(0, 100);
    progressBar2->setMinimum(0);
    progressBar2->setMaximum(100);
    progressBar2->setValue(50);
    progressBar2->setInvertedAppearance(true);

    double dProgress = (progressBar2->value() - progressBar2->minimum()) * 100.0
                    / (progressBar2->maximum() - progressBar2->minimum());
    progressBar2->setFormat(QString("当前进度%1").arg(QString::number(dProgress, 'f', 1)));
    progressBar2->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    mainLayout->addWidget(progressBar);
    mainLayout->addWidget(progressBar1);
    mainLayout->addWidget(progressBar2);
    setLayout(mainLayout);

    setStyle("style.qss");
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




