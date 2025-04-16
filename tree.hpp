//Hanna Zipser
#include <iostream>

class GARDEN_CLASS;
class BRANCH_CLASS;
using namespace std;

class TREE_CLASS{;
    unsigned int id;
    unsigned int wysokosc;
    unsigned int ileGalezi;
    unsigned int ileOwocow;
    unsigned int wagaOwocow;
    TREE_CLASS* next;
    TREE_CLASS* prev;
    BRANCH_CLASS* pierwszaGalaz;
    GARDEN_CLASS* ogrod;
public:
    TREE_CLASS(GARDEN_CLASS* ogrod, unsigned int id);
    TREE_CLASS(const TREE_CLASS & doSkopiowania,GARDEN_CLASS* ogrod, unsigned int id);
    TREE_CLASS(const TREE_CLASS & doSkopiowania);
     TREE_CLASS();
    ~TREE_CLASS();

    unsigned int getBranchesTotal ( void );
    unsigned int getFruitsTotal ( void );
    unsigned int getWeightsTotal ( void );
    unsigned int getNumber ( void );
    unsigned int getHeight ( void );

    void growthTree();

    void fadeTree();

    void harvestTree(unsigned int waga);

    void cutTree (unsigned int wysokosc);
    void cloneBranch (BRANCH_CLASS* id);

    GARDEN_CLASS* getGardenPointer ( void );
    BRANCH_CLASS* getBranchPointer ( unsigned int w);

    TREE_CLASS* getNext();
    void setNext(TREE_CLASS* drzewo);
    TREE_CLASS* getPrev();
    void setPrev(TREE_CLASS* drzewo);
    void zmianaWagi(int wzrost);
    void zmianaIlosciOwocow(int ilosc);
    void zmianaIlosciGalezi(int ilosc);
    void setParent(GARDEN_CLASS* ogrod);
    void displayAll();
};
