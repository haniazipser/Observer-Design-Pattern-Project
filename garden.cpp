//Hanna Zipser
#include <iostream>
#include "garden.hpp"
#include "tree.hpp"
using namespace std;

    GARDEN_CLASS::GARDEN_CLASS(){
        ileDrzew = 0;
        ileGalezi = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        dostepneId = 0;
        pierwszeDrzewo = NULL;
        ostatnieDrzewo = NULL;
    }

    GARDEN_CLASS::~GARDEN_CLASS(){
        ileDrzew = 0;
        ileGalezi = 0;
        ileOwocow = 0;
        wagaOwocow = 0;
        dostepneId = 0;
        while(pierwszeDrzewo!=NULL){
            TREE_CLASS* nastepny = (*pierwszeDrzewo).getNext();
            if (pierwszeDrzewo!=NULL){
                delete pierwszeDrzewo;
            }
            pierwszeDrzewo = nastepny;
        }
        pierwszeDrzewo = NULL;
        ostatnieDrzewo = NULL;
    }

    unsigned int GARDEN_CLASS:: getTreesTotal (void){
        return ileDrzew;
    }
    unsigned int GARDEN_CLASS::getBranchesTotal ( void ){
        return ileGalezi;
    }
    unsigned int GARDEN_CLASS::getFruitsTotal ( void ){
        return ileOwocow;
    }
    unsigned int GARDEN_CLASS::getWeightsTotal ( void ){
        return wagaOwocow;
    }

    void GARDEN_CLASS::plantTree(){
        if(ileDrzew == 0){
            TREE_CLASS* noweDrzewo = new TREE_CLASS(this, 0);
            dostepneId++;
            pierwszeDrzewo = noweDrzewo;
            ostatnieDrzewo = noweDrzewo;
        }else{
            if (ileDrzew == dostepneId){//nie ma dziur
                TREE_CLASS* noweDrzewo = new TREE_CLASS(this, dostepneId);
                dostepneId++;
                (*ostatnieDrzewo).setNext(noweDrzewo);
                (*noweDrzewo).setPrev(ostatnieDrzewo);
                ostatnieDrzewo = noweDrzewo;
            }else{//szukaj dziury
                if ((*pierwszeDrzewo).getNumber()!=0){//dziura na poczatku
                    TREE_CLASS* noweDrzewo = new TREE_CLASS(this, 0);
                    (*noweDrzewo).setNext(pierwszeDrzewo);
                    (*pierwszeDrzewo).setPrev(noweDrzewo);
                    pierwszeDrzewo = noweDrzewo;
                }else{

                TREE_CLASS* drzewo = pierwszeDrzewo;
                while ((*drzewo).getNumber() + 1 == (*(*drzewo).getNext()).getNumber()){
                    drzewo = (*drzewo).getNext();
                }
                TREE_CLASS* noweDrzewo = new TREE_CLASS(this, (*drzewo).getNumber() + 1);
                TREE_CLASS* nastepny = (*drzewo).getNext();
                (*drzewo).setNext(noweDrzewo);
                (*noweDrzewo).setPrev(drzewo);
                (*noweDrzewo).setNext(nastepny);
                (*nastepny).setPrev(noweDrzewo);
                }
            }
        }
    }

    void GARDEN_CLASS::extractTree(unsigned int id){
        TREE_CLASS* drzewo = ostatnieDrzewo;
        while (drzewo != NULL){
            if ((*drzewo).getNumber() == id){
                if (id == dostepneId - 1){//usuwamy ostatnie drzewo
                    if (drzewo == pierwszeDrzewo){//usuwamy jedyne drzewo
                        pierwszeDrzewo = NULL;
                        ostatnieDrzewo = NULL;
                        dostepneId = 0;
                    }else{
                        dostepneId--;
                        ostatnieDrzewo = (*drzewo).getPrev();
                        (*ostatnieDrzewo).setNext(NULL);
                    }
                }else if(drzewo == pierwszeDrzewo){//usuwamy pierwsze dzrewo
                    pierwszeDrzewo = (*drzewo).getNext();
                    (*pierwszeDrzewo).setPrev(NULL);
                }else{
                    TREE_CLASS* poprzedni = (*drzewo).getPrev();
                    TREE_CLASS* nastepny = (*drzewo).getNext();
                    (*poprzedni).setNext(nastepny);
                    (*nastepny).setPrev(poprzedni);
                }
                delete drzewo;
                break;

            } else if ((*drzewo).getNumber() < id){
                break;
            }
            drzewo = (*drzewo).getPrev();
        }
    }

    void GARDEN_CLASS:: growthGarden(){
        TREE_CLASS* drzewo = pierwszeDrzewo;
        while (drzewo!= NULL){
            (*drzewo).growthTree();
            drzewo = (*drzewo).getNext();
        }
    }


    void GARDEN_CLASS:: fadeGarden(){
        TREE_CLASS* drzewo = pierwszeDrzewo;
        while (drzewo!= NULL){
            int temp = (*drzewo).getNumber();
            (*drzewo).fadeTree();
            drzewo = (*drzewo).getNext();
        }
    }

    void GARDEN_CLASS::harvestGarden(unsigned int waga){
        TREE_CLASS* drzewo = pierwszeDrzewo;
        while (drzewo!= NULL){
            (*drzewo).harvestTree(waga);
            drzewo = (*drzewo).getNext();
        }
    }

    TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int id){
        TREE_CLASS* drzewo = pierwszeDrzewo;
        while (drzewo != NULL){
            if ((*drzewo).getNumber() == id){
                return drzewo;
            } else if ((*drzewo).getNumber() > id){
                return NULL;
            }
            drzewo = (*drzewo).getNext();
        }
        return NULL;
    }

    void GARDEN_CLASS::cloneTree(unsigned int id){
        TREE_CLASS* drzewo = pierwszeDrzewo;
        TREE_CLASS* doSkopiowania = NULL;
        while (drzewo != NULL){
            if ((*drzewo).getNumber() == id){
                doSkopiowania = drzewo;
                break;
            }
            drzewo = (*drzewo).getNext();
        }

        if (doSkopiowania!= NULL){
            if (ileDrzew == dostepneId){//nie ma przerw
                TREE_CLASS* noweDrzewo = new TREE_CLASS(*doSkopiowania,this, dostepneId);
                dostepneId++;
                (*ostatnieDrzewo).setNext(noweDrzewo);
                (*noweDrzewo).setPrev(ostatnieDrzewo);
                ostatnieDrzewo = noweDrzewo;
            }else{//szukaj przerwy
                if ((*pierwszeDrzewo).getNumber()!=0){//dziura na poczatku
                    TREE_CLASS* noweDrzewo = new TREE_CLASS(*doSkopiowania,this, 0);
                    (*noweDrzewo).setNext(pierwszeDrzewo);
                    (*pierwszeDrzewo).setPrev(noweDrzewo);
                    pierwszeDrzewo = noweDrzewo;
                }else{

                TREE_CLASS* drzewo = pierwszeDrzewo;
                while ((*drzewo).getNumber() + 1 == (*(*drzewo).getNext()).getNumber()){
                    drzewo = (*drzewo).getNext();
                }
                TREE_CLASS* noweDrzewo = new TREE_CLASS(*doSkopiowania, this, (*drzewo).getNumber() + 1);
                TREE_CLASS* nastepny = (*drzewo).getNext();
                (*drzewo).setNext(noweDrzewo);
                (*noweDrzewo).setPrev(drzewo);
                (*noweDrzewo).setNext(nastepny);
                (*nastepny).setPrev(noweDrzewo);
                }
            }
        }

    }

    void GARDEN_CLASS::zmianaWagi (int wzrost){
        wagaOwocow += wzrost;
    }
    void GARDEN_CLASS::zmianaIlosciOwocow (int ilosc){
        ileOwocow += ilosc;
    }
    void GARDEN_CLASS::zmianaIlosciGalezi (int ilosc){
        ileGalezi += ilosc;
    }
    void GARDEN_CLASS::zmianaIlosciDrzew (int ilosc){
        ileDrzew += ilosc;
    }
    void GARDEN_CLASS:: displayAll(){
        std::cout << "GARDEN:" << std::endl;
        std::cout << "fruit_count:" << getFruitsTotal() << " ";
        std::cout << "tree_count:" << getTreesTotal() << " ";
        std::cout << "branch_count:" << getBranchesTotal() << " ";
        std::cout << "weights:" << getWeightsTotal() << std::endl;
        std::cout << "trees: \n";
        int max = getTreesTotal(), i = 0;
        while (i <= max){
            TREE_CLASS * wood = getTreePointer(i);
            if (wood != NULL) {
                std:: cout << "tree nr " << i << std::endl;
                wood->displayAll();
                std::cout << std::endl;
            }
            i++;
        }
        std::cout << std::endl;
        std::cout << "/ / / / / / / /";
        std::cout << std::endl<< std::endl;
    }
