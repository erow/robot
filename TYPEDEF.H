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
public:
    std::vector<Tree*> children;
    T value;
    Tree(T v){
        value=v;
    }
    Tree(){
        value=0;
    }
    ~Tree(){
        for(unsigned int i=0;i<children.size();i++){
            delete children[i];
        }
        children.clear();
    }

    void addChild(T v){
        children.push_back(new Tree(v));
    }
    void addChild(Tree* v){
        children.push_back((v));
    }
    bool end(){
        return children.size()==0;
    }

    bool callChildren(){
        return 1;
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


#endif // TYPEDEF_H
