#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <utility>
#include "Wektor.hh"
#include "Macierz.hh"

class UkladRownanLiniowych {
    MacierzKw A;
    Wektor B;
public:
    UkladRownanLiniowych();
    UkladRownanLiniowych(MacierzKw AA, Wektor BB);

    MacierzKw & zwroc_macierz() { return this->A; }
    const MacierzKw & macierz() const { return this->A; }
    void zmien_macierz(MacierzKw MM) { this->A=MM; }
    /*analogicznie dla wektora */
    Wektor & zwroc_wektor() { return this->B; }
    const Wektor & wektor() const { return this->B; }
    void zmien_wektor(Wektor WW) { this->B=WW; }

/*!
 * Metoda do obliczania ukladu rownan metoda Cramera
 */
    Wektor oblicz();
};


/*!
 * Funkcja do wczytywania obiektu klasy UkladRownanLiniowych ze strumienia
 * Strm - strumien wyjsciowy
 * UklRown - wysylany uklad (referencja)
 */

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*!
 * Funkcja do wysylania obiektu klasy UkladRownanLiniowych do strumienia
 * Strm - strumien wyjsciowy
 * UklRown - wysylany uklad (referencja)
 */

std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          );

#endif
