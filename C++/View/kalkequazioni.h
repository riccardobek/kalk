#ifndef KALKEQUAZIONI_H
#define KALKEQUAZIONI_H

#include "../Model/modelequazioni.h"
#include "View/tastiera.h"
#include <QWidget>
#include <QLineEdit>
#include <QMessageBox>

class KalkEquazioni: public QWidget
{
public:
    explicit KalkEquazioni(QWidget* parent =0);

private slots:
    //Slot che gestisce tutti i pulsanti di tastiera eccetto l'uguale
    void inserisci();

    /*Slot che fa eseguire la sostituzione delle x con una razionale
     * inserito nello schermo2 (+ gestione degli eventuali errori)
    */
    void sostituisciX();

    /*Slot che calcola la derivata dell'equazione quando permesso
     * (+ gestione degli eventuali errori)
    */
    void derivata();

    //Slot che stampa il grado dell'equazione
    void grado();

    //Slot che stampa il tipo dell'equazione
    void tipo();

    //Slot che stampa il delta dell'equazione
    void delta();

    /*Slot che gestisce le diverse operazioni di cui è incaricato il pulsante =
     * (+ gestione degli eventuali errori)
    */
    void calcola();

private:
    tastiera* t;
    QPushButton* p[5];
    QLineEdit* schermo1;
    QLineEdit* schermo2;
    QVBoxLayout* layout;

    modelEquazioni* controller;
};

#endif // KALKEQUAZIONI_H
