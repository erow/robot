#include "qmlink.h"
#include "basicmodel.h"
#include "mainwindow.h"
#include <QtGui>
QMLink *cur_link=0;
void PendulumView::init(QWidget* te){
    parent=te;
    for(int i=0;i<10;i++){
        bones.push_back(new Bone);
        bones[i]->setSign(i);
    }
    bones[0]->setOrigin();

    searchTree.value=new Link(bones[0],bones[0]);
    searchTree.connect(bones[1]);//head  0
    ModelTree * t;
    t=searchTree.connect(bones[2]);//left leg 1
    t=t->connect(bones[3]);
    t=t->connect(bones[4]);
    t->connect(bones[5]);

    t=searchTree.connect(bones[6]);//right leg 5
    t=t->connect(bones[7]);
    t=t->connect(bones[8]);
    t->connect(bones[9]);

    weight=50*8+20*5;
    changeAngle(1,M_PI/2);
    changeRote(1,M_PI);
    changeAngle(2,M_PI/2);
    changeRote(4,-M_PI/2);
    changeAngle(4,M_PI/3);

    changeAngle(5,M_PI/2);

    changeAngle(6,M_PI/2);
    changeRote(8, M_PI/2);
    changeAngle(8,M_PI/3);

    QMLink*asd;

    for(int i=0;i<=8;i++){
        asd=new QMLink(parent);
        asd->sign=i;
        asd->robot=this;
    }


}
QMLink::QMLink(QWidget *parent) :
    QPushButton(parent)
{
}
bool QMLink::hitButton ( const QPoint & pos ){
    //this->hide();
    return 1;
}
void QMLink::focusInEvent ( QFocusEvent * e ){
   cur_link=this;

}
QPainterPath QMLink::shape()
  {
      QPainterPath path;
      path.addEllipse(QRectF(-65, -65, 130, 130));
      return path;
  }
void QMLink::paintEvent ( QPaintEvent * e){
    cal();
    QRectF target(0.0,0.0, 16.0, 16.0);
    QRectF source(0.0, 0.0, 100.0, 100.0);
    QImage image("ellipse.png");
    QPainter pen(this);
   //pen.drawRoundedRect(0, 0, 30, 30,15,15);
    pen.drawImage(target, image, source);
   // pen.drawEllipse(target);
}
void QMLink::cal(){
    int x,y,z;
   // PendulumView::m_links[sign]->value->B->getHeadPos(x,y,z);
    //robot->getPos(x,y,sign);
    viewPort(PendulumView::m_links[sign]->value->B->head,x,z);
    setPos(Screan_x+x,Screan_y-z);
    double q=PendulumView::m_links[sign]->value->B->head(0);
    qDebug()<<"sign:"<<sign;//<<",x:"<<x<<",y:"<<y<<"\n"<<q<<"\n";
}
