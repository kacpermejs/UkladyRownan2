#include <iostream>
#include <fstream>
#include <iomanip>
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

    char typ;
    cin >> typ;
    if(typ=='r')
    {
        UkladRownanLiniowych<double, ROZMIAR>   UklRown;
        Wektor<double, ROZMIAR> WekRozwiazan;
        Wektor<double, ROZMIAR> WekBledow;
        MacierzKw<double, ROZMIAR> MacUkladu;

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
    else if(typ=='z')
    {
        UkladRownanLiniowych<LZespolona, ROZMIAR>   UklRown;
        Wektor<LZespolona, ROZMIAR> WekRozwiazan;
        Wektor<LZespolona, ROZMIAR> WekBledow;
        MacierzKw<LZespolona, ROZMIAR> MacUkladu;

        cin >> UklRown;
        UklRown.zwroc_macierz().transponuj();
        cout << fixed << setprecision(2);
        cout << UklRown;
        MacUkladu=UklRown.macierz();
        WekRozwiazan=UklRown.oblicz();
        WekBledow=MacUkladu*WekRozwiazan-UklRown.wektor();

        cout << "Wynik: (";
        for(int i=1; i<=ROZMIAR; ++i)
        {
            cout << "x" << i;
            if(i!=ROZMIAR)
                cout << ", ";
        }
        cout << ") :\n" << WekRozwiazan << endl;
        
        cout << scientific << setprecision(1);
        cout << "Wektor bledu:\n"
        << WekBledow << endl;

        cout << "Dlugosc wektora bledu:\n"
        << WekBledow.dlugosc() << endl;
    }
}




