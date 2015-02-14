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
    robot.refer_gesture=AngleAxisd(M_PI/4, Vector3d(0,0,1))*robot.refer_gesture;
    robot.refer_pos<<10,-10,0;

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
    cur_link->changeAngle(angle.toDouble());
}


void MainWindow::on_button_rote_clicked()
{
    valuechange();
    update();
}
void MainWindow::paintEvent ( QPaintEvent * e){
    QMainWindow::paintEvent(e);

    QPainter pen(this);
    pen.drawEllipse(200,200,30,30);
   // pen.drawEllipse(target);
    //draw bones
    QPoint po(200,200);
    //p1=po;
    for(int i=1;i<10;i++){
        double x,y,z;
        robot.getBone(i)->getHeadPos(x,y,z);
        QPoint p1(x,-z);
        robot.getBone(i)->getTailPos(x,y,z);
        QPoint pt(x,-z);
        pen.drawLine(po+p1,po+pt);

        qDebug()<<"i:"<<i<<",x:"<<x<<",y:"<<y<<",z:"<<z<<"\n";
    }
}
