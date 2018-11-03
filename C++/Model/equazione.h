#ifndef EQUAZIONE_H
#define EQUAZIONE_H

#include "polinomio.h"

class equazione
{
public:
    equazione(const polinomio& =polinomio(),const polinomio& =polinomio());

    //Metodo per unire i due polinomi dell'equzione
    polinomio unifica() const;
    //Metodo che stampa l'equazione con 0 a destra
    string getEquazione() const;
    /*Metodo che restituisce una stringa che indica
     * l'uguaglianza o meno per un'opportuna x
    */
    string sostituzioneX(const razionale&);

    //Metodi virtuali puri
    virtual string risolvi() const =0;
    virtual tipoEquazione getTipo() const =0;
    virtual razionale getGrado() const =0;
    virtual equazione* derivata() const =0;

    //distruttore virtuale
    virtual ~equazione();

private:
    polinomio sx,dx;
};


#endif // EQUAZIONE_H

