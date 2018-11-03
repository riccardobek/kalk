#ifndef CONFIG_H
#define CONFIG_H

#include <exception>

//!Errori sui razionali
class divisioneZero: public std::exception{};
class erroreRadice: public std::exception{};

//!Errore sui monomi
class esponenteDiverso: public std::exception{};

//!Errori sulle equazioni
class erroreGrado: public std::exception{};
class x_Assente: public std::exception{};


//!Simboli
enum class simbolo{
    piu='+',
    meno='-',
    per='*',
    diviso=':',
    circonflesso='^'
};

//!Tipo di equazioni
enum class tipoEquazione{
    eqPrimoGrado =0,
    eqSecondoGrado =1,
    eqSecondoGradoPura =2,
    eqSecondoGradoSpuria =3,
    eqMaggioreDue =4
};

//!Errori di inserimento generati dalle classi modelPolinomio e modelEquazioni
class erroreSimbolo: public std::exception{};
class errorePotenza: public std::exception{};
class nonGestito: public std::exception{};

#endif // CONFIG_H
