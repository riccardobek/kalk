#include "polinomio.h"

polinomio::polinomio(){
    addMonomio(simbolo('+'),monomio());
}

void polinomio::clear(){
    pol.clear();
}

void polinomio::addMonomio(const simbolo& s, const monomio& m){
    if((char)s=='*'){
        if(pol.size()>0)
            *(--pol.end()) = (*(--pol.end())) * m;
        else
            throw erroreSimbolo();
    }

    if((char)s==':'){
        if(pol.size()>0)
            *(--pol.end()) = (*(--pol.end())) / m;
        else
            throw erroreSimbolo();
    }

    if((char)s=='+' || (char)s=='-'){
        bool trovato=false;
        list<monomio>::iterator i = pol.begin();
        for(;i!=pol.end() && !trovato;++i){
            try{
                if((char)s=='+')
                    *i = *i + m;
                else
                    *i = *i - m;
                trovato=true;
            }
            catch(std::exception){}
        }
        if(!trovato){
            if(m.getCoefficiente()<razionale(0) && (char)s=='-')
                pol.push_back(m*razionale(-1));
            else if((char)s=='-')
                pol.push_back(m*razionale(-1));
            else
                pol.push_back(m);

        }
    }
}

monomio polinomio::getMonomio_pos(int i) const{
    list<monomio>::const_iterator it = pol.begin();
    int j=0;
    while (i>j) {
        ++it;
        ++j;
    }
    return *it;
}

razionale polinomio::sostituisciVariabile(const razionale& r){
    razionale risultato;
    list<monomio>::const_iterator i=pol.begin();
    for(; i!=pol.end();++i){
        if((*i).getGrado().getNumeratore()!=0)
            risultato = risultato + (*i).getCoefficiente()*razionale::potenza(r,(*i).getGrado());
        else
            risultato = risultato + (*i).getCoefficiente();
    }
    return risultato;
}

polinomio polinomio::getDerivata() const{
    polinomio risultato;
    list<monomio>::const_iterator i=pol.begin();
    for(;i!=pol.end();++i){
        monomio tmp;
        if((*i).getGrado().getNumeratore()!=0 && (*i).getCoefficiente().getNumeratore()){
            tmp.setCoefficiente((*i).getCoefficiente()*(*i).getGrado());
            tmp.setEsponente((*i).getGrado()-razionale(1,1));
            risultato.addMonomio(simbolo('+'),tmp);
        }
    }
    return risultato;
}

razionale polinomio::getGrado() const{
    razionale max;
    list<monomio>::const_iterator i=pol.begin();
    for(;i!=pol.end();++i){
        if(max<(*i).getGrado() && (*i).getCoefficiente().getNumeratore()!=0)
            max=(*i).getGrado();
    }
    return max;
}

string polinomio::toString() const{
    string risultato;
    list<monomio>::const_iterator i=pol.begin();
    for(;i!=pol.end();++i){
        if((*i).getCoefficiente().getNumeratore()<0)
            risultato = risultato + " - " + ((*i)*razionale(-1)).toString();
        else if((*i).getCoefficiente().getNumeratore()>0)
            risultato = risultato + " + " + (*i).toString();
    }
    if(risultato.size()==0) risultato="0";
    return risultato;
}

int polinomio::size() const{
    return pol.size();
}

void polinomio::ordina(){
    pol.sort();
}

void polinomio::eliminaZeri(){
    list<monomio>::iterator it = pol.begin();
    for(;it!=pol.end();++it){
        if(it->getCoefficiente().getNumeratore()==0){
            it=pol.erase(it);
            --it;
        }
    }
}


ostream& operator<<(ostream& out, const polinomio& p){
    return out<<p.toString();
}

polinomio operator*(const polinomio& p, const monomio& m){
    polinomio risultato;
    for(int i=0; i<p.size();++i){
        risultato.addMonomio(simbolo('+'),(p.getMonomio_pos(i)*m));
    }
    return risultato;
}

polinomio operator/(const polinomio& p, const monomio& m){
    polinomio risultato;
    for(int i=0; i<p.size();++i){
        risultato.addMonomio(simbolo('+'),p.getMonomio_pos(i)/m);
    }
    return risultato;
}

polinomio operator+(const monomio& m, const polinomio& p){
    polinomio risultato;
    risultato.addMonomio(simbolo('+'),m);
    for(int i=0;i<p.size();++i){
        risultato.addMonomio(simbolo('+'),p.getMonomio_pos(i));
    }
    return risultato;
}

polinomio operator-(const monomio& m, const polinomio& p){
    polinomio risultato;
    risultato.addMonomio(simbolo('-'),m);
    for(int i=0;i<p.size();++i){
        risultato.addMonomio(simbolo('-'),p.getMonomio_pos(i));
    }
    return risultato;
}

polinomio operator*(const monomio& m, const polinomio& p){
    return polinomio(p*m);
}

polinomio operator/(const monomio& m, const polinomio& p){
    polinomio risultato;
    for(int i=0; i<p.size();++i){
        risultato.addMonomio(simbolo('+'),m/p.getMonomio_pos(i));
    }
    return risultato;
}

polinomio operator-(const polinomio& p1, const polinomio& p2){
    polinomio risultato(p1);
    for(int i=0;i<p2.size();++i){
        risultato.addMonomio(simbolo('-'),p2.getMonomio_pos(i));
    }
    return risultato;
}

polinomio operator+(const polinomio& p1, const polinomio& p2){
    polinomio risultato(p1);
    for(int i=0;i<p2.size();++i){
        risultato.addMonomio(simbolo('+'),p2.getMonomio_pos(i));
    }
    return risultato;
}











