#ifndef TYPEDEF_H
#define TYPEDEF_H

#include <eigen3/Eigen/Dense>
#include <vector>
#include <iostream>
#include <string>


#include "bone.h"
#include "link.h"

template <typename T>
class Tree{
protected:
    int num;
public:
    std::vector<Tree*> children;
    T value;
    Tree(T v){
        value=v;
        num=1;
    }
    Tree(){
        value=0;num=1;
    }
    ~Tree(){
        for(unsigned int i=0;i<children.size();i++){
            delete children[i];
        }
        children.clear();
    }
    int size(){
    return num;
    }

    void addChild(T v){
        num++;
        children.push_back(new Tree(v));
    }
    void addChild(Tree* v){
        num+=v->size();
        children.push_back((v));
    }
    bool end(){
        return children.size()==0;
    }

    bool callChildren(){
        return 1;
    }
    T& operator[](int index){

        if(index==0)
            return value;
        index-=1;
        for(unsigned int i=0;i<children.size();i++){
            if(index<children[i])
                return *children[i][index];

            index-=children[i]->size();

        }
    }

    void print(int j){
        for(unsigned int i=0;i<children.size();i++){
            children[i]->print(j+1);
        }

        std::string t;
         for(int i=0;i<j;i++){
             t+=" ";
         }
        std::cout<<t<<j<<"\n";

    }

};

const int Screan_size=3000;
const int Screan_x=300;
const int Screan_y=400;

extern Matrix3d refer_gesture;
extern Vector3d refer_pos;
void viewPort(const Vector3d& v_t,int &x,int&y);

#endif // TYPEDEF_H
