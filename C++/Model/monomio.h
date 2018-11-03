#ifndef MONOMIO_H
#define MONOMIO_H

#include "razionale.h"

class monomio
{
public:
    //Costruttore di default
    monomio(const razionale& =razionale(),const razionale& =razionale());

    //Costruttore del monomio attraverso parsing di una stringa
    monomio(const string&);

    //Getter
    razionale getCoefficiente() const;
    razionale getGrado() const;

    //Setter
    void setCoefficiente(const razionale&);
    void setEsponente(const razionale&);

    //Funzionalità
    string toString() const;
    bool operator< (const monomio&) const;

private:
    razionale coefficiente;
    razionale esponente;
};
//Output in linea di comando
ostream& operator<<(ostream&, const monomio&);

//Operazioni tra monomi
monomio operator+(const monomio&, const monomio&);
monomio operator-(const monomio&, const monomio&);
monomio operator*(const monomio&, const monomio&);
monomio operator/(const monomio&, const monomio&);


#endif // MONOMIO_H
