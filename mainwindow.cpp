#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmlink.h"
#include <QtGui>
#include <QTimer>
//QMLink* cur_link;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer* timer=new QTimer(this);
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
    cur_link=0;
    robot.init(this);
    robot.refer_gesture<<1,0,0 , 0,1,0 ,0,0,1;
    robot.refer_pos<<0,-10,0;

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::linkclicked(){
    valuechange();

}
void MainWindow::step(){
    if(!cur_link)
        ui->num->setText(QString("null"));
    else
        ui->num->setText(QString::number(cur_link->sign));
}

void MainWindow::valuechange(){
    QString angle,rote;
    angle=ui->Edit_angle->text();
    rote=ui->Edit_rote->text();
    cur_link->changeRote((rote.toDouble()));
}


void MainWindow::on_button_rote_clicked()
{

}
