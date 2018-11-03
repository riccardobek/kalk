#ifndef SPURIA_H
#define SPURIA_H

#include "secondogrado.h"

class spuria: public secondoGrado
{
public:
    /*Crea l'equazione solo se effettivamente di spuria di secondo grado
     * altrimenti lancia un'eccezione
    */
    spuria(const polinomio& =polinomio(), const polinomio& =polinomio());

    //Stampa la soluzione dell'equazione
    string risolvi() const;

    //Restituisce il tipo dell'equazione
    tipoEquazione getTipo() const;

    razionale getDelta() const;

};

#endif // SPURIA_H
