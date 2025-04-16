//Hanna Zipser
#include <iostream>
#include "branch.hpp"
#include "fruit.hpp"
#include "tree.hpp"
using namespace std;

    BRANCH_CLASS::BRANCH_CLASS(TREE_CLASS* drzewo, int wysokosc){//kontruktor
     (*drzewo).zmianaIlosciGalezi(1);
      dlugosc = 0;
      ileOwocow = 0;
      wagaOwocow = 0;
      (*this).wysokosc = wysokosc;
      (*this).drzewo = drzewo;
      pierwszyOwoc = NULL;
      next = NULL;
    }

    BRANCH_CLASS::BRANCH_CLASS(){
      dlugosc = 0;
      ileOwocow = 0;
      wagaOwocow = 0;
      wysokosc = 0;
      drzewo = NULL;
      pierwszyOwoc = NULL;
      next = NULL;
    }

    BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania, TREE_CLASS* drzewo, unsigned int wysokosc){
        if(drzewo != NULL){
            (*drzewo).zmianaIlosciGalezi(1);
        }
      (*this).dlugosc = doSkopiowania.dlugosc;
      (*this).ileOwocow = 0;
      (*this).wagaOwocow = 0;
      (*this).wysokosc = wysokosc;
      (*this).drzewo = drzewo;
      next = NULL;

      //kopiujemy liste
      FRUIT_CLASS* owoc = doSkopiowania.pierwszyOwoc;
      if (owoc != NULL){//jest co kopiowac
          (*this).pierwszyOwoc = new FRUIT_CLASS(*owoc, this);;
         // cout<<"Pierwszy:"<<(*(*this).pierwszyOwoc).getWeight();
          owoc = (*owoc).getNext();

          FRUIT_CLASS* poprzedni = (*this).pierwszyOwoc;
          while (owoc!=NULL){
            (*poprzedni).setNext(new FRUIT_CLASS(*owoc, this));
            poprzedni = (*poprzedni).getNext();
            owoc = (*owoc).getNext();
          }
      }else{
        (*this).pierwszyOwoc = NULL;
      }
    }

    BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania){
      (*this).dlugosc = doSkopiowania.dlugosc;
      (*this).ileOwocow = 0;
      (*this).wagaOwocow = 0;
      (*this).wysokosc = doSkopiowania.wysokosc;
      (*this).drzewo = doSkopiowania.drzewo;
      if(drzewo != NULL){
         (*drzewo).zmianaIlosciGalezi(1);
      }
      next = NULL;

      //kopiujemy liste
      FRUIT_CLASS* owoc = doSkopiowania.pierwszyOwoc;
      if (owoc != NULL){//jest co kopiowac
          FRUIT_CLASS* kopia = new FRUIT_CLASS(*owoc, this);
          (*this).pierwszyOwoc = kopia;
          owoc = (*owoc).getNext();

          FRUIT_CLASS* poprzedni = kopia;
          while (owoc!=NULL){
            kopia = new FRUIT_CLASS(*owoc, this);
            (*poprzedni).setNext(kopia);
            poprzedni = kopia;
            owoc = (*owoc).getNext();
          }
      }else{
        (*this).pierwszyOwoc = NULL;
      }
    }

    BRANCH_CLASS::BRANCH_CLASS(const BRANCH_CLASS & doSkopiowania, TREE_CLASS* drzewo){
      (*this).dlugosc = doSkopiowania.dlugosc;
      (*this).ileOwocow = 0;
      (*this).wagaOwocow = 0;
      (*this).wysokosc = doSkopiowania.wysokosc;
      (*this).drzewo = drzewo;
      if(drzewo != NULL){
         (*drzewo).zmianaIlosciGalezi(1);
      }
      next = NULL;

      //kopiujemy liste
      FRUIT_CLASS* owoc = doSkopiowania.pierwszyOwoc;
      if (owoc != NULL){//jest co kopiowac
          FRUIT_CLASS* kopia = new FRUIT_CLASS(*owoc, this);
          (*this).pierwszyOwoc = kopia;
          owoc = (*owoc).getNext();

          FRUIT_CLASS* poprzedni = kopia;
          while (owoc!=NULL){
            kopia = new FRUIT_CLASS(*owoc, this);
            (*poprzedni).setNext(kopia);
            poprzedni = kopia;
            owoc = (*owoc).getNext();
          }
      }else{
        (*this).pierwszyOwoc = NULL;
      }
    }

    BRANCH_CLASS::~BRANCH_CLASS(){
        if(drzewo!=NULL){
            (*drzewo).zmianaIlosciGalezi(-1);
        }
        dlugosc = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        wysokosc = 0;
        next = NULL;
        while (pierwszyOwoc != NULL){
            FRUIT_CLASS* nastepny = (*pierwszyOwoc).getNext();
            delete pierwszyOwoc;
            pierwszyOwoc = nastepny;
        }
        drzewo = NULL;
    }

    unsigned int BRANCH_CLASS:: getFruitsTotal ( void ){
        return ileOwocow;
    }

    unsigned int BRANCH_CLASS::getWeightsTotal ( void ){
        return wagaOwocow;
    }

    unsigned int BRANCH_CLASS::getHeight ( void ){
        return wysokosc;
    }

    unsigned int BRANCH_CLASS::getLength ( void ){
        return dlugosc;
    }
    void BRANCH_CLASS::growthBranch ( void ){
        dlugosc++;
        FRUIT_CLASS* owoc = pierwszyOwoc;
        if (owoc!= NULL){
            while ((*owoc).getNext()!=NULL){
                (*owoc).growthFruit();
                owoc = (*owoc).getNext();
            }
            (*owoc).growthFruit();

            if (dlugosc%2==0 && dlugosc > 0){
                FRUIT_CLASS* nowyOwoc = new FRUIT_CLASS(this, dlugosc);
                (*owoc).setNext(nowyOwoc);
            }
        }else{
            if (dlugosc%2==0 && dlugosc > 0){
                FRUIT_CLASS* nowyOwoc = new FRUIT_CLASS(this, dlugosc);
                pierwszyOwoc = nowyOwoc;
            }
        }
    }

    void BRANCH_CLASS:: fadeBranch ( void ){
        if (dlugosc != 0){
            dlugosc--;
        }
        FRUIT_CLASS* owoc = pierwszyOwoc;
        FRUIT_CLASS* nowyOstatni = NULL;
        if (owoc != NULL){
            while (owoc != NULL && (*owoc).getLength() <= dlugosc){
                (*owoc).fadeFruit();
                nowyOstatni = owoc;
                owoc = (*owoc).getNext();
            }
            if (owoc != NULL){
                delete owoc;
                owoc = NULL;
                if (nowyOstatni!=NULL){//nie usuwamy ostatniego owocu
                    (*nowyOstatni).setNext(NULL);
                }else{
                    pierwszyOwoc = NULL;
                }
            }
        }
    }

     void BRANCH_CLASS::harvestBranch ( unsigned int waga){
         FRUIT_CLASS* owoc = pierwszyOwoc;
         while (owoc != NULL){
            if ((*owoc).getWeight() >= waga){
                (*owoc).pluckFruit();
            }
            owoc = (*owoc).getNext();
        }
     }

      void BRANCH_CLASS:: cutBranch ( unsigned int dlugosc){
          if (dlugosc < (*this).dlugosc){
              (*this).dlugosc = dlugosc;
                FRUIT_CLASS* owoc = pierwszyOwoc;
                FRUIT_CLASS* nowyOstatni = NULL;
                while (owoc != NULL && (*owoc).getLength() <= dlugosc){
                    nowyOstatni = owoc;
                    owoc = (*owoc).getNext();
                }
                if (nowyOstatni!=NULL){
                    (*nowyOstatni).setNext(NULL);
                }else{
                    pierwszyOwoc = NULL;
                }
                while (owoc != NULL){
                    FRUIT_CLASS* nastepny = (*owoc).getNext();
                    delete owoc;
                    owoc = nastepny;
                }
          }
      }

      FRUIT_CLASS* BRANCH_CLASS:: getFruitPointer (unsigned int dlugosc){
        FRUIT_CLASS* owoc = pierwszyOwoc;
        while (owoc != NULL){
            if ((*owoc).getLength() == dlugosc){
                return owoc;
            } else if ((*owoc).getLength() > dlugosc){
                return NULL;
            }
            owoc = (*owoc).getNext();
        }
        return NULL;
      }

      TREE_CLASS* BRANCH_CLASS::getTreePointer(){
        return drzewo;
      }

    BRANCH_CLASS* BRANCH_CLASS::getNext(){
        return next;
    }
    void BRANCH_CLASS::setNext(BRANCH_CLASS* galaz){
        next = galaz;
    }

    void BRANCH_CLASS::zmianaWagi(int wzrost){
        wagaOwocow += wzrost;
        if (drzewo!= NULL){
            (*drzewo).zmianaWagi(wzrost);
        }
    }

    void BRANCH_CLASS::zmianaIlosciOwocow(int ilosc){
        ileOwocow += ilosc;
        if (drzewo!= NULL){
            (*drzewo).zmianaIlosciOwocow(ilosc);
        }
    }

    void BRANCH_CLASS::setParent(TREE_CLASS* drzewo){
        (*this).drzewo = drzewo;
    }

    void BRANCH_CLASS::displayAll(){
         std::cout << "-----fruit_count:" << getFruitsTotal() << " ";
        std::cout << "weights:" << getWeightsTotal() << std::endl;
        std::cout << "length:" << dlugosc << std::endl;
        int max = getFruitsTotal(), i = 2;
        if (max>0) std::cout << "-----fruits: \n";
        while (i <= 2*max){
            FRUIT_CLASS * fruit = getFruitPointer(i);
            if (fruit != NULL) {
                std:: cout << "       *fruit at " << i << std::endl;
                std::cout <<"       *length: " << fruit->getLength() << " weight: "<< fruit->getWeight() << std::endl;}
            i+=2;
        }
    }

