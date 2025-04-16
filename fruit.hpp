//Hanna Zipser
#include <iostream>
using namespace std;

class BRANCH_CLASS;

class FRUIT_CLASS{
    unsigned int waga;
    unsigned int dlugosc;
    FRUIT_CLASS* next;
    BRANCH_CLASS* galaz;

public:
    FRUIT_CLASS(BRANCH_CLASS* galaz, int dlugosc);
    FRUIT_CLASS();
    FRUIT_CLASS(const FRUIT_CLASS & doSkopiowania, BRANCH_CLASS* galaz);
    FRUIT_CLASS(const FRUIT_CLASS & doSkopiowania);
    ~FRUIT_CLASS();
    unsigned int getLength ( void );
    unsigned int getWeight ( void );
    void growthFruit ( void );
    void fadeFruit ( void );
    void pluckFruit ( void );
    BRANCH_CLASS* getBranchPointer ( void );

    FRUIT_CLASS* getNext();
    void setParent(BRANCH_CLASS* galaz);
    void setNext(FRUIT_CLASS* owoc);
    void wyswietlOwoc();

};
