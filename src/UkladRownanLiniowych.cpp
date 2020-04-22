#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych()
{
    MacierzKw AA;
    Wektor BB;

    this->A=AA;
    this->B=BB;
}

UkladRownanLiniowych::UkladRownanLiniowych(MacierzKw AA, Wektor BB)
{
    this->A=AA;
    this->B=BB;
}


Wektor UkladRownanLiniowych::oblicz()
{
    Wektor Wynik;
    Wektor WektorZerowy;

    MacierzKw Temp=this->A;

    double det=this->A.wyznacznik(GAUSS);
    Wektor detx;

    for(int i=0; i<ROZMIAR; i++)
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



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
    Strm >> UklRown.zwroc_macierz() >> UklRown.zwroc_wektor();

    return Strm;
}


std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          )
{
    char znakRownosci;

    MacierzKw Mac1=UklRown.macierz();


    for(int i=0; i<ROZMIAR; i++)
    {

        if(i==ROZMIAR/2)
            znakRownosci='=';
        else
            znakRownosci=' ';
        Strm << "|" << Mac1.zwrocWiersz(i) << "||" << "x" << i+1 << "|"
             << znakRownosci
             << "|" << UklRown.wektor()[i] << "|" << std::endl;

    }

    return Strm;
}
