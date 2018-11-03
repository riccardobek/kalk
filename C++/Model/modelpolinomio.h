#ifndef MODELPOLINOMIO_H
#define MODELPOLINOMIO_H

#include "../Model/polinomio.h"

class modelPolinomio
{
public:
    //Costruttore
    modelPolinomio();

    //Crea il monomio necessario per gli inserimenti nel polinomio
    void creaMonomio(string);

    //Crea un razionale per permettere il metodo potenzaRazionale()
    void creaRazionale(string);

    //Memorizza il polinomio corrente in M e lo cancella
    void memorizzaPoly();

    //Effettua i calcoli per ottenere il polinomio finale
    void calcola();

    //Permette l'inserimento dell'operazione
    void setOperazione(const simbolo&);

    //Segnala che l'operazione è stata cancellata
    void resetInsertOp();

    //Segnala se l'operazione è stata inserita
    bool getOperazione() const;

    //Cancella i valori inseriti in input
    void DEL();

    //Cancella tutti i dati
    void AC();

    //Stampa il polinomio
    string getPolinomio() const;

    //Stampa la potenza del razionale precedentemente inserito con creaRazionale()
    string calcolaPotenza(string);

    //Sostituisce la x con il razionale precedentemente inserito con creaRazionale()
    string sostituzioneX();

    //Calcola la derivata del polinomio
    string derivata();

    //Restituisce il grado del polinomio
    string grado() const;

    //Verifica se la memoria è effettivamente popolata
    bool getMemory() const;

    //Inserisce il valore del polinomio presente in memoria al polinomio corrente
    string setPolyUMemory();

    //Effettua le operazioni necessarie per per unire il polinomio in M con quello corrente
    string polyOpMemory();

    //Controlla la presenza del circonflesso
    bool getCirconflesso() const;

    //Setta se il circonflesso è stato, o meno, inserito
    void setCirconflesso(bool);

private:
    polinomio* poly;
    polinomio* memory;
    razionale* rational;
    monomio* monomial;
    simbolo operation;
    bool insertOp;
    bool insertCirconflesso;

};

#endif // MODELPOLINOMIO_H
