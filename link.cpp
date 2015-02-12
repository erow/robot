#include "link.h"

Link::Link(Bone *a,Bone* b,double angle,double w,double pow)
{
    max_angle=angle;
    weight=w;
    power=pow;
    type=0;sign=0;
    A=a;B=b;

    rote=0;
    this->angle=0;

    b->gesture=a->gesture;
    b->head=a->tail;
    b->cal();
}
bool Link::setAngle(double a){
    Matrix3d T;
    T=
            AngleAxisd(a-angle, A->gesture.col(1))
            * AngleAxisd(0, A->gesture.col(2));
    B->gesture=T*B->gesture;
    B->cal();
    angle=a;
    return 1;
}
bool Link::setRote(double a){

    Matrix3d T;

    T=      AngleAxisd(0, A->gesture.col(1))
            * AngleAxisd(a-rote, A->gesture.col(2));
    B->gesture=T*B->gesture;

    B->cal();
    rote=a;
    return 1;
}
void Link::cal(){
    Matrix3d T;
    T=AngleAxisd(rote, A->gesture.col(2))*
      AngleAxisd(angle, A->gesture.col(1))
            ;

     B->gesture=T*A->gesture;
     B->head=A->tail;
     B->cal();
}
bool Link::getCentroid(Vector3d &re){

    re+=(A->tail)*weight;
    return true;
}
