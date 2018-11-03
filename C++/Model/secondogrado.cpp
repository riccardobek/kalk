#include "secondogrado.h"


secondoGrado::secondoGrado(const polinomio& a, const polinomio& b):
    equazione(a,b){
    polinomio temp = unifica();
    temp.eliminaZeri();
    if(temp.getGrado()!=razionale(2,1) || temp.size()!=3)
        throw erroreGrado();
}

string secondoGrado::risolvi() const{
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();
    razionale delta = getDelta();
    razionale risultato1, risultato2;
    if (delta >= 0){
        risultato1 = razionale(-1)*temp.getMonomio_pos(1).getCoefficiente() - razionale::potenza(delta,razionale(1,2));
        risultato1 = risultato1/ (razionale(2)*temp.getMonomio_pos(2).getCoefficiente());
        risultato2 = razionale(-1)*temp.getMonomio_pos(1).getCoefficiente() + razionale::potenza(delta,razionale(1,2));
        risultato2 = risultato2/ (razionale(2)*temp.getMonomio_pos(2).getCoefficiente());

        return "x= "+risultato1.toString() + "  &&  x= " + risultato2.toString();
    }
    else
        return "Delta negativo: "+delta.toString();
}

tipoEquazione secondoGrado::getTipo() const{
    return tipoEquazione(1);
}

razionale secondoGrado::getDelta() const{
    razionale a,b,c;
    polinomio temp = unifica();
    temp.ordina();
    temp.eliminaZeri();
    a=temp.getMonomio_pos(2).getCoefficiente();
    b=temp.getMonomio_pos(1).getCoefficiente();
    c=temp.getMonomio_pos(0).getCoefficiente();
    return b*b - razionale(4)*a*c;
}

razionale secondoGrado::getGrado() const{
    return razionale(2,1);
}

primoGrado* secondoGrado::derivata() const{
    return new primoGrado(unifica().getDerivata());
}
