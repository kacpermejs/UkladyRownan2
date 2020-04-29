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
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator *= (double l)
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]*=l;

    return *this;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> & Wektor<Typ, Rozmiar>::operator /= (double l)
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
const Typ Wektor<Typ, Rozmiar>::operator * (const Wektor W2) const
{
    Typ Wynik(0);
    for(int i=0; i<Rozmiar; ++i)
    {
        Wynik+=(*this)[i]*W2[i];
    }
    return Wynik;
}

template<typename Typ, int Rozmiar>
const double Wektor<Typ, Rozmiar>::dlugosc() const //modul
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
        if(std::abs(this->Tab[i]-W2.Tab[i])>EPSILON)
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

template<>
const double Wektor<LZespolona,1>::dlugosc() const
{
    LZespolona Wynik(0);
    for(int i=0; i<1; i++)
    {
        Wynik+=(*this)[i] * (*this)[i].sprz();
    }

    return Wynik.re;
}
template<>
const double Wektor<LZespolona,2>::dlugosc() const
{
    LZespolona Wynik(0);
    for(int i=0; i<2; i++)
    {
        Wynik+=(*this)[i] * (*this)[i].sprz();
    }

    return Wynik.getRE();
}
template<>
const double Wektor<LZespolona,3>::dlugosc() const
{
    LZespolona Wynik(0);
    for(int i=0; i<3; i++)
    {
        Wynik+=(*this)[i] * (*this)[i].sprz();
    }

    return Wynik.getRE();
}
template<>
const double Wektor<LZespolona,4>::dlugosc() const
{
    LZespolona Wynik(0);
    for(int i=0; i<4; i++)
    {
        Wynik+=(*this)[i] * (*this)[i].sprz();
    }

    return Wynik.getRE();
}

template<>
const double Wektor<LZespolona,5>::dlugosc() const
{
    LZespolona Wynik(0);
    for(int i=0; i<5; i++)
    {
        Wynik+=(*this)[i] * (*this)[i].sprz();
    }

    return Wynik.getRE();
}

/*
 * specajlizacja funkcji operatora == poniewaz dla liczby zespolonej == i != z EPSILON jest zdefiniowane
 */
template<>
bool Wektor<LZespolona, 1>::operator == (const Wektor<LZespolona, 1> & W2) const
{
    for(int i=0; i<1; i++)
    {
        if(this->Tab[i] != W2.Tab[i])
            return false;
    }
    return true;
}

template<>
bool Wektor<LZespolona, 2>::operator == (const Wektor<LZespolona, 2> & W2) const
{
    for(int i=0; i<2; i++)
    {
        if(this->Tab[i] != W2.Tab[i])
            return false;
    }
    return true;
}

template<>
bool Wektor<LZespolona, 3>::operator == (const Wektor<LZespolona, 3> & W2) const
{
    for(int i=0; i<3; i++)
    {
        if(this->Tab[i] != W2.Tab[i])
            return false;
    }
    return true;
}

template<>
bool Wektor<LZespolona, 4>::operator == (const Wektor<LZespolona, 4> & W2) const
{
    for(int i=0; i<4; i++)
    {
        if(this->Tab[i] != W2.Tab[i])
            return false;
    }
    return true;
}

template<>
bool Wektor<LZespolona, 5>::operator == (const Wektor<LZespolona, 5> & W2) const
{
    for(int i=0; i<5; i++)
    {
        if(this->Tab[i] != W2.Tab[i])
            return false;
    }
    return true;
}
//==========================================================================================

template class Wektor<LZespolona, 1>;
template class Wektor<LZespolona, 2>;
template class Wektor<LZespolona, 3>;
template class Wektor<LZespolona, 4>;
template class Wektor<LZespolona, 5>;

template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 1> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 2> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 3> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 4> &Wek);
template std::istream& operator >> (std::istream &Strm, Wektor<LZespolona, 5> &Wek);

template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 1> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 2> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<LZespolona, 5> &Wek);

