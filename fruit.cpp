//Hanna Zipser
#include <iostream>
#include "fruit.hpp"
#include "branch.hpp"
using namespace std;
    FRUIT_CLASS::FRUIT_CLASS(BRANCH_CLASS* galaz, int dlugosc){//kontruktor
        waga = 0;
        (*this).dlugosc = dlugosc;
        next = NULL;
        (*this).galaz = galaz;
        (*galaz).zmianaIlosciOwocow(1);
    }

     FRUIT_CLASS::FRUIT_CLASS(){
        waga = 0;
        dlugosc = 0;
        next = NULL;
        galaz = NULL;
     }

     FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS & doSkopiowania, BRANCH_CLASS* galaz){
        (*this).waga = doSkopiowania.waga;
        (*this).dlugosc = doSkopiowania.dlugosc;
        next = NULL;
        (*this).galaz = galaz;
        if(galaz != NULL){
            (*galaz).zmianaIlosciOwocow(1);
            (*galaz).zmianaWagi(waga);
        }
     }

     FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS & doSkopiowania){
        (*this).waga = doSkopiowania.waga;
        (*this).dlugosc = doSkopiowania.dlugosc;
         next = NULL;
        (*this).galaz = doSkopiowania.galaz;
        if(galaz != NULL){
            (*galaz).zmianaIlosciOwocow(1);
            (*galaz).zmianaWagi(waga);
        }
     }

    FRUIT_CLASS::~FRUIT_CLASS(){//destruktor
        if(galaz != NULL){
            (*galaz).zmianaWagi(-waga);
            (*galaz).zmianaIlosciOwocow(-1);
        }
        waga = 0;
        dlugosc = 0;
        next = NULL;
        galaz = NULL;
    }


    unsigned int FRUIT_CLASS:: getLength ( void ){
        return dlugosc;
    }
    unsigned int FRUIT_CLASS::getWeight ( void ){
        return waga;
    }
    void FRUIT_CLASS::growthFruit ( void ){
        waga++;
        if (galaz!=NULL){
            (*galaz).zmianaWagi(1);
        }
    }
    void FRUIT_CLASS::fadeFruit ( void ){
        if(waga != 0){
            waga--;
            if(galaz != NULL){
                (*galaz).zmianaWagi(-1);
            }
        }
    }
    void FRUIT_CLASS::pluckFruit ( void ){
        if(galaz != NULL){
        (*galaz).zmianaWagi(-waga);
        }
        waga=0;
    }
    BRANCH_CLASS* FRUIT_CLASS::getBranchPointer ( void ){
        return galaz;
    }
    FRUIT_CLASS* FRUIT_CLASS::getNext(){
        return next;
    }
    void FRUIT_CLASS::setNext(FRUIT_CLASS* owoc){
        next = owoc;
    }

     void FRUIT_CLASS::setParent(BRANCH_CLASS* galaz){
        (*this).galaz= galaz;
     }

