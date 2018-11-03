#ifndef SECONDOGRADO_H
#define SECONDOGRADO_H

#include "equazione.h"
#include "primogrado.h"

class secondoGrado: public equazione
{
public:
    /*Crea l'equazione solo se effettivamente di secondo grado
     * altrimenti lancia un'eccezione
    */
    secondoGrado(const polinomio& =polinomio(), const polinomio& =polinomio());

    //Stampa la soluzione dell'equazione
    string risolvi() const;

    //Stampa il tipo dell'equazione
    tipoEquazione getTipo() const;

    //Calcola il delta dell'equazione: c + bx^1 + ax^2 = 0 -->delta= b^2 - 4a * c
    razionale getDelta() const;

    //Restituisce il grado dell'equazione
    razionale getGrado() const;

    //Restituisce la derivata dell'equazione ovvero da secondo grado passa a primo grado
    primoGrado* derivata() const;
};

#endif // SECONDOGRADO_H
