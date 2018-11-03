#include "primogrado.h"

primoGrado::primoGrado(const polinomio& a,const polinomio& b):
    equazione(a,b){
    if(unifica().getGrado()!=razionale(1))
        throw erroreGrado();
}

string primoGrado::risolvi() const{
    polinomio temp = unifica();
    razionale menoUno(-1,1);
    temp.ordina();
    temp.eliminaZeri();
    razionale r;
    if(temp.size()==1)
        return string("x = 0");
    r = menoUno*temp.getMonomio_pos(1).getCoefficiente()/temp.getMonomio_pos(0).getCoefficiente();
    return string("x = "+r.toString());
}

tipoEquazione primoGrado::getTipo() const{
    return tipoEquazione(0);
}

razionale primoGrado::getGrado() const{
    return razionale(1);
}

primoGrado* primoGrado::derivata() const{
    return 0;
}
