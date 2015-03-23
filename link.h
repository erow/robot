#ifndef LINK_H
#define LINK_H

#include "TYPEDEF.H"
class Bone;
using namespace Eigen;
enum LinkType{
Trote,Tangle
};
class Link
{
protected:
    //硬件参数
    double max_angle;
    double weight;//g
    double power;//N*m/s
    LinkType type;
    int sign;
    //自变量

    Vector3d rotationVector;
    double angle;
public:
    //临时参数，因变量
    Vector3d pos;
    Matrix3d translate;//save changed
     Bone *A,*B;
public:
    bool getCentroid(Vector3d& re);
    void cal();
    Link(Bone *a,Bone* b,double angle=M_PI,double w=50,double pow=10);
    bool setAngle(double a);
    void addAngle(double a);
    bool setRotationVector(double,double,double);

    void setSign(int s){sign=s;}
    double getWeight(){return weight;}
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
};

#endif // LINK_H
