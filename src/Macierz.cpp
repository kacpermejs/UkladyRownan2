#include "Macierz.hh"


template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar>::MacierzKw()
{
    for(Wektor<Typ, Rozmiar> &ElemTab : Tab)
        ElemTab=Wektor<Typ, Rozmiar>();
}

template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar>::MacierzKw(const Wektor<Typ, Rozmiar> tablica[])
{
    for(int i=0; i<Rozmiar; i++)
        this->Tab[i]=tablica[i];
}

/*
template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar>::MacierzKw(Wektor<Typ, Rozmiar> A, Wektor B, Wektor C)
{
    this->Tab[0] = A;
    this->Tab[1] = B;
    this->Tab[2] = C;
}*/

template<typename Typ, int Rozmiar>
const Typ MacierzKw<Typ, Rozmiar>::wyznacznikSarrus() //tylko dla 3x3
{
    assert(Rozmiar==3);
    Typ Wynik;

    return Wynik=(*this)(0,0) * (*this)(1,1) * (*this)(2,2)
                +(*this)(0,1) * (*this)(1,2) * (*this)(2,0)
                +(*this)(0,2) * (*this)(1,0) * (*this)(2,1)

                -(*this)(2,0) * (*this)(1,1) * (*this)(0,2)
                -(*this)(2,1) * (*this)(1,2) * (*this)(0,0)
                -(*this)(2,2) * (*this)(1,0) * (*this)(0,1);


}

template<typename Typ, int Rozmiar>
const Typ MacierzKw<Typ, Rozmiar>::wyznacznikLaplace()
{
    Typ Wynik(0);
    return Wynik; //nie działa bo nie działa rekurencja z szablonami.
              //Proba implementacji na dole w komentarzu.
}
/*
template<typename Typ, int Rozmiar>
const Typ MacierzKw<Typ, Rozmiar>::wyznacznikLaplace()
{
    Typ Wynik(0);
    double m=1;
    int k;

    MacierzKw<Typ, Rozmiar-1> Temp;

    if(Rozmiar==1)
        return (*this)(0,0);
    else if(Rozmiar>=2)
    {

        for(int i=0; i<Rozmiar; ++i)
        {
            k=0;
            for(int j=0; j<(Rozmiar-1); ++j)
            {
                if(k==i) k++;
                for(int l=0; l<(Rozmiar-1); ++l)
                    Temp(l,j)=(*this)(l,k++);
            }

            Wynik+=(*this)(0, i)*Temp.wyznacznikLaplace()*m;
            m*=(-1);
        }

    }
    return Wynik;
}*/

template<typename Typ, int Rozmiar>
const Typ MacierzKw<Typ, Rozmiar>::wyznacznikGauss()
{
    Typ det(1);
    MacierzKw<Typ, Rozmiar> Temp=(*this);
    for (int i = 0; i < Rozmiar; ++i)
    {

        Typ Element = Temp(i,i);
        int przekatna = i;
        for (int kolumna = i + 1; kolumna < Rozmiar; ++kolumna)
        {
            if (AbsV(Temp(i,kolumna)) > AbsV(Element))
            {
                Element = Temp(i, kolumna);
                przekatna = kolumna;
            }
        }
        if (Element == 0)
        {
            det = 0;
            return det;
        }
        if (przekatna != i)
        {
            std::swap(Temp[i],Temp[przekatna]); //zamiana kolumn
            det *= -1;
        }
        det *= Element;

        for (int kolumna = i + 1; kolumna < Rozmiar; ++kolumna)
        {
            for (int wiersz = i + 1; wiersz < Rozmiar; ++wiersz)
            {
                Temp(wiersz,kolumna) -= Temp(i,kolumna) * Temp(wiersz,i) / Element;
            }
        }
    }

    return det;
}

template<typename Typ, int Rozmiar>
const Typ MacierzKw<Typ, Rozmiar>::wyznacznik(metoda met)
{
    Typ det(0);
    switch(met)
    {
    case LAPLACE:
    {
        return this->wyznacznikLaplace();
        break;
    }
    case GAUSS:
    {
        return this->wyznacznikGauss();
        break;
    }
    case SARRUS:
    {
        return this->wyznacznikSarrus();
        break;
    }
    default:
    {
    return det;
    break;
    }
    }
}

template<typename Typ, int Rozmiar>
const MacierzKw<Typ, Rozmiar> MacierzKw<Typ, Rozmiar>::transponowana() const
{
    MacierzKw<Typ, Rozmiar> Temp=(*this);

    Temp.transponuj();

    return Temp;
}

template<typename Typ, int Rozmiar>
void MacierzKw<Typ, Rozmiar>::transponuj()
{
    MacierzKw<Typ, Rozmiar> Temp=(*this);

    for(int i=0; i<Rozmiar; i++)
        for(int j=0; j<Rozmiar; j++)
            (*this)(j,i)=Temp(i,j);

}

template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar> & MacierzKw<Typ, Rozmiar>::operator*=(const MacierzKw<Typ, Rozmiar> & M2)
{
    MacierzKw<Typ, Rozmiar> Temp;
    for(int i=0; i < Rozmiar; i++)
        for(int j=0; j < Rozmiar; j++)
            for(int k=0; k < Rozmiar; k++)
                Temp(i,j)+=(*this)(i,k)*M2(k,j);
    *this=Temp;
    return *this;
}

template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar> & MacierzKw<Typ, Rozmiar>::operator+=(const MacierzKw<Typ, Rozmiar> & M2)
{
    for(int i=0; i < Rozmiar; i++)
        (*this)[i]+=M2[i];
    return *this;
}

template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar> & MacierzKw<Typ, Rozmiar>::operator-=(const MacierzKw<Typ, Rozmiar> & M2)
{
    for(int i=0; i < Rozmiar; i++)
        (*this)[i]-=M2[i];
    return *this;
}

template<typename Typ, int Rozmiar>
MacierzKw<Typ, Rozmiar> & MacierzKw<Typ, Rozmiar>::operator*=(double l)
{
    for(int i=0; i < Rozmiar; i++)
        (*this)[i]*=l;
    return *this;
}

template<typename Typ, int Rozmiar>
const Wektor<Typ, Rozmiar> MacierzKw<Typ, Rozmiar>::zwrocWiersz(int index) const
{
    assert(index>=0 && index<Rozmiar);
    Wektor<Typ, Rozmiar> Wynik;
    for(int kol=0; kol<Rozmiar; kol++)
        Wynik[kol]=this->Tab[kol][index];
    return Wynik;
}

template<typename Typ, int Rozmiar>
Wektor<Typ, Rozmiar> MacierzKw<Typ, Rozmiar>::operator*(const Wektor<Typ, Rozmiar>& W2) const
{
    Wektor<Typ, Rozmiar> Wynik;

    for(int i=0; i < Rozmiar; i++)
        for(int k=0; k < Rozmiar; k++)
        {
            Wynik[i]+=(*this)(i,k)*W2[k];
        }
    return Wynik;
}
//==========================================================================================================

template<typename Typ, int Rozmiar>
std::istream& operator >> (std::istream &Strm, MacierzKw<Typ, Rozmiar> &Mac)
{
    for(int i=0; i < Rozmiar; i++)
    {
        for(int j=0; j < Rozmiar; j++)
        {
            Strm >> Mac[j][i];
        }
    }
    return Strm;
}

template<typename Typ, int Rozmiar>
std::ostream& operator << (std::ostream &Strm, const MacierzKw<Typ, Rozmiar> &Mac)
{
    for(int i=0; i < Rozmiar; i++)
    {
        for(int j=0; j < Rozmiar; j++)
        {
            Strm << Mac[j][i] << "\t";
        }
        Strm << "\n";
    }
    return Strm;
}

template class MacierzKw<double, 1>;
template class MacierzKw<double, 2>;
template class MacierzKw<double, 3>;
template class MacierzKw<double, 4>;
template class MacierzKw<double, 5>;

template std::istream& operator >> (std::istream &Strm, MacierzKw<double, 1> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<double, 2> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<double, 3> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<double, 4> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<double, 5> &Mac);

template std::ostream& operator << (std::ostream &Strm, const MacierzKw<double, 1> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<double, 2> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<double, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<double, 4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<double, 5> &Mac);

template class MacierzKw<LZespolona, 1>;
template class MacierzKw<LZespolona, 2>;
template class MacierzKw<LZespolona, 3>;
template class MacierzKw<LZespolona, 4>;
template class MacierzKw<LZespolona, 5>;

template std::istream& operator >> (std::istream &Strm, MacierzKw<LZespolona, 1> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<LZespolona, 2> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<LZespolona, 3> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<LZespolona, 4> &Mac);
template std::istream& operator >> (std::istream &Strm, MacierzKw<LZespolona, 5> &Mac);

template std::ostream& operator << (std::ostream &Strm, const MacierzKw<LZespolona, 1> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<LZespolona, 2> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<LZespolona, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<LZespolona, 4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const MacierzKw<LZespolona, 5> &Mac);




