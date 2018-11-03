#ifndef PURA_H
#define PURA_H

#include "secondogrado.h"

class pura: public secondoGrado
{
public:

    /*Crea l'equazione solo se effettivamente di pura di secondo grado
     * altrimenti lancia un'eccezione
    */
    pura(const polinomio& =polinomio(), const polinomio& =polinomio());

    //Stampa la soluzione dell'equazione
    string risolvi() const;

    //Restituisce il tipo dell'equazione
    tipoEquazione getTipo() const;

    razionale getDelta() const;

};

#endif // PURA_H
