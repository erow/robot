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
    refer_gesture<<1,0,0 , 0,1,0 ,0,0,1;
    refer_gesture=AngleAxisd(M_PI*5/4, Vector3d(0,0,1));
    refer_pos<<400,400,-20;

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::linkclicked(){
    valuechange();

}
void robotmove(double* res,double d){
    double a=0;
    double h=15;
    if(sqrt(20*20-h*h)<d)
        d=sqrt(20*20-h*h);
    a=atan2(d,h);
    double b=acos(sqrt(h*h+d*d)/2/10);
    res[1]=-b*2;
    res[0]=-a+b;
    res[2]=M_PI_2l-res[0]-res[1];
}

void MainWindow::step(){


    if(!cur_link)
        ui->num->setText(QString("null"));
    else
        ui->num->setText(QString::number(cur_link->sign));

    static int v=100,i=0;
    if(i+v>1000)
        v=-100;
    if(i+v<0)
        v=100;
    i+=v;
    double result[3];
    robotmove(result,sqrt(20*20-15*15)*i/1000);
    int j=0;
    robot.changeAngle(j+4,result[j]);j++;
    robot.changeAngle(j+4,result[j]);j++;
    robot.changeAngle(j+4,result[j]);j++;

    robotmove(result,sqrt(20*20-15*15)*(1000-i)/1000);
    j=0;
    robot.changeAngle(j+10,result[j]);j++;
    robot.changeAngle(j+10,result[j]);j++;
    robot.changeAngle(j+10,result[j]);j++;
    update();
}

void MainWindow::valuechange(){
    QString angle,motor;
    angle=ui->Edit_angle->text();
    motor=ui->Edit_rote->text();
    if(!cur_link) return;
    if(motor.toInt()==0)
    cur_link->changeAngle(angle.toDouble());
    else
        robot.changeAngle(motor.toInt(),(angle.toDouble()));
}


void MainWindow::on_button_rote_clicked()
{
    valuechange();
    update();
}
void MainWindow::paintEvent ( QPaintEvent * e){
    QMainWindow::paintEvent(e);

    QPainter pen(this);
    pen.drawEllipse(Screan_x,Screan_y,10,10);
    // pen.drawEllipse(target);
    //draw bones
    QPoint po(Screan_x,Screan_y);
    //p1=po;

    for(int i=1;i<14;i++){
        int x,y,z;
        double a,b,c;
        robot.getBone(i)->getTailPos(a,b,c);
        qDebug()<<"i:"<<i<<",x:"<<a<<",y:"<<b<<",z:"<<c<<"\n";
        viewPort(robot.getBone(i)->head,x,z);
        QPoint p1(x,-z);
        viewPort(robot.getBone(i)->tail,x,z);
        QPoint pt(x,-z);
        pen.drawLine(po+p1,po+pt);


    }
}
