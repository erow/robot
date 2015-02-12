#include "pendulum.h"

Pendulum::Pendulum()
{
    for(int i=0;i<8;i++){
        bones.push_back(new Bone);
        bones[i]->setSign(i);

    }
    bones[0]->setOrigin();

    searchTree.value=new Link(bones[0],bones[1]);
    ModelTree * t;

    t=searchTree.connect(bones[2]);
    t->connect(bones[3]);
    t=searchTree.connect(bones[4]);
    t->connect(bones[5]);
    weight=50*8+20*5;
}
