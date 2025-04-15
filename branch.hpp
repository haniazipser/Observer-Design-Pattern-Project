//Hanna Zipser
#include <iostream>

using namespace std;
class FRUIT_CLASS;
class TREE_CLASS;
class BRANCH_CLASS{
    unsigned int dlugosc;
    unsigned int ileOwocow;
    unsigned int wagaOwocow;
    unsigned int wysokosc;
    BRANCH_CLASS* next;
    FRUIT_CLASS* pierwszyOwoc;
    TREE_CLASS* drzewo;

public:
    BRANCH_CLASS (TREE_CLASS* drzewo, int wysokosc);
    BRANCH_CLASS();
    BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania, TREE_CLASS* drzewo, unsigned int wysokosc);
    BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania, TREE_CLASS* drzewo);
    BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania);
    ~BRANCH_CLASS();

    unsigned int getFruitsTotal ( void );

    unsigned int getWeightsTotal ( void );

    unsigned int getHeight ( void );

    unsigned int getLength ( void );
    void growthBranch ( void );
    void fadeBranch ( void );

    void harvestBranch ( unsigned int waga);

    void cutBranch ( unsigned int dlugosc);

    FRUIT_CLASS* getFruitPointer (unsigned int dlugosc);
    TREE_CLASS* getTreePointer();


    BRANCH_CLASS* getNext();
    void setNext(BRANCH_CLASS* galaz);
    void zmianaWagi(int wzrost);
    void zmianaIlosciOwocow(int ilosc);
    void displayAll();
    void setParent(TREE_CLASS* drzewo);

};
