#ifndef KALKPOLINOMI_H
#define KALKPOLINOMI_H

#include "../Model/modelpolinomio.h"
#include "tastiera.h"
#include <QLineEdit>
#include <QMessageBox>


class KalkPolinomi: public QWidget
{
public:
    explicit KalkPolinomi(QWidget* parent =0);

public slots:
    //Slot che gestisce tutte le operazioni di tastiera
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

private:
    tastiera* t;
    QPushButton* p[3];
    QLineEdit* schermo1;
    QLineEdit* schermo2;
    QVBoxLayout* layout;
    modelPolinomio* controller;

};

#endif // KALKPOLINOMI_H
