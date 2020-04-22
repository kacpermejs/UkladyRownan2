#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cassert>
#include <cmath>
#include "rozmiar.h"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template<typename Typ, int Rozmiar>
class Wektor {

    Typ Tab[Rozmiar]; //4 tablica statyczna

    public:

    Wektor<Typ, Rozmiar>();

    Wektor<Typ, Rozmiar>(double x, double y, double z);
    //Wektor<Typ, Rozmiar>(Typ x,Typ y, Typ z);
    Wektor<Typ, Rozmiar>(Typ tablica[]);

    Wektor<Typ, Rozmiar> & operator += (const Wektor<Typ, Rozmiar> & W2); //W1 += W2  , W1 += W3 += W4
    Wektor<Typ, Rozmiar> & operator -= (const Wektor<Typ, Rozmiar> & W2);
    Wektor<Typ, Rozmiar> & operator *= (Typ l);
    Wektor<Typ, Rozmiar> & operator /= (Typ l);

    Typ operator * (const Wektor<Typ, Rozmiar> & W2) const; //skalarnie

    inline const Wektor<Typ, Rozmiar> operator + (const Wektor<Typ, Rozmiar> & W2) const { return Wektor<Typ, Rozmiar>(*this)+=W2; } //W1 + W2
    inline const Wektor<Typ, Rozmiar> operator - (const Wektor<Typ, Rozmiar> & W2) const { return Wektor<Typ, Rozmiar>(*this)-=W2; }
    inline const Wektor<Typ, Rozmiar> operator * (Typ l) const { return Wektor<Typ, Rozmiar>(*this)*=l; } // W1 * 2
    inline const Wektor<Typ, Rozmiar> operator / (Typ l) const { return Wektor<Typ, Rozmiar>(*this)/=l; } // W1 / 2

    Typ dlugosc() const; //modul

    bool operator == (const Wektor<Typ, Rozmiar> & W2) const;
    bool operator != (const Wektor<Typ, Rozmiar> & W2) const;

    inline const Typ & operator[] (int index) const { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
    inline Typ & operator[] (int index) { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
};
template<typename Typ, int Rozmiar>
inline Wektor<Typ, Rozmiar> operator *(Typ l, Wektor<Typ, Rozmiar> W2) { return Wektor<Typ, Rozmiar>(W2)*l; }
/*!
 * Funkcja do wczytywania obiektu klasy Wektor ze strumienia
 * Strm - strumien wyjsciowy
 * Wek - wczytywany uklad (referencja)
 */
template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ, Rozmiar> &Wek);

/*!
 * Funkcja do wysylania obiektu klasy Wektor do strumienia
 * Strm - strumien wyjsciowy
 * Wek - wysylany uklad (referencja)
 */
template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Typ, Rozmiar> &Wek);

#endif
