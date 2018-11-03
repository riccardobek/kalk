#include "modelpolinomio.h"

modelPolinomio::modelPolinomio():poly(0),memory(0),rational(0),monomial(0){}

void modelPolinomio::creaMonomio(string m){
    if(m.length()!=0)
        monomial = new monomio(m);
}

void modelPolinomio::creaRazionale(string r){
    rational = new razionale(r);
}

void modelPolinomio::memorizzaPoly(){
    if(poly){
        memory = new polinomio(*poly);
        poly->clear();
        delete poly;
        poly=0;
    }
}

void modelPolinomio::calcola(){
    if(!poly){poly = new polinomio();}
    if(monomial){
        poly->addMonomio(operation,*monomial);
        delete monomial;
        monomial = 0;
    }
}

void modelPolinomio::setOperazione(const simbolo& o){
    operation=o;
    insertOp=true;
}

void modelPolinomio::resetInsertOp(){
    insertOp=false;
}

bool modelPolinomio::getOperazione() const{
    return insertOp;
}

void modelPolinomio::DEL(){
    if(rational){
        delete rational;
        rational=0;
    }
    insertCirconflesso=false;
}

void modelPolinomio::AC(){
    if(poly){
        poly->clear();
        delete poly;
        poly=0;
    }
    if(rational){
        delete rational;
        rational=0;
    }
    if(monomial){
        delete monomial;
        monomial=0;
    }
    operation=simbolo('+');

    insertOp=false;
    insertCirconflesso=false;
}

string modelPolinomio::getPolinomio() const{
    return poly->toString();
}

string modelPolinomio::calcolaPotenza(string s){
    if(rational){
        try{
            unsigned int var=s.find('^');
            string c=s.substr(var+1,s.length());
            razionale r(c);

            r=razionale::potenza(*rational,r);
            delete rational;
            rational=0;
            return r.toString();
        }
        catch(std::exception e){
            throw errorePotenza();
        }
    }
    return "";
}

string modelPolinomio::sostituzioneX(){
    if(rational){
        razionale  r=poly->sostituisciVariabile(*rational);
        delete rational;
        rational=0;
        poly->clear();
        poly->addMonomio(simbolo('+'),r);
    }

    return poly->toString();
}

string modelPolinomio::derivata(){
    if(poly){
        *poly = poly->getDerivata();
        return poly->toString();
    }
    return "";
}

string modelPolinomio::grado() const{
    if(poly)
        return poly->getGrado().toString();
    return "NaN";
}

bool modelPolinomio::getMemory() const{
    if(memory)
        return true;
    return false;
}

string modelPolinomio::setPolyUMemory(){
    poly = new polinomio(*memory);
    memory->clear();
    if(memory){
        delete memory;
        memory=0;
    }
    return poly->toString();
}

string modelPolinomio::polyOpMemory(){
    if((char)operation=='+'){
        *poly = *poly + *memory;
    }
    else if((char)operation=='-'){
            *poly = *poly - *memory;
    }
    else if(poly->size()==1){
            if((char)operation=='*'){
                *poly = poly->getMonomio_pos(0) * (*memory);
            }
            else if((char)operation==':'){
                *poly = poly->getMonomio_pos(0) / (*memory);
            }
            else
                throw erroreSimbolo();
    }
    else
        throw erroreSimbolo();

    memory->clear();
    if(memory){
        delete memory;
        memory=0;
    }

    return poly->toString();
}

bool modelPolinomio::getCirconflesso() const{
    return insertCirconflesso;
}

void modelPolinomio::setCirconflesso(bool c){
    insertCirconflesso=c;
}


