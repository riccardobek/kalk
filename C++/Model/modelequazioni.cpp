#include "modelequazioni.h"

modelEquazioni::modelEquazioni():sx(0), dx(0), e(0), rational(0), memory(0),
    monomial(0), grado(0), tipo(0){}

void modelEquazioni::AC(){
    if(e){
        delete e;
        e=0;
    }
    if(rational){
        delete rational;
        rational=0;
    }
    if(monomial){
        delete monomial;
        monomial=0;
    }
    if(grado){
        delete grado;
        grado=0;
    }
    if(tipo){
        delete tipo;
        tipo=0;
    }
    if(sx){
        sx->clear();
        delete sx;
        sx=0;
    }
    if(dx){
        dx->clear();
        delete dx;
        dx=0;
    }
    uguale = false;
    insertCirconflesso = false;
    opInserita = false;
    operation = simbolo('+');
}

void modelEquazioni::DEL(){
    if(rational){
        delete rational;
        rational=0;
    }
    insertCirconflesso=false;
}

//per usare la memoria inserire una + o una - e poi premere M quando = è già stato cliccato
void modelEquazioni::memorizza(){
    if(sx){
        memory = new polinomio(*sx);
        sx->clear();
        delete sx;
        sx=0;
    }
    memoryPopulated=true;
}

bool modelEquazioni::getMemoryPopulated() const{
    return memoryPopulated;
}

void modelEquazioni::insertMemoryInPoly(){
    if(memory){
        if(uguale==true)
            dx=new polinomio(*memory);
        else
            sx=new polinomio(*memory);
        memoryPopulated=false;
        memory->clear();
        delete memory;
        memory=0;
    }
}


void modelEquazioni::resetMemory(){
    if(memory){
        memory->clear();
        delete memory;
        memory=0;
    }
    cliccataM=false;
}


void modelEquazioni::setClickM(){
    cliccataM=true;
}

string modelEquazioni::getEquazione() const{
    if(uguale && !e)
        return sx->toString() + " = " + dx->toString();
    else if(!e && sx)
        return sx->toString();
    else if(e)
        return e->getEquazione();
    return "";
}

bool modelEquazioni::getOpInserita() const{
    return opInserita;
}

bool modelEquazioni::getUguale() const{
    return uguale;
}

void modelEquazioni::creaRazionale(string r){
    rational= new razionale(r);
}

void modelEquazioni::inseritoCirconflesso(){ insertCirconflesso=true;}
void modelEquazioni::resetCirconflesso(){insertCirconflesso=false;}
bool modelEquazioni::getCirconflesso() const{ return insertCirconflesso;}

string modelEquazioni::potenzaRazionale(string s){
    if(rational){
        try{
            unsigned int var=s.find('^');
            string c=s.substr(var+1,s.length());
            razionale r(c);

            return razionale::potenza(*rational,r).toString();
        }
        catch(std::exception e){
            throw errorePotenza();
        }
    }
    return "";
}

void modelEquazioni::creaMonomio(string m){
    if(m.length()!=0)
        monomial = new monomio(m);

}

void modelEquazioni::inserisciOperazione(const simbolo& s){
    operation=s;
    opInserita=true;
}


void modelEquazioni::calcolaPolinomi(){
    if(!sx){sx=new polinomio();}
    if(cliccataM && memory){
        if(uguale){
            if((char)operation=='+')
                *dx = *dx + *memory;
            if((char)operation=='-')
                *dx = *dx - *memory;
            if(dx->size()==1){
                if((char)operation=='*'){
                    *dx = dx->getMonomio_pos(0) * (*memory);
                }
                else if((char)operation==':'){
                    *dx = dx->getMonomio_pos(0) / (*memory);
                }
                else
                    throw nonGestito();
            }
        }
        else{
            if((char)operation=='+')
                *sx = *sx + *memory;
            if((char)operation=='-')
                *sx = *sx - *memory;
            if(sx->size()==1){
                if((char)operation=='*'){
                    *sx = sx->getMonomio_pos(0) * (*memory);
                }
                else if((char)operation==':'){
                    *sx = sx->getMonomio_pos(0) / (*memory);
                }
                else
                    throw erroreSimbolo();
            }
        }

        if((char)operation=='*' || (char)operation==':')
            throw nonGestito();
    }

    if(monomial){
        if(uguale)
            dx->addMonomio(operation,*monomial);
        else
            sx->addMonomio(operation,*monomial);
        delete monomial;
        monomial=0;
    }

    opInserita=false;
}

void modelEquazioni::setUguale(bool u){
    if(u)
        dx = new polinomio();
    uguale=u;
}

bool modelEquazioni::spuria_test(){
    try{
        e = new spuria(*sx,*dx);
        return true;
    }
    catch(erroreGrado){
        delete e;
        return false;
    }
}

bool modelEquazioni::pura_test(){
    try{
        e = new pura(*sx,*dx);
        return true;
    }
    catch(erroreGrado){
        delete e;
        return false;
    }
}

bool modelEquazioni::secondoGrado_test(){
    try{
        e = new secondoGrado(*sx,*dx);
        return true;
    }
    catch(erroreGrado){
        delete e;
        return false;
    }
}

bool modelEquazioni::primoGrado_test(){
    try{
        e = new primoGrado(*sx,*dx);
        return true;
    }
    catch(erroreGrado){
        delete e;
        return false;
    }
}


void modelEquazioni::calcola(){
    if(primoGrado_test()){
        grado= new razionale(e->getGrado());
        tipo= new tipoEquazione(e->getTipo());
        return;
    }
    if(spuria_test()){
        grado= new razionale(e->getGrado());
        tipo= new tipoEquazione(e->getTipo());
        return;
    }
    if(pura_test()){
        grado= new razionale(e->getGrado());
        tipo= new tipoEquazione(e->getTipo());
        return;
    }
    if(secondoGrado_test()){
        grado= new razionale(e->getGrado());
        tipo= new tipoEquazione(e->getTipo());
        return;
    }

    if(!e){
        grado=0;
        tipo=new tipoEquazione(tipoEquazione(4));
    }
}


string modelEquazioni::valoreX(){
    if(e)
        return e->risolvi();
    return "Non risolvibile";
}

string modelEquazioni::eseguiGrado(){
    if(!grado)
        throw nonGestito();
    return grado->toString();
}

string modelEquazioni::eseguiDelta(){
    return dynamic_cast<secondoGrado*>(e)->getDelta().toString();
}

string modelEquazioni::restituisciTipo(){
    switch((int)(*tipo)){
        case 0:
            return "Primo grado";
        case 1:
            return "Secondo grado";
        case 2:
            return "Pura di secondo grado";
        case 3:
            return "Spuria di secondo grado";
        default:
            return "Le equazioni gestite sono quelle di primo e secondo grado.";
    }
}


string modelEquazioni::eseguiDerivata(){
    if(e)
        e=e->derivata();
    else
        throw nonGestito();
    if(e){
        delete grado;
        delete tipo;
        grado=new razionale(e->getGrado());
        tipo=new tipoEquazione(e->getTipo());
    }
    else{
        throw x_Assente();
    }
    return e->getEquazione();
}

string modelEquazioni::eseguiSostituzioneX(){
    if(rational){
        if(e)
            return e->sostituzioneX(*rational);
        else
            throw nonGestito();
    }

    return "";
}
