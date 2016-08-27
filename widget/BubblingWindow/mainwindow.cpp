#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | windowFlags());
    setFixedSize(200, 100);

    m_pShowTimer = new QTimer(this);
    m_pStayTimer = new QTimer(this);
    m_pCloseTimer = new QTimer(this);
    m_pPoint = new QPoint();
    m_pLabel = new QLabel(this);

    connect(m_pShowTimer, SIGNAL(timeout()), this, SLOT(onMove()));
    connect(m_pStayTimer, SIGNAL(timeout()), this, SLOT(onStay()));
    connect(m_pCloseTimer, SIGNAL(timeout()), this, SLOT(onClose()));
    m_pLabel->move(20,30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onMove()
{
    m_nDesktopHeight--;
    QThread::msleep(10);
    move(m_pPoint->x(), m_nDesktopHeight);
    if (m_nDesktopHeight < m_pPoint->y()) {
        m_pShowTimer->stop();
        m_pStayTimer->start(3000);
    }
}

void MainWindow::onStay()
{
    m_pStayTimer->stop();
    m_pCloseTimer->start(100);
}

void MainWindow::onClose()
{
    m_dTransparent -= 0.1;
    if (m_dTransparent <= 0.0) {
        m_pCloseTimer->stop();
        close();
    }
    else {
        setWindowOpacity(m_dTransparent);
    }
}

void MainWindow::showMessage(const QString &message)
{
    m_pLabel->setText(message);
    QRect rect = qApp->desktop()->availableGeometry();
    m_pPoint->setX(rect.width() - width());
    m_pPoint->setY(rect.height() - height());
    m_nDesktopHeight = rect.height();
    m_dTransparent = 1;
    m_pShowTimer->start(5);
}
