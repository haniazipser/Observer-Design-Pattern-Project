//Hanna Zipser
#include <iostream>
#include "tree.hpp"
#include "garden.hpp"
#include "branch.hpp"
using namespace std;

    TREE_CLASS::TREE_CLASS(GARDEN_CLASS* ogrod, unsigned int id){
        (*this).ogrod = ogrod;
       (*this).id = id;
       (*ogrod).zmianaIlosciDrzew(1);
        wysokosc = 0;
        ileGalezi = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        next = NULL;
        prev = NULL;
        pierwszaGalaz = NULL;
    }

    TREE_CLASS::TREE_CLASS(){
        ogrod = NULL;
        id = 0;
        wysokosc = 0;
        ileGalezi = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        next = NULL;
        prev = NULL;
        pierwszaGalaz = NULL;
    }

    TREE_CLASS::TREE_CLASS(const TREE_CLASS & doSkopiowania, GARDEN_CLASS* ogrod, unsigned int id){
        (*this).ogrod = ogrod;
        if (ogrod != NULL){
            (*ogrod).zmianaIlosciDrzew(1);
        }
        (*this).id = id;
        (*this).wysokosc = doSkopiowania.wysokosc;
        (*this).ileGalezi = 0;//doSkopiowania.ileGalezi;
        (*this).ileOwocow = 0;//doSkopiowania.ileOwocow;
        wagaOwocow = 0;
        (*this).wagaOwocow = 0;//doSkopiowania.wagaOwocow;
        next = NULL;
        prev = NULL;

        //kopiujemy liste
      BRANCH_CLASS* galaz = doSkopiowania.pierwszaGalaz;
      if (galaz != NULL){//jest co kopiowac
         // cout<<"wywolanie na wys"<< (*galaz).getHeight()<<endl;
          BRANCH_CLASS* kopia = new BRANCH_CLASS(*galaz, this, (*galaz).getHeight());
          (*this).pierwszaGalaz = kopia;
         // cout<<"Pierwszy:";
          galaz = (*galaz).getNext();

          BRANCH_CLASS* poprzedni = kopia;
          while (galaz!=NULL){
             //cout<<"wywolanie na wys"<< (*galaz).getHeight()<<endl;
            kopia = new BRANCH_CLASS(*galaz, this, getHeight());
            (*poprzedni).setNext(kopia);
            //cout<<"poprzedni :"<<endl;
            //(*poprzedni).displayAll();
            //cout<<"polaczony z :"<<endl;
            //(*kopia).displayAll();
            poprzedni = kopia;
            galaz = (*galaz).getNext();
          }
          //cout<<"ostatni:"<<endl;
          //(*(*pierwszaGalaz).getNext()).displayAll();
      }else{
        (*this).pierwszaGalaz = NULL;
      }
    }

     TREE_CLASS::TREE_CLASS(const TREE_CLASS & doSkopiowania){
        (*this).ogrod = doSkopiowania.ogrod;
        if (ogrod != NULL){
            (*ogrod).zmianaIlosciDrzew(1);
        }
        (*this).id = doSkopiowania.id;
        (*this).wysokosc = doSkopiowania.wysokosc;
        (*this).ileGalezi = 0;//doSkopiowania.ileGalezi;
        (*this).ileOwocow = 0;//doSkopiowania.ileOwocow;
        (*this).wagaOwocow = 0;//doSkopiowania.wagaOwocow;
        next = NULL;
        prev = NULL;

      BRANCH_CLASS* galaz = doSkopiowania.pierwszaGalaz;
      if (galaz != NULL){//jest co kopiowac
          BRANCH_CLASS* kopia = new BRANCH_CLASS(*galaz, this);
         (*this).pierwszaGalaz = kopia;
          galaz = (*galaz).getNext();

          BRANCH_CLASS* poprzedni = (*this).pierwszaGalaz;
          while (galaz!=NULL){
            BRANCH_CLASS* kopia1 = new BRANCH_CLASS(*galaz, this);
            (*poprzedni).setNext(kopia1);
            poprzedni = (*poprzedni).getNext();
            galaz = (*galaz).getNext();
          }
      }else{
        (*this).pierwszaGalaz = NULL;
      }
    }


     TREE_CLASS::~TREE_CLASS(){
         if(ogrod != NULL){
            (*ogrod).zmianaIlosciDrzew(-1);
         }
        id = 0;
        wysokosc = 0;
        ileGalezi = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        next = NULL;
        prev = NULL;
        while (pierwszaGalaz != NULL){
            BRANCH_CLASS* nastepny = (*pierwszaGalaz).getNext();
            delete pierwszaGalaz;
            pierwszaGalaz = nastepny;

        }
        ogrod = NULL;
    }

    unsigned int TREE_CLASS:: getBranchesTotal ( void ){
        return ileGalezi;
    }
    unsigned int  TREE_CLASS::getFruitsTotal ( void ){
        return ileOwocow;
    }
    unsigned int  TREE_CLASS::getWeightsTotal ( void ){
        return wagaOwocow;
    }
    unsigned int  TREE_CLASS::getNumber ( void ){
        return id;
    }
    unsigned int  TREE_CLASS::getHeight ( void ){
        return wysokosc;
    }

    void  TREE_CLASS::growthTree(){
        wysokosc++;
        BRANCH_CLASS* galaz = pierwszaGalaz;
        if (galaz != NULL){//nie pierwsze
            while ((*galaz).getNext() != NULL){
                (*galaz).growthBranch();
                galaz = (*galaz).getNext();
            }
            (*galaz).growthBranch();

            if (wysokosc % 3 == 0 && wysokosc > 0){
                BRANCH_CLASS* nowaGalaz = new BRANCH_CLASS(this, wysokosc);
                (*galaz).setNext(nowaGalaz);
            }
        }else{
            if (wysokosc % 3 == 0 && wysokosc > 0){
                BRANCH_CLASS* nowaGalaz = new BRANCH_CLASS(this, wysokosc);
                pierwszaGalaz = nowaGalaz;
            }
        }
    }

    void  TREE_CLASS::fadeTree(){
        if (wysokosc != 0){
            wysokosc--;
        }
        BRANCH_CLASS* galaz = pierwszaGalaz;
        BRANCH_CLASS* nowyOstatni = NULL;
        if (galaz != NULL){

            while (galaz != NULL && (*galaz).getHeight() <= wysokosc){
                (*galaz).fadeBranch();
                nowyOstatni = galaz;
                galaz = (*galaz).getNext();
            }
            if (galaz != NULL){
                delete galaz;
                galaz = NULL;
                if (nowyOstatni!=NULL){//nie usunelismy ostatniej galezi
                    (*nowyOstatni).setNext(NULL);
                }else{
                    pierwszaGalaz = NULL;
                }
            }
        }
    }

    void TREE_CLASS::harvestTree(unsigned int waga){
        BRANCH_CLASS* galaz = pierwszaGalaz;
        while (galaz != NULL){
            (*galaz).harvestBranch(waga);
            galaz = (*galaz).getNext();
        }
    }

     void  TREE_CLASS::cutTree (unsigned int wysokosc){

        if (wysokosc < (*this).wysokosc){
               (*this).wysokosc = wysokosc;
                BRANCH_CLASS* galaz = pierwszaGalaz;
                BRANCH_CLASS* nowyOstatni = NULL;
                while (galaz != NULL && (*galaz).getHeight() <= wysokosc){
                    nowyOstatni = galaz;
                    galaz = (*galaz).getNext();
                }
                if(nowyOstatni!=NULL){
                    (*nowyOstatni).setNext(NULL);
                }else{
                    pierwszaGalaz = NULL;
                }
                while (galaz != NULL){
                    BRANCH_CLASS* nastepny = (*galaz).getNext();
                    delete galaz;
                    galaz = nastepny;
                }
          }
     }

     ///TO DO CLONE BRANCH
     void TREE_CLASS::cloneBranch(BRANCH_CLASS* doSkopiowania){//pierwszy/ostatni
         BRANCH_CLASS* galaz = pierwszaGalaz;
         BRANCH_CLASS* poprzedni;
         if (galaz != NULL){
            if ((*galaz).getLength()==0){//pierwsza galaz
                BRANCH_CLASS* kopia = new BRANCH_CLASS (*doSkopiowania, this, (*galaz).getHeight());
                pierwszaGalaz = kopia;
                (*kopia).setNext((*galaz).getNext());
                delete galaz;
            }else{

                while(galaz != NULL && (*galaz).getLength()!=0){
                    int temp = (*galaz).getLength();
                    poprzedni = galaz;
                    galaz = (*galaz).getNext();
                }
                if (galaz != NULL){//mamy dlg = 0
                    BRANCH_CLASS* kopia = new BRANCH_CLASS (*doSkopiowania, this, (*galaz).getHeight());
                    (*poprzedni).setNext(kopia);
                   // cout<<"poprzedni:"<<(*poprzedni).getHeight()<<endl;
                    //cout<<"podloczony na next:"<<(*(*poprzedni).getNext()).getHeight()<<endl;
                    (*kopia).setNext((*galaz).getNext());
                    delete galaz;
                }
            }
         }
     }

     GARDEN_CLASS*  TREE_CLASS::getGardenPointer ( void ){
        return ogrod;
     }
     BRANCH_CLASS*  TREE_CLASS::getBranchPointer ( unsigned int w){
        BRANCH_CLASS* galaz = pierwszaGalaz;
        while (galaz != NULL){
            if ((*galaz).getHeight() == w){
                return galaz;
            } else if ((*galaz).getHeight() > w){
                return NULL;
            }
            galaz = (*galaz).getNext();
        }
        return NULL;
     }

    TREE_CLASS* TREE_CLASS::getNext(){
        return next;
    }
    void TREE_CLASS::setNext(TREE_CLASS* drzewo){
        next = drzewo;
    }
    TREE_CLASS* TREE_CLASS::getPrev(){
        return prev;
    }
    void TREE_CLASS::setPrev(TREE_CLASS* drzewo){
        prev = drzewo;
    }

    void TREE_CLASS::zmianaWagi(int wzrost){
        wagaOwocow += wzrost;
        if(ogrod != NULL){
            (*ogrod).zmianaWagi(wzrost);
        }
     }
     void TREE_CLASS::zmianaIlosciOwocow(int ilosc){
        ileOwocow += ilosc;
        if(ogrod != NULL){
            (*ogrod).zmianaIlosciOwocow(ilosc);
        }
     }
     void TREE_CLASS::zmianaIlosciGalezi(int ilosc){
        ileGalezi += ilosc;
        if(ogrod != NULL){
            (*ogrod).zmianaIlosciGalezi(ilosc);
        }
     }

     void TREE_CLASS::setParent(GARDEN_CLASS* ogrod){
        (*this).ogrod = ogrod;
     }

     void TREE_CLASS::displayAll(){
        /*
        cout<<"D"<<getNumber()<<endl;
        cout<<" ilosc galezi:"<<ileGalezi<<endl;
        cout<<" ilosc owocow:"<<ileOwocow<<endl;
        cout<<" waga owocow:"<<wagaOwocow<<endl;
        BRANCH_CLASS* galaz = pierwszaGalaz;
        while (galaz != NULL){
            (*galaz).wyswietlGalaz();
            galaz= (*galaz).getNext();
        }
        cout<<endl;*/
        std::cout << ">>fruit_count:" << getFruitsTotal() << " ";
    std::cout << "branch_count:" << getBranchesTotal() << " ";
    std::cout << "weights:" << getWeightsTotal() << std::endl;
    std::cout << "height:" << wysokosc << std::endl;
    int max = getBranchesTotal(), i = 3;
    if (max>0) std::cout << ">>branches: \n";
    while (i <= 3*max){
        BRANCH_CLASS * branch = getBranchPointer(i);
        if (branch != NULL) {
            std:: cout << "-----branch at " << i << std::endl;
            branch->displayAll();}
        i+=3;
    }
     }


