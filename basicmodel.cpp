#include "basicmodel.h"


BasicModel::BasicModel()
{

}
bool BasicModel::changeAngle(int sign, double det){
     m_links[sign]->value->setAngle(det);
     m_links[sign]->cal();
     return true;
}
bool BasicModel::changeRote(int sign, double det){
    m_links[sign]->value->setRote(det);
    m_links[sign]->cal();
    return true;
}
void BasicModel::getCentroid(Vector3d &re){

}
void BasicModel::getRefer_pos(Vector3d &re, int sign, int head){
    Matrix3d p0,t;
    p0=bones[0]->gesture;
    Vector3d v0=Vector3d::Zero(),v,tv;
    v=v0;
    bones[0]->getCentroid(v0);
    m_links[sign]->value->getCentroid(v);
    v0/=bones[0]->getWeight();
    v/=m_links[sign]->value->getWeight();
    tv=refer_pos-v0;
    t=refer_gesture*p0.adjoint();
    v-=tv;
    re=t.adjoint()*v;

}
 std::map<int,ModelTree*> BasicModel::m_links;
void ModelTree::cal(){
    value->cal();
    for(unsigned int i=0;i<children.size();i++){
    // children[i]->value->cal();
        ((ModelTree*)children[i])->cal();
    }

}
ModelTree* ModelTree::connect(Bone *b){
    ModelTree* t=(ModelTree *)new Tree(new Link(value->B,b));
   children.push_back(t);
   static int num=0;
   t->value->setSign(num);
   BasicModel::m_links[num]=t;
   num++;
   return t;
}
bool ModelTree::getCentroid(Vector3d &re){

    for(unsigned int i=0;i<children.size();i++){
        value->B->getCentroid(re);
        value->getCentroid(re);
       ((ModelTree*)children[i])->getCentroid(re);
    }
    return true;
}