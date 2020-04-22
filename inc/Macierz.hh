#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>

enum metoda
{
LAPLACE,
GAUSS,
SARRUS
};
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */


class MacierzKw {
    Wektor Tab[ROZMIAR]; //2. propozycja, zalecana
public:
    MacierzKw();
    MacierzKw(const Wektor Tab[]);
    MacierzKw(Wektor A, Wektor B, Wektor C);

    double wyznacznikLaplace();// rozwiniecje laplace'a, gaussa, sarrusa
    double wyznacznikGauss();
    double wyznacznikSarrus();
    double wyznacznik(metoda met);

    const MacierzKw transponowana() const;
    void transponuj();

    MacierzKw & operator*=(const MacierzKw & M2);
    MacierzKw & operator+=(const MacierzKw & M2);
    MacierzKw & operator-=(const MacierzKw & M2);
    MacierzKw & operator*=(double l);


    inline const MacierzKw operator*(const MacierzKw & M2) { return MacierzKw(*this)*=M2; }
    inline const MacierzKw operator+(const MacierzKw & M2) { return MacierzKw(*this)+=M2; }
    inline const MacierzKw operator-(const MacierzKw & M2) { return MacierzKw(*this)-=M2; }
    inline const MacierzKw operator*(double l) { return MacierzKw(*this)*=l; }






    const Wektor & operator[] (int index) const { assert(index>=0 && index<ROZMIAR); return this->Tab[index]; }
    Wektor & operator[] (int index) { assert(index>=0 && index<ROZMIAR); return this->Tab[index]; }
    const double & operator() (int ind1, int ind2) const { return this->Tab[ind2][ind1]; }
    double & operator() (int ind1, int ind2) { return this->Tab[ind2][ind1]; }

    const Wektor zwrocWiersz(int index) const;

};

Wektor operator*(const MacierzKw & M1, const Wektor & W2);
/*!
 * Funkcja do wczytywania obiektu klasy  ze strumienia
 * Strm - strumien wejsciowy
 * Mac - wczytywana macierz (referencja)
 */

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac);

/*!
 * Funkcja do wysylania obiektu MacierzKw do strumienia
 * Strm - strumien wyjsciowy
 * Mac - wysylana macierz (referencja)
 */

std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac);

#endif
