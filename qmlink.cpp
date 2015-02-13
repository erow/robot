#include "qmlink.h"
#include "basicmodel.h"
#include <QtGui>
QMLink *cur_link=0;
void PendulumView::init(QWidget* te){
    parent=te;
    for(int i=0;i<8;i++){
        bones.push_back(new Bone);
        bones[i]->setSign(i);
    }
    bones[0]->setOrigin();

    searchTree.value=new Link(bones[0],bones[1]);

    ModelTree * t;
    t=searchTree.connect(bones[2]);
    t->connect(bones[3]);
    t=searchTree.connect(bones[4]);
    t->connect(bones[5]);
    weight=50*8+20*5;

    QMLink*asd=new QMLink(parent);
    asd->sign=0;
    asd->robot=this;
    asd=new QMLink(parent);
    asd->sign=1;
    asd->robot=this;
    asd=new QMLink(parent);
    asd->sign=2;
    asd->robot=this;
    asd=new QMLink(parent);
    asd->sign=3;
    asd->robot=this;

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
