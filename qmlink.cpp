#include "qmlink.h"
#include "basicmodel.h"
#include "mainwindow.h"
#include <QtGui>
QMLink *cur_link=0;
void PendulumView::init(QWidget* te){
    std::cout<<"qlink init !\n";
    parent=te;
    for(int i=0;i<16;i++){
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
    t=t->connect(bones[5]);
    t=t->connect(bones[6]);
    t=t->connect(bones[7]);
    int j=8;

    t=searchTree.connect(bones[j++]);//right leg 7
    t=t->connect(bones[j++]);
    t=t->connect(bones[j++]);
    t=t->connect(bones[j++]);
    t=t->connect(bones[j++]);
    t=t->connect(bones[j++]);

    weight=50*8+20*5;




    //m_links[1]->value->setRotationVector(0,0,1);
    //m_links[1]->value->setRotationVector(0,0,1);
    changeAngle(1,M_PI/2);
    //m_links[1]->value->translate=AngleAxisd(M_PI/2,Vector3d(0,-1,0));


    m_links[1]->cal();
    //m_links[1]->value->setRotationVector(1,0,0);
    //m_links[2]->value->setRotationVector(0,1,0);
     changeAngle(2,M_PI/2);
     //m_links[2]->value->setRotationVector(0,0,1);
    //m_links[2]->value->addAngle(M_PI/2);
    m_links[3]->value->setRotationVector(0,0,1);
  //  m_links[4]->value->setRotationVector(0,0,1);
    changeAngle(3,M_PI/2);
    changeAngle(6,M_PI/2);

    /*changeAngle(5,M_PI/2);

    changeAngle(6,M_PI/2);
    m_links[8]->value->setRotationVector(0,0,1);
    changeAngle(8, M_PI/2);
    m_links[8]->value->setRotationVector(1,0,0);
    changeAngle(8,M_PI/3);
*/
    changeAngle(7,-M_PI/2);
    changeAngle(8,-M_PI/2);

    m_links[9]->value->setRotationVector(0,0,1);
    changeAngle(9,M_PI/2);
    changeAngle(12,M_PI/2);

    QMLink*asd;

    for(int i=1;i<=12;i++){
        asd=new QMLink(parent);
        asd->sign=i;
        asd->robot=this;
    }

    std::cout<<"qlink init done!\n";

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
    QRectF source(0.0, 0.0, 80.0, 80.0);
    QImage image("link");
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
