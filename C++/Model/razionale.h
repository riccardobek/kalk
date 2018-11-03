#ifndef RAZIONALE_H
#define RAZIONALE_H

#include "config.h"
#include <iostream>
#include <cmath>
#include <sstream>

using std::ostream;
using std::string;

class razionale
{
public:
    //Costruttore di defalut
    razionale(int =0, int =1);

    //Costruttore del razionale tramite parsing di una stringa
    razionale(const string&);

    //Getter
    int getNumeratore() const;
    int getDenominatore() const;

    //Setter
    void setNumeratore(int);
    void setDenominatore(int);

    //Funzionalità
    string toString() const;
    static razionale potenza(const razionale&, const razionale&);
    operator double();
    bool operator!=(const razionale&) const;
    bool operator==(const razionale&) const;
    bool operator<(const razionale&) const;

private:
    int num;
    int den;

    //Semplifica il razionale
    void semplifica();

    //Trasforma le stringe in numeri: utile per il parsing
    static int stringToNumber(const string&);

    //Trasforma i numeri in stringa: utile per la stampa
    static string numberToString(int);
};
//Output in linea di comando
ostream& operator<<(ostream&, const razionale&);

//Operazioni sui razionali
razionale operator+(const razionale&, const razionale&);
razionale operator-(const razionale&, const razionale&);
razionale operator*(const razionale&, const razionale&);
razionale operator/(const razionale&, const razionale&);


#endif // RAZIONALE_H
