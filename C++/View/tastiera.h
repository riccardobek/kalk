#ifndef TASTIERA_H
#define TASTIERA_H

#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <QGridLayout>

class tastiera : public QWidget
{
public:
    //Costruttore di defalut
    explicit tastiera(QWidget* parent =0);

    /*Metodo che restituisce l'indirizzo del puntatore
    * del pulsante alla posizione desiderata
    */
    QPushButton*& getPulsante(int);

private:
    QPushButton* p[21];
    QGridLayout* layout;


};

#endif // TASTIERA_H
