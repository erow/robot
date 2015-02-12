#ifndef BONE_H
#define BONE_H
#include "TYPEDEF.H"
using namespace Eigen;
using std::cout;
using std::endl;
class Bone
{
protected:
    //硬件参数
    double length;//cm
    double weight;//g
    int type;
    int sign;
    //自变量

public:
    //临时参数，因变量
    Vector3d head,tail;
    Matrix3d gesture;
public:
    friend class Link;
    void cal();
    Bone(double len=10,double w=100);
    void setOrigin();
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    void setSign(int s){sign=s;}
    double getWeight(){return weight;}
    bool getCentroid(Vector3d& re);
    void print(){
        cout<<"head:"<<head.transpose()<<endl;
        cout<<"tail:"<<tail.transpose()<<endl;
        cout<<"gesture:"<<endl<<gesture<<endl;
    }
};

#endif // BONE_H
