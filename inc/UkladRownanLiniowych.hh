#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <utility>
#include "Wektor.hh"
#include "Macierz.hh"

template<typename Typ, int Rozmiar>
class UkladRownanLiniowych {
    MacierzKw<Typ, Rozmiar> A;
    Wektor<Typ, Rozmiar> B;
public:
    UkladRownanLiniowych<Typ, Rozmiar>();
    UkladRownanLiniowych<Typ, Rozmiar>(MacierzKw<Typ, Rozmiar> AA, Wektor<Typ, Rozmiar> BB);

    MacierzKw<Typ, Rozmiar> & zwroc_macierz() { return this->A; }
    const MacierzKw<Typ, Rozmiar> & macierz() const { return this->A; }
    void zmien_macierz(MacierzKw<Typ, Rozmiar> MM) { this->A=MM; }
    /*analogicznie dla wektora */
    Wektor<Typ, Rozmiar> & zwroc_Wektor() { return this->B; }
    const Wektor<Typ, Rozmiar> & wektor() const { return this->B; }
    void zmien_Wektor(Wektor<Typ, Rozmiar> WW) { this->B=WW; }

/*!
 * Metoda do obliczania ukladu rownan metoda Cramera
 */
    Wektor<Typ, Rozmiar> oblicz();
};


/*!
 * Funkcja do wczytywania obiektu klasy UkladRownanLiniowych ze strumienia
 * Strm - strumien wyjsciowy
 * UklRown - wysylany uklad (referencja)
 */
template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ, Rozmiar> &UklRown);

/*!
 * Funkcja do wysylania obiektu klasy UkladRownanLiniowych do strumienia
 * Strm - strumien wyjsciowy
 * UklRown - wysylany uklad (referencja)
 */
template<typename Typ, int Rozmiar>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<Typ, Rozmiar> &UklRown
                          );

#endif
