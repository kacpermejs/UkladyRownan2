#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
#include <cmath>
#include <utility>
#include <cassert>
#include "AbsV.hh"

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

template<typename Typ, int Rozmiar>
class MacierzKw {
    Wektor<Typ, Rozmiar> Tab[Rozmiar]; //2. propozycja, zalecana
public:
    MacierzKw<Typ, Rozmiar>();
    MacierzKw<Typ, Rozmiar>(const Wektor<Typ, Rozmiar> Tab[]);
    //MacierzKw<Typ, Rozmiar>(Wektor<Typ, Rozmiar> A, Wektor<Typ, Rozmiar> B, Wektor<Typ, Rozmiar> C);

    const Typ wyznacznikLaplace();// rozwiniecje laplace'a, gaussa, sarrusa
    const Typ wyznacznikGauss();
    const Typ wyznacznikSarrus();
    const Typ wyznacznik(metoda met);

    const MacierzKw<Typ, Rozmiar> transponowana() const;
    void transponuj();

//=============================================================================================================================================

    MacierzKw<Typ, Rozmiar> & operator*=(const MacierzKw<Typ, Rozmiar> & M2);
    MacierzKw<Typ, Rozmiar> & operator+=(const MacierzKw<Typ, Rozmiar> & M2);
    MacierzKw<Typ, Rozmiar> & operator-=(const MacierzKw<Typ, Rozmiar> & M2);
    MacierzKw<Typ, Rozmiar> & operator*=(double l);


    inline const MacierzKw<Typ, Rozmiar> operator*(const MacierzKw<Typ, Rozmiar> & M2) { return MacierzKw<Typ, Rozmiar>(*this)*=M2; }
    inline const MacierzKw<Typ, Rozmiar> operator+(const MacierzKw<Typ, Rozmiar> & M2) { return MacierzKw<Typ, Rozmiar>(*this)+=M2; }
    inline const MacierzKw<Typ, Rozmiar> operator-(const MacierzKw<Typ, Rozmiar> & M2) { return MacierzKw<Typ, Rozmiar>(*this)-=M2; }
    inline const MacierzKw<Typ, Rozmiar> operator*(double l) { return MacierzKw<Typ, Rozmiar>(*this)*=l; }

    Wektor<Typ, Rozmiar> operator*(const Wektor<Typ, Rozmiar> & W2) const;

//=============================================================================================================================================

    const Wektor<Typ, Rozmiar> & operator[] (int index) const { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
    Wektor<Typ, Rozmiar> & operator[] (int index) { assert(index>=0 && index<Rozmiar); return this->Tab[index]; }
    const Typ & operator() (int ind1, int ind2) const { return this->Tab[ind2][ind1]; }
    Typ & operator() (int ind1, int ind2) { return this->Tab[ind2][ind1]; }

    const Wektor<Typ, Rozmiar> zwrocWiersz(int index) const;

};

/*!
 * Funkcja do wczytywania obiektu klasy  ze strumienia
 * Strm - strumien wejsciowy
 * Mac - wczytywana macierz (referencja)
 */
template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, MacierzKw<Typ, Rozmiar> &Mac);

/*!
 * Funkcja do wysylania obiektu MacierzKw do strumienia
 * Strm - strumien wyjsciowy
 * Mac - wysylana macierz (referencja)
 */
template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<Typ, Rozmiar> &Mac);

#endif
