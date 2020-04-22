#include "Wektor.hh"



Wektor::Wektor()
{
    for(double &ElemTab : Tab)
        ElemTab=0;
}


Wektor::Wektor(double x, double y, double z)
{
    this->Tab[0] = x;
    this->Tab[1] = y;
    this->Tab[2] = z;
}


Wektor::Wektor(double tablica[])
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]=tablica[i];
}


Wektor & Wektor::operator += (const Wektor & W2)
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]+=W2.Tab[i];

    return *this;
}


Wektor & Wektor::operator -= (const Wektor & W2)
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]-=W2.Tab[i];

    return *this;
}


Wektor & Wektor::operator *= (double l)
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]*=l;

    return *this;
}


Wektor & Wektor::operator /= (double l)
{
    if(l==0)
    {
        std::cerr << "UWAGA: Dzielenie przez zero (zwracam bazowy wektor)\n";
        return *this;
    }
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]/=l;

    return *this;
}


double Wektor::dlugosc() const //modul
{
    double Wynik=0;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik+=pow((*this)[i],2);
    }

    return sqrt(Wynik);
}


bool Wektor::operator == (const Wektor & W2) const
{
    for(int i=0; i<ROZMIAR; i++)
    {
        if((this->Tab[i]+EPSILON)!=W2.Tab[i]||(this->Tab[i]-EPSILON)!=W2.Tab[i])
            return false;
    }
    return true;
}


bool Wektor::operator != (const Wektor & W2) const
{
    return !(*this==W2);
}


std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
        Strm >> Wek[i];
    return Strm;
}


std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm << Wek[i];

        if(i!=ROZMIAR-1)
            Strm << "\t";
    }

    return Strm;
}
