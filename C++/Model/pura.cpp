#include "pura.h"

pura::pura(const polinomio & a, const polinomio & b):
    secondoGrado(a,b){
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();
    if(temp.size()==2){
        if(temp.getMonomio_pos(0).getGrado()!=razionale(0,1))
            throw erroreGrado();
        if(temp.getMonomio_pos(1).getGrado()!=razionale(2,1))
            throw erroreGrado();
    }
    else
        if(temp.getMonomio_pos(0).getGrado()!=razionale(2,1))
            throw erroreGrado();
}

string pura::risolvi() const{
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();

    if(temp.getMonomio_pos(1).getCoefficiente().getNumeratore()==0 || temp.size()==1)
        return "x = 0";
    razionale r = razionale(-1,1)*temp.getMonomio_pos(0).getCoefficiente()/temp.getMonomio_pos(1).getCoefficiente();

    r = razionale::potenza(r,razionale(1,2));
    return "x = +"+r.toString()+"  &&  x= -"+r.toString();
}

tipoEquazione pura::getTipo() const{
    return tipoEquazione(2);
}

razionale pura::getDelta() const{
    razionale a,c;
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();

    a=temp.getMonomio_pos(1).getCoefficiente();
    c=temp.getMonomio_pos(0).getCoefficiente();
    return  razionale(-4)*a*c;
}

