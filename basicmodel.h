#ifndef BASICMODEL_H
#define BASICMODEL_H
#include "TYPEDEF.H"
#include <vector>
#include <map>

class ModelTree:public Tree<Link*>{
public:
    ModelTree(){;}

    void cal();
    bool getCentroid(Vector3d& re);
    ModelTree* connect(Bone *b);

};

class BasicModel
{
protected:
    std::vector<Bone*> bones;
    std::vector<Link*> links;
    double weight;
public:
    static  std::map<int,ModelTree*> m_links;
    ModelTree searchTree;

    Matrix3d refer_gesture;
    Vector3d refer_pos;

public:
    BasicModel();
    bool changeAngle(int sign,double det);
    bool changeRote(int SIGN,double det);
    void getCentroid(Vector3d& re);
    void getRefer_pos(Vector3d& re,int sign,int head);
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};

#endif // BASICMODEL_H
