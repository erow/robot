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
    typedef void (* Fun_tree)(Tree*);
    //std::vector<Tree*> children;
    Tree* child;
    Tree* brother;
    T value;
    Tree(T v){
        value=v;
        num=1;
        child=0;
        brother=0;
    }
    Tree(){
        value=0;num=1;
        child=0;
        brother=0;
    }
    ~Tree(){
        /*for(unsigned int i=0;i<children.size();i++){
            delete children[i];
        }
        children.clear();*/
        if(brother)
        delete brother;
        if(child)
        delete child;
        child=0;
        brother=0;
    }
    int size(){
    return num;
    }

    void addChild(T v){
        num++;
        //children.push_back(new Tree(v));
        if(child){
        child->addBrother(v);
        }else{
        child=new Tree(v);
        }
    }
    void addBrother(T v){
        if(brother)
            brother->addBrother(v);
        else
            brother=new Tree(v);
    }
    void addChild(Tree* v){
        num+=v->size();
        //children.push_back((v));
        if(child){
        child->addBrother(v);
        }else{
        child=(v);
        }
    }
    void addBrother(Tree* v){
        Tree* p=brother;
        while(p!=0){
        p=p->brother;
        }
        brother=v;
    }
    bool end(){
        return num==0;
    }

    bool callChildren(){
        return 1;
    }
    /*T& operator[](int index){

        if(index==0)
            return value;
        index-=1;
        for(unsigned int i=0;i<children.size();i++){
            if(index<children[i])
                return *children[i][index];

            index-=children[i]->size();

        }
    }*/
    void call(Fun_tree t){
        t(this);
        if(child)
            child->call(t);
        if(brother)
            brother->call(t);
    }
    void print(int j){
/*
        for(unsigned int i=0;i<children.size();i++){
            children[i]->print(j+1);
        }
*/
        std::string t;
         for(int i=0;i<j;i++){
             t+=" ";
         }
        std::cout<<t<<j<<"\n";

    }

};

const int Screan_size=3000;
const int Screan_x=300;
const int Screan_y=250;

extern Matrix3d refer_gesture;
extern Vector3d refer_pos;
void viewPort(const Vector3d& v_t,int &x,int&y);

#endif // TYPEDEF_H
