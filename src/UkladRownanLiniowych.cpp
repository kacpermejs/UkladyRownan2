#include "UkladRownanLiniowych.hh"

template<typename Typ, int Rozmiar>
UkladRownanLiniowych<Typ, Rozmiar>::UkladRownanLiniowych()
{
    MacierzKw AA;
    Wektor BB;

    this->A=AA;
    this->B=BB;
}

template<typename Typ, int Rozmiar>
UkladRownanLiniowych<Typ, Rozmiar>::UkladRownanLiniowych(MacierzKw<Typ, Rozmiar> AA, Wektor<Typ, Rozmiar> BB)
{
    this->A=AA;
    this->B=BB;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> UkladRownanLiniowych<Typ, Rozmiar>::oblicz()
{
    Wektor Wynik<Typ, Rozmiar>;
    Wektor WektorZerowy<Typ, Rozmiar>;

    MacierzKw Temp=this->A;

    double det=this->A.wyznacznik(GAUSS);
    Wektor detx;

    for(int i=0; i<Rozmiar; i++)
    {
        Temp=this->A;
        Temp[i]=this->B;
        detx[i]=Temp.wyznacznik(GAUSS);

        Wynik[i]=detx[i]/det;
    }

    if(detx==WektorZerowy && (det+EPSILON==0 || det+EPSILON==0))
        std::cout << "Uklad ma nieskonczenie wiele rozwiazan!\n";
    else if(detx!=WektorZerowy && (det+EPSILON==0 || det+EPSILON==0))
        std::cout << "Uklad jest sprzeczny\n";



    return Wynik;
}


template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<Typ, Rozmiar> &UklRown)
{
    Strm >> UklRown.zwroc_macierz() >> UklRown.zwroc_wektor();

    return Strm;
}

template<typename Typ, int Rozmiar>
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych<Typ, Rozmiar>    &UklRown
                          )
{
    char znakRownosci;

    MacierzKw Mac1=UklRown.macierz();


    for(int i=0; i<Rozmiar; i++)
    {

        if(i==Rozmiar/2)
            znakRownosci='=';
        else
            znakRownosci=' ';
        Strm << "|" << Mac1.zwrocWiersz(i) << "||" << "x" << i+1 << "|"
             << znakRownosci
             << "|" << UklRown.wektor()[i] << "|" << std::endl;

    }

    return Strm;
}

template class UkladRownanLiniowych<double, ROZMIAR>;
