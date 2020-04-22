#include "Wektor.hh"


template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor()
{
    for(Typ &ElemTab : Tab)
        ElemTab=0;
}

/*
template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor(Typ x, Typ y, Typ z)
{
    this->Tab[0] = x;
    this->Tab[1] = y;
    this->Tab[2] = z;
}*/

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar>::Wektor(Typ tablica[])
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]=tablica[i];
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator += (const Wektor<Typ, Rozmiar> & W2)
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]+=W2.Tab[i];

    return *this;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator -= (const Wektor<Typ, Rozmiar> & W2)
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]-=W2.Tab[i];

    return *this;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator *= (Typ l)
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]*=l;

    return *this;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator /= (Typ l)
{
    if(l==0)
    {
        std::cerr << "UWAGA: Dzielenie przez zero (zwracam bazowy wektor)\n";
        return *this;
    }
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]/=l;

    return *this;
}

template<typename Typ, int Rozmiar>
Typ Wektor<Typ, Rozmiar>::dlugosc() const //modul
{
    Typ Wynik=0;
    for(int i=0; i<Rozmiar; i++)
    {
        Wynik+=pow((*this)[i],2);
    }

    return sqrt(Wynik);
}

template<typename Typ, int Rozmiar>
bool Wektor<Typ, Rozmiar>::operator == (const Wektor<Typ, Rozmiar> & W2) const
{
    for(int i=0; i<Rozmiar; i++)
    {
        if((this->Tab[i]+EPSILON)!=W2.Tab[i]||(this->Tab[i]-EPSILON)!=W2.Tab[i])
            return false;
    }
    return true;
}

template<typename Typ, int Rozmiar>
bool Wektor<Typ, Rozmiar>::operator != (const Wektor<Typ, Rozmiar> & W2) const
{
    return !(*this==W2);
}

template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<Typ, Rozmiar> &Wek)
{
    for(int i=0; i<Rozmiar; i++)
        Strm >> Wek[i];
    return Strm;
}

template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<Typ, Rozmiar> &Wek)
{
    for(int i=0; i<Rozmiar; i++)
    {
        Strm << Wek[i];

        if(i!=Rozmiar-1)
            Strm << "\t";
    }

    return Strm;
}

template class Wektor<double, 1>;
template class Wektor<double, 2>;
template class Wektor<double, 3>;
template class Wektor<double, 4>;
template class Wektor<double, 5>;

template std::istream& operator >> (std::istream &Strm, Wektor<double, 1> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 2> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 3> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 4> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<double, 5> &Wek);

template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 1> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 2> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 5> &Wek);

