#include "razionale.h"


int razionale::stringToNumber(const std::string& text){
    std::istringstream ss(text);
    int result;
    return ss>>result ? result : throw std::exception();
}

string razionale::numberToString(int number){
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

razionale::razionale(int a, int b): num(a), den(b) {
    if(!b) throw divisioneZero();
    semplifica();
}

razionale::razionale(const string& s){
    unsigned int barra=s.find('/');
    if(barra==-1){
        num=stringToNumber(s.substr(0,s.length()));
        den=1;
    }
    else{
        num=stringToNumber(s.substr(0, barra));
        den=stringToNumber(s.substr(barra+1, s.length()-barra));
    }
    if(!den) throw divisioneZero();
    semplifica();
}


int razionale::getNumeratore() const{return num;}
int razionale::getDenominatore() const{return den;}
void razionale::setNumeratore(int n){num=n;}
void razionale::setDenominatore(int d){den=d;}

razionale razionale::potenza(const razionale& b, const razionale& e){
    if(b.num<=0 && e.den%2==0)
        throw erroreRadice();

    razionale exp = e;
    razionale risultato = b;

    if(e.num<0){
        exp = exp * razionale(-1);
        int tmp = risultato.num;
        risultato.num = risultato.den;
        risultato.den = tmp;
    }

    int tmpN = pow(risultato.num,static_cast<double>(exp))*100;
    int tmpD = pow(risultato.den,static_cast<double>(exp))*100;

    razionale tmp1(tmpN,100);
    razionale tmp2(tmpD,100);

    risultato=tmp1/tmp2;

    return risultato;
}

void razionale::semplifica(){
    int i=2;
    int min=0;
    if(den<0){
        num*=-1;
        den*=-1;
    }
    do{
        if(num<den) min=den;
        else min=num;

        if((num%i==0)&&(den%i==0)){
            num=num/i;
            den=den/i;
        }
        else ++i;
    }while(i<=min);
}

string razionale::toString() const{
    return (den != 1) ? (numberToString(num) + '/' + numberToString(den)) : numberToString(num);
}

razionale::operator double(){
    return (static_cast<double>(num)/static_cast<double>(den));
}

bool razionale::operator!=(const razionale& a) const{
    return num!=a.num || den!=a.den;
}

bool razionale::operator==(const razionale& a) const{
    return num!=a.num && den!=a.den;
}

bool razionale::operator<(const razionale& a) const{
    return num*a.den < den*a.num;
}

ostream& operator<<(ostream& out, const razionale& a){
    return out<<a.toString();
}

razionale operator+(const razionale& a, const razionale& b){
    return razionale(a.getNumeratore()*b.getDenominatore()+b.getNumeratore()*a.getDenominatore() , a.getDenominatore()*b.getDenominatore());
}

razionale operator-(const razionale& a, const razionale& b){
    return razionale(a.getNumeratore()*b.getDenominatore()-b.getNumeratore()*a.getDenominatore() , a.getDenominatore()*b.getDenominatore());
}

razionale operator*(const razionale& a, const razionale& b){
    return razionale(a.getNumeratore()*b.getNumeratore() , a.getDenominatore()*b.getDenominatore());
}

razionale operator/(const razionale& a, const razionale& b){
    return razionale(a.getNumeratore()*b.getDenominatore(),a.getDenominatore()*b.getNumeratore());
}
