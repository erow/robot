#include "bone.h"

Bone::Bone(double len,double w)
{
    length=len;weight=w;
    sign=0;
    type=0;

}
void Bone::setOrigin(){
    length=0;
    head=tail=Vector3d::Zero();
    gesture<<Vector3d::UnitX(),Vector3d::UnitY(),Vector3d::UnitZ();

}
void Bone::cal(){
    tail=head+length*gesture.col(2);

}
bool Bone::getCentroid(Vector3d &re){

    re+=(head+tail)/2*weight;
    return true;
}
