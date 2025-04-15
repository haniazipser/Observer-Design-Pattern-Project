//Hanna Zipser
#include <iostream>
#include "garden.hpp"
#include "tree.hpp"
#include "branch.hpp"
#include "fruit.hpp"
using namespace std;

int main()
{       GARDEN_CLASS g;
    for(int i=0; i != 8; i++) g.plantTree();
    for(int i=0; i != 8; i++) g.growthGarden();
    g.extractTree(1);
    g.extractTree(2);
    g.extractTree(5);
    g.extractTree(14);
    std::cout<<g.getTreePointer(14)<<std::endl;
//    g.display();
    g.cloneTree(5);
//    g.display();
    g.cloneTree(0);
    g.cloneTree(3);
    g.cloneTree(7);
    g.cloneTree(500);
//    g.display();
    g.plantTree();
    g.plantTree();
    g.plantTree();
//    g.display();
    for(int i=0; i != 8; i++) g.cloneTree(i);
//    g.display();
    for(int i=0; i != 8; i++) g.extractTree(i);
//    g.display();
    for(int i=8; i != 25; i++) g.extractTree(i);
//    g.display();
    g.cloneTree(0);
    g.getTreePointer(100);
//    g.display();
    g.plantTree();
//    g.display();
    g.cloneTree(0);
    g.displayAll();
    g.cloneTree(0);
    g.displayAll();
    g.extractTree(0);
    g.extractTree(1);
    g.extractTree(2);
    g.displayAll();
    g.plantTree();
    g.plantTree();
    g.plantTree();
    g.getTreePointer(2)->growthTree();
    g.getTreePointer(2)->growthTree();
    g.getTreePointer(2)->growthTree();
    g.getTreePointer(2)->growthTree();
    g.getTreePointer(2)->growthTree();
    g.cloneTree(2);
    g.extractTree(2);
    g.displayAll();
    g.cloneTree(3);
    g.displayAll();
    for(int i=0; i!=20; i++)g.getTreePointer(2)->growthTree();
    for(int i=0; i!=10; i++)g.getTreePointer(3)->growthTree();
    g.growthGarden();
    g.displayAll();
    g.extractTree(2);
    g.displayAll();
    std::cout<<g.getTreePointer(2)<<std::endl;
    for(int i=0; i!=20; i++) g.extractTree(i);
    g.displayAll();
    g.plantTree();
    for(int i=0; i!=10; i++) g.cloneTree(i);
    g.displayAll();
    g.growthGarden();
    g.growthGarden();
    g.growthGarden();
    g.getTreePointer(5)->growthTree();
    g.displayAll();
    for(int i=0; i!=10; i++) g.cloneTree(i);
    g.getTreePointer(5)->growthTree();
    for(int i=20; i!=-1; i--) g.extractTree(i);
    g.displayAll();

    return 0;
}
