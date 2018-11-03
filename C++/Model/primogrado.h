#ifndef PRIMOGRADO_H
#define PRIMOGRADO_H

#include "equazione.h"

class primoGrado: public equazione
{
public:
    /*Crea l'equazione solo se effettivamente di primo grado
     * altrimenti lancia un'eccezione
    */
    primoGrado(const polinomio& =polinomio(), const polinomio& =polinomio());

    //Stampa la soluzione dell'equazione
    string risolvi() const;

    //Restituisce il tipo dell'equazione
    tipoEquazione getTipo() const;

    //Restituisce il grado dell'equazione
    razionale getGrado() const;

    /*Calcola la derivata dell'equazione che essendo di primo grado
     *  non può essere effettuata
    */
    primoGrado* derivata() const;
};

#endif // PRIMOGRADO_H
