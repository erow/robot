#include "basicmodel.h"


BasicModel::BasicModel()
{

}
bool BasicModel::changeAngle(int sign, double det){
     m_links[sign]->value->setAngle(det);
     m_links[sign]->cal();
     return true;
}

void BasicModel::getCentroid(Vector3d &re){

}
void BasicModel::getBone_pos(double& x,double& y,double& z,int sign){
    Vector3d p;
   Matrix3d p0,t;
   p0=bones[0]->gesture;
   Vector3d v0=Vector3d::Zero(),v,tv;
   v=v0;
   bones[0]->getCentroid(v0);
   if(1){
       v=bones[sign]->tail;
   }
   else{

   }

   v0/=bones[0]->getWeight();
   tv=refer_pos-v0;
   t=refer_gesture*p0.adjoint();
   v-=tv;
   p=t.adjoint()*v;
   x=p[0];y=p[1];z=p[2];
}

Vector3d viewPort(const Vector3d& refer_pos,const Matrix3d& refer_gesture, int sign){
  /*  Matrix3d p0,t;
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
    return t.adjoint()*v;*/

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
void BasicModel::getPos(int&x,int&y,int sign){
    Vector3d p;
    getRefer_pos(p,sign,1);
    x=p[0];y=p[2];

}
 std::map<int,ModelTree*> BasicModel::m_links;
template<typename T>
void cal_link(Tree<T>* t){
    t->value->cal();
}
void ModelTree::cal(){
    /*value->cal();
    for(unsigned int i=0;i<children.size();i++){
    // children[i]->value->cal();
        ((ModelTree*)children[i])->cal();
    }*/
    Tree::call(cal_link);
}
ModelTree* ModelTree::connect(Bone *b){
   Tree* tnode=new Tree<Link*>(new Link(value->B,b));
   //children.push_back(t);
   static int mnum=0;
   tnode->value->setSign(mnum);
   BasicModel::m_links[mnum]=(ModelTree*)tnode;
   mnum++;
   Tree::addChild(tnode);
   std::cout<<"addchild done!\n";

   return (ModelTree*)tnode;
}
bool ModelTree::getCentroid(Vector3d &re){
/*
    for(unsigned int i=0;i<children.size();i++){
        value->B->getCentroid(re);
        value->getCentroid(re);
       ((ModelTree*)children[i])->getCentroid(re);
    }*/
    return true;
}
