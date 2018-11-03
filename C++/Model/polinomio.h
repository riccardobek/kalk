#ifndef POLINOMIO_H
#define POLINOMIO_H

#include "monomio.h"
#include <list>

using std::list;

class polinomio
{
public:
    //Costruttore
    polinomio();

    //Cancella il contenuto del polinomio
    void clear();

    /*Aggiunge un simbolo e un monomio al polinomio:
     * somma, sottrazione, divisione e moltiplicazione sono gestite da
     * questo metodo
    */
    void addMonomio(const simbolo&,const monomio&);

    //Restituisce una specifica posizione del polinomio
    monomio getMonomio_pos(int) const;

    //Sostituisce la variabile x con un razionale
    razionale sostituisciVariabile(const razionale&);

    //Restituisce la derivata del polinomio
    polinomio getDerivata() const;

    //Restituisce il grado del polinomio
    razionale getGrado() const;

    //Stampa il polinomio sottoforma di stringa
    string toString() const;

    //Restituisce la lunghezza del polinomio
    int size() const;

    //Ordina dal termine noto alla x di grado maggiore il polinomio
    void ordina();
    void eliminaZeri();

private:
    list<monomio> pol;
};

ostream& operator<<(ostream&, const polinomio&);

//Operazione tra polinomio e monomio
polinomio operator*(const polinomio&, const monomio&);
polinomio operator/(const polinomio&, const monomio&);
//Operazione tra monomio e polinomio
polinomio operator+(const monomio&, const polinomio&);
polinomio operator-(const monomio&, const polinomio&);
polinomio operator*(const monomio&, const polinomio&);
polinomio operator/(const monomio&, const polinomio&);
//Operazione tra polinomio e polinomio
polinomio operator-(const polinomio&, const polinomio&);
polinomio operator+(const polinomio&, const polinomio&);

#endif // POLINOMIO_H
