#ifndef BASICMODEL_H
#define BASICMODEL_H
#include "TYPEDEF.H"
#include <vector>
#include <map>

class ModelTree:public Tree<Link*>{
public:
    ModelTree(){;}
   // void cal_link(Tree* t);
    void cal();
    bool getCentroid(Vector3d& re);
    ModelTree* connect(Bone *b);

};

class BasicModel
{
protected:
    std::vector<Bone*> bones;
   // std::vector<Link*> links;
    double weight;


public:
    static  std::map<int,ModelTree*> m_links;
    ModelTree searchTree;

    Matrix3d refer_gesture;
    Vector3d refer_pos;
    const Bone* getBone(int i){return bones[i];}
    const Link* getLink(int i){return m_links[i]->value;}
public:
    BasicModel();
    static bool changeAngle(int sign,double det);

    void getBone_pos(double& x,double& y,double& z,int sign);
    void getCentroid(Vector3d& re);
    void getRefer_pos(Vector3d& re,int sign,int head);
    void getRefer_pos_link(Vector3d &re, int sign, int head);
    void getPos(int&x,int&y,int sign);
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW

};

#endif // BASICMODEL_H
