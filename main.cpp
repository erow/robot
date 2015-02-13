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
    QApplication a( argc, argv);
    MainWindow w;

    w.show();
    return  a.exec();
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

