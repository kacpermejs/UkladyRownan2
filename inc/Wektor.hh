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

class Wektor {

    double Tab[ROZMIAR]; //4 tablica statyczna

    public:

    Wektor();
    Wektor(double x,double y, double z);
    Wektor(double tablica[]);

    Wektor & operator += (const Wektor & W2); //W1 += W2  , W1 += W3 += W4
    Wektor & operator -= (const Wektor & W2);
    Wektor & operator *= (double l);
    Wektor & operator /= (double l);

    double operator * (const Wektor & W2) const; //skalarnie

    inline const Wektor operator + (const Wektor & W2) const { return Wektor(*this)+=W2; } //W1 + W2
    inline const Wektor operator - (const Wektor & W2) const { return Wektor(*this)-=W2; }
    inline const Wektor operator * (double l) const { return Wektor(*this)*=l; } // W1 * 2
    inline const Wektor operator / (double l) const { return Wektor(*this)/=l; } // W1 / 2

    double dlugosc() const; //modul

    bool operator == (const Wektor & W2) const;
    bool operator != (const Wektor & W2) const;

    inline const double & operator[] (int index) const { assert(index>=0 && index<ROZMIAR); return this->Tab[index]; }
    inline double & operator[] (int index) { assert(index>=0 && index<ROZMIAR); return this->Tab[index]; }
};
inline Wektor operator *(double l, Wektor W2) { return Wektor(W2)*l; }
/*!
 * Funkcja do wczytywania obiektu klasy Wektor ze strumienia
 * Strm - strumien wyjsciowy
 * Wek - wczytywany uklad (referencja)
 */

std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*!
 * Funkcja do wysylania obiektu klasy Wektor do strumienia
 * Strm - strumien wyjsciowy
 * Wek - wysylany uklad (referencja)
 */

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

#endif
