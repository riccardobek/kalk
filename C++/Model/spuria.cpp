#include "spuria.h"

spuria::spuria(const polinomio& a, const polinomio& b):
    secondoGrado(a,b){
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();
    if(temp.getMonomio_pos(0).getGrado()!=razionale(1,1))
        throw erroreGrado();
    if(temp.getMonomio_pos(1).getGrado()!=razionale(2,1))
        throw erroreGrado();
}

string spuria::risolvi() const{
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();
    razionale r = razionale(-1,1)*temp.getMonomio_pos(0).getCoefficiente()/temp.getMonomio_pos(1).getCoefficiente();
    return "x= 0  &&  x= "+r.toString();
}

tipoEquazione spuria::getTipo() const{
    return tipoEquazione(3);
}

razionale spuria::getDelta() const{
    razionale a,b;
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();

    a=temp.getMonomio_pos(1).getCoefficiente();
    b=temp.getMonomio_pos(0).getCoefficiente();
    return b*b - razionale(4)*a;
}

