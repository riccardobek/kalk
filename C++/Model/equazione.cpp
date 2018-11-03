
#include "equazione.h"

equazione::equazione(const polinomio& s,const polinomio& d):sx(s),dx(d){}

polinomio equazione::unifica() const{
    return sx-dx;
}

string equazione::getEquazione() const{
    polinomio temp=unifica();
    temp.ordina();
    return temp.toString()+" = 0 ";
}

string equazione::sostituzioneX(const razionale& r){
    razionale a =sx.sostituisciVariabile(r);
    razionale b =dx.sostituisciVariabile(r);
    return a==b ? a.toString()+" = "+b.toString() : a.toString()+" != "+b.toString();
}

equazione::~equazione(){}
