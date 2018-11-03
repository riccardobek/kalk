#ifndef MODELEQUAZIONI_H
#define MODELEQUAZIONI_H

#include "Model/pura.h"
#include "Model/spuria.h"
#include "Model/primogrado.h"

class modelEquazioni
{
public:
    //Costruttore
    modelEquazioni();

    //Sostituisci la x presente nell'equazione e verifica se vi è uguaglianza o meno
    string eseguiSostituzioneX();

    //Verifica se è un'equazione di secondo grado e quindi stampa il valore del delta
    string eseguiDelta();

    //Calcola la derivata e stampala
    string eseguiDerivata();

    //Stampa il grado dell'equazione
    string eseguiGrado();

    //Stampa il tipo dell'equazione
    string restituisciTipo();

    /*Stampa l'equazione quando questa viene effettivamente creata dopo il metodo calcola(),
     * altrimenti procedi con la stampa del polinomio sinistro e destro a seconda della
     * presenza o assenza dell'uguale
    */
    string getEquazione() const;

    //Crea il monomio necessario per gli inserimenti nel polinomio
    void creaMonomio(string);

    //Procedi con la memorizzazione in M del polinomio e resetta quest'ultimo
    void memorizza();

    //Verifica se la memoria è stata popolata
    bool getMemoryPopulated() const;

    //Inserisci quanto memorizzato nel polinomio e cancella la memoria
    void insertMemoryInPoly();

    //Resetta la M e il suo click
    void resetMemory();

    //Segnala che la M è stata premuta per memorizzare
    void setClickM();

    //Verifica la presenza di un'operazione
    bool getOpInserita() const;

    //Verifica se presente o meno l'uguale
    bool getUguale() const;

    //Crea un razionale per permettere due metodi: eseguiSostituzioneX() e potenzaRazionale()
    void creaRazionale(string);

    //Segnala l'inserimento del circonflesso
    void inseritoCirconflesso();

    //Canclella il circonflesso
    void resetCirconflesso();

    //Verifica la presenza del simbolo circonflesso
    bool getCirconflesso() const;

    //Calcola la potenza del razionale inserito in precedenza con il creaRazionale
    string potenzaRazionale(string);

    //Memorizza l'operzione che bisognerà eseguire
    void inserisciOperazione(const simbolo&);

    /*Procede ai calcoli dei singoli polinomi, destro e sinistro,
     * prima della creazione dell'equazione
    */
    void calcolaPolinomi();

    //Controlla se inserito l'uguale per comprendere se bisogna lavorare a destra o a sinistra
    void setUguale(bool);

    //Richiama i metodi di istanziazione dell'equazione e alloca grado e tipo
    void calcola();

    //Individua i risultati dell'equazione
    string valoreX();

    //Cancella i valori inseriti in input
    void DEL();

    //Cancella tutti i dati
    void AC();

private:

    // test per individuare il tipo di equazione e allocarla con successo
    bool spuria_test();
    bool pura_test();
    bool secondoGrado_test();
    bool primoGrado_test();


    polinomio *sx,*dx;
    equazione* e;
    razionale* rational;
    polinomio* memory;
    monomio* monomial;
    razionale* grado;
    tipoEquazione* tipo;
    simbolo operation;
    bool uguale;
    bool insertCirconflesso;
    bool memoryPopulated;
    bool cliccataM;
    bool opInserita;

};

#endif // MODELEQUAZIONI_H
