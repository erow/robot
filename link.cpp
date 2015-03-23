#include "link.h"

Link::Link(Bone *a,Bone* b,double angle,double w,double pow)
{
    max_angle=angle;
    weight=w;
    power=pow;
    type=Tangle;
    sign=0;
    A=a;B=b;

    rotationVector=Vector3d(1,0,0);
    translate=A->gesture;
    this->angle=0;

    b->gesture=a->gesture;
    b->head=a->tail;
    b->cal();
}
bool Link::setAngle(double a){

    angle=a;
    cal();
    return 1;
}
void Link::addAngle(double a){
    translate=AngleAxisd(a, rotationVector)*translate;
    cal();
}

bool Link::setRotationVector(double a,double b,double c){

    rotationVector=Vector3d(a,b,c);
    cal();
    return 1;
}

void Link::cal(){

     B->gesture=translate*(AngleAxisd(angle, A->gesture*rotationVector)*A->gesture);
     B->head=A->tail;
     B->cal();
}
bool Link::getCentroid(Vector3d &re){

    re+=(A->tail)*weight;
    return true;
}
