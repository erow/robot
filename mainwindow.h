#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qmlink.h"
#include "pendulum.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    //void MainWindow::timerEvent();
    void linkclicked();
    void step();
    void valuechange();
    void on_button_rote_clicked();
    void paintEvent ( QPaintEvent * e);
private:
    PendulumView robot;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
