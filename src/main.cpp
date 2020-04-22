#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"





/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
using namespace std;

    UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
    Wektor WekRozwiazan;
    Wektor WekBledow;
    MacierzKw MacUkladu;

    cin >> UklRown;
    UklRown.zwroc_macierz().transponuj();
    cout << UklRown;
    MacUkladu=UklRown.macierz();
    WekRozwiazan=UklRown.oblicz();
    WekBledow=MacUkladu*WekRozwiazan-UklRown.wektor();

    cout << "Wynik: (x1, x2,x3)\n"
    << WekRozwiazan << endl;

    cout << "Wektor bledu:\n"
    << WekBledow << endl;

    cout << "Dlugosc wektora bledu:\n"
    << WekBledow.dlugosc() << endl;



}




