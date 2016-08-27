#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTimer;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer *m_pShowTimer;
    QTimer *m_pStayTimer;
    QTimer *m_pCloseTimer;
    QLabel *m_pLabel;
    QPoint  *m_pPoint;
    int m_nDesktopHeight;
    double m_dTransparent;

private slots:
    void onMove();
    void onStay();
    void onClose();

public:
    void showMessage(const QString& message);
};

#endif // MAINWINDOW_H
