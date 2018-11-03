#include "monomio.h"

//COSTRUTTORI
monomio::monomio(const razionale& c, const razionale& exp):
    coefficiente(c), esponente(exp){}

monomio::monomio(const string& s){
    unsigned int var=s.find('x');
    if(var!=-1){
        string c=s.substr(0,var);
        if(c.size()==0){ c="1";}
        string exp=s.substr(var+2,s.length()-var);
        coefficiente=razionale(c);
        esponente=razionale(exp);
    }
    else{
        coefficiente=razionale(s);
        esponente=razionale(0,1);
    }
}

//GETTER
razionale monomio::getCoefficiente() const{return coefficiente;}
razionale monomio::getGrado() const{
    return esponente;
}
//SETTER
void monomio::setCoefficiente(const razionale& r){coefficiente=r;}
void monomio::setEsponente(const razionale& r){esponente=r;}

//FUNZIONALITA'
string monomio::toString() const{
    return coefficiente.toString()+(esponente.getNumeratore()!=0 ? "x^"+esponente.toString() : "");
}

bool monomio::operator< (const monomio& m) const{
    return esponente<m.esponente;
}

//OUTPUT IN LINEA DI COMANDO
ostream& operator<<(ostream& out, const monomio& m){
    return out<<m.toString();
}

//OPERAZIONI

monomio operator+(const monomio& a, const monomio& b){
    if(a.getGrado()!=b.getGrado())
        throw esponenteDiverso();
    return monomio(a.getCoefficiente()+b.getCoefficiente(),a.getGrado());
}

monomio operator-(const monomio& a, const monomio& b){
    if(a.getGrado()!=b.getGrado())
        throw esponenteDiverso();
    return monomio(a.getCoefficiente()-b.getCoefficiente(),a.getGrado());
}

monomio operator*(const monomio& a, const monomio& b){
    return monomio(a.getCoefficiente()*b.getCoefficiente(),a.getGrado()+b.getGrado());
}

monomio operator/(const monomio& a, const monomio& b){
    return monomio(a.getCoefficiente()/b.getCoefficiente(),a.getGrado()-b.getGrado());
}

