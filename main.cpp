#include <iostream>
#include "TYPEDEF.H"
#include "bone.h"
#include "link.h"
#include "pendulum.h"
using namespace std;

int main()
{
    Pendulum robot;

    robot.changeAngle(0,M_PI/6);
    //robot.changeAngle(1,M_PI/6);
    Pendulum::m_links[0]->value->A->print();
    Pendulum::m_links[0]->value->B->print();
    Pendulum::m_links[1]->value->B->print();

    cout<<"ROTE--------------\n";
    robot.changeRote(0,M_PI/3);
    Pendulum::m_links[0]->value->A->print();
    Pendulum::m_links[0]->value->B->print();
    Pendulum::m_links[1]->value->B->print();
    cout<<"transfor:A*T=B\n";
    Matrix3d A,B,T;
    Vector3d a;
    A=Pendulum::m_links[0]->value->A->gesture;
    B=Pendulum::m_links[1]->value->B->gesture;
    //Vector3d x = A.colPivHouseholderQr().solve(b);
    // robot.searchTree.print(1);
    T=B*A.adjoint();
    cout<<T*A<<endl;
    a<<0,0,10;
    cout<<"(a*T):\n"<<T.adjoint()*a<<endl;

    robot.refer_gesture=B;
    robot.refer_pos<<0,0,10;

    robot.getRefer_pos(a,1,1);
    cout<<"a********\n"<<a<<endl;
    return 1;
}

/*
Matrix3d A;A<<1,0,0
                 ,0,1,0
                 ,0,0,1;
    double angle=M_PI/6;
    Matrix3d ta,tr;
    ta= AngleAxisd(angle, A.col(1))
    ,tr= AngleAxisd(angle, A.col(2));
    std::cout<<"ta:\n"<<ta<<"\n";
    std::cout<<"tr:\n"<<tr<<"\n";
    std::cout<<"t ta*tr:\n"<<tr*ta<<"\n";

      Bone l1,l2,l3;
      l1.setOrigin();
      Link g(&l1,&l2);
      l2.print();
      g.setAngle(M_PI/6);
      l2.print();

      g.setRote(M_PI/6*5);
      l2.print();
      Link g2(&l2,&l3);

      g.setRote(M_PI/6*3);
      g.setRote(M_PI/6*5);
      l2.print();
      cout<<"l3:";
      l3.print();
      g2.setAngle(M_PI/6);
      l3.print();
      g.setAngle(M_PI/3);
      g.setAngle(M_PI/6);
      g2.cal();
      l3.print();
      l3;

        tail:-11.8301 6.83013 13.6603
      Vector3f v(0,0,1);
      Vector3f unit;
      Matrix3f T;
      T=AngleAxisf(M_PI/6, Vector3f::UnitX()) *
              AngleAxisf(0.0*M_PI,  Vector3f::UnitY())
              * AngleAxisf(0.0*M_PI, Vector3f::UnitZ());;
      cout<<v<<endl<<"T:"<<T<<endl;

      cout<<"transform:T*v"<<endl<<T*v;*/

