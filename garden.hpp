//Hanna Zipser
#include <iostream>
using namespace std;
class TREE_CLASS;
class GARDEN_CLASS{
    unsigned int ileDrzew;
    unsigned int ileGalezi;
    unsigned int ileOwocow;
    unsigned int wagaOwocow;
    unsigned int dostepneId;
    TREE_CLASS* pierwszeDrzewo;
    TREE_CLASS* ostatnieDrzewo;
    public:
    GARDEN_CLASS();
    ~GARDEN_CLASS();
    unsigned int getTreesTotal();
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    void plantTree();
    void extractTree(unsigned int id);
    void growthGarden();
    void fadeGarden();
    void harvestGarden(unsigned int waga);
    TREE_CLASS* getTreePointer(unsigned int id);
    void cloneTree(unsigned int id);

    unsigned int getFreeId();
    void freeId(unsigned int id);
    void zmianaWagi (int zmiana);
    void zmianaIlosciOwocow(int ilosc);
    void zmianaIlosciGalezi(int ilosc);
    void zmianaIlosciDrzew(int ilosc);
    void displayAll();
};
