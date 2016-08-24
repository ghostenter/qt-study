#include "widget.h"
#include <QApplication>
#include <QtWidgets>

void setStyle(const QString &style);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setStyle("style.qss");

    Widget w;
    w.show();

    return a.exec();
}

//静态加载样式函数
void setStyle(const QString &style)
{
    QFile qss(":/qss/" + style);
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());
    qss.close();
}
