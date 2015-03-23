#include <iostream>
#include <QtGui/QApplication>
#include <QtGui>
#include "mainwindow.h"
#include "TYPEDEF.H"
#include "bone.h"
#include "link.h"
#include "pendulum.h"
using namespace std;
class QApplication;
int main(int argc, char *argv[])
{
    cout<<"start\n";
    QApplication a( argc, argv);
    MainWindow w;

   // QPushButton w;
    w.show();
    return  a.exec();
}
Matrix3d refer_gesture;
Vector3d refer_pos;
void viewPort(const Vector3d& v_t,int &x,int&y){
   Matrix3d p0,t;
   p0<<1,0,0, 0,1,0, 0,0,1;
   Vector3d v,tv;

   t=refer_gesture*p0.adjoint();
   v=v_t- refer_pos;
   tv=t.adjoint()*v;
   if(tv(0)<=0)
   {
    x=y=999999;
   }

   else{
       x=atan2(tv(1),tv(0))*Screan_size;
       y=atan2(tv(2),tv(0))*Screan_size;
   }
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

