#include "Macierz.hh"


MacierzKw::MacierzKw()
{
    for(Wektor &ElemTab : Tab)
        ElemTab=Wektor();
}

MacierzKw::MacierzKw(const Wektor tablica[])
{
    for(int i=0; i<ROZMIAR; i++)
        this->Tab[i]=tablica[i];
}

MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C)
{
    this->Tab[0] = A;
    this->Tab[1] = B;
    this->Tab[2] = C;
}

double MacierzKw::wyznacznikSarrus() //tylko dla 3x3
{
    assert(ROZMIAR==3);
    double Wynik;

    return Wynik=(*this)(0,0) * (*this)(1,1) * (*this)(2,2)
                +(*this)(0,1) * (*this)(1,2) * (*this)(2,0)
                +(*this)(0,2) * (*this)(1,0) * (*this)(2,1)

                -(*this)(2,0) * (*this)(1,1) * (*this)(0,2)
                -(*this)(2,1) * (*this)(1,2) * (*this)(0,0)
                -(*this)(2,2) * (*this)(1,0) * (*this)(0,1);


}


double MacierzKw::wyznacznikLaplace()
{
    return 0; //nie działa bo nie działa rekurencja z szablonami.
              //Proba implementacji na dole w komentarzu.
}


double MacierzKw::wyznacznikGauss()
{
    double det = 1;
    MacierzKw Temp=(*this);
    for (int i = 0; i < ROZMIAR; ++i) {

        double Element = Temp[i][i];
        int iloscZer = i;
        for (int wiersz = i + 1; wiersz < ROZMIAR; ++wiersz) {
            if (std::abs(Temp(wiersz,i)) > std::abs(Element)) {
                Element = Temp[wiersz][i];
                iloscZer = wiersz;
            }
        }
        if (Element == 0) {
            return 0;
        }
        if (iloscZer != i) {
            std::swap(Temp[i],Temp[iloscZer]); //zamiana wierszy
            det *= -1;
        }
        det *= Element;

        for (int wiersz = i + 1; wiersz < ROZMIAR; ++wiersz) {
            for (int kolumna = i + 1; kolumna < ROZMIAR; ++kolumna) {
                Temp[wiersz][kolumna] -= Temp[wiersz][i] * Temp[i][kolumna] / Element;
            }
        }
    }

    return det;
}


double MacierzKw::wyznacznik(metoda met)
{
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
    return 0;
    break;
    }
    }
}


const MacierzKw MacierzKw::transponowana() const
{
    MacierzKw Temp=(*this);

    Temp.transponuj();

    return Temp;
}


void MacierzKw::transponuj()
{
    MacierzKw Temp=(*this);

    for(int i=0; i<ROZMIAR; i++)
        for(int j=0; j<ROZMIAR; j++)
            (*this)(j,i)=Temp(i,j);

}


MacierzKw & MacierzKw::operator*=(const MacierzKw & M2)
{
    MacierzKw Temp;
    for(int i=0; i<ROZMIAR; i++)
        for(int j=0; j<ROZMIAR; j++)
            for(int k=0; k<ROZMIAR; k++)
                Temp(i,j)+=(*this)(i,k)*M2(k,j);
    *this=Temp;
    return *this;
}


MacierzKw & MacierzKw::operator+=(const MacierzKw & M2)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]+=M2[i];
    return *this;
}


MacierzKw & MacierzKw::operator-=(const MacierzKw & M2)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]-=M2[i];
    return *this;
}


MacierzKw & MacierzKw::operator*=(double l)
{
    for(int i=0; i<ROZMIAR; i++)
        (*this)[i]*=l;
    return *this;
}


const Wektor MacierzKw::zwrocWiersz(int index) const
{
    assert(index>=0 && index<ROZMIAR);
    Wektor Wynik;
    for(int kol=0; kol<ROZMIAR; kol++)
        Wynik[kol]=this->Tab[kol][index];
    return Wynik;
}

//================================================================================

Wektor operator*(const MacierzKw & M1, const Wektor & W2)
{
    Wektor Wynik;

    for(int i=0; i<ROZMIAR; i++)
        for(int k=0; k<ROZMIAR; k++)
        {
            Wynik[i]+=M1(i,k)*W2[k];
        }
    return Wynik;
}

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm >> Mac[j][i];
        }
    }
    return Strm;
}


std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm << Mac[j][i] << "\t";
        }
        Strm << "\n";
    }
    return Strm;
}


/*


double MacierzKw::wyznacznikLaplace()
{
    double Wynik=0;
    double m=1;
    int k;

    if(ROZMIAR>6)
    {
        std::cerr << "Nie obslugiwana wielkosc" << std::endl;
        return 0;
    }

    MacierzKw<ROZMIAR-1> Temp;

    if(ROZMIAR==1)
        return (*this)(0,0);
    else if(ROZMIAR>=2)
    {

        for(int i=0; i<ROZMIAR; ++i)
        {
            k=0;
            for(int j=0; j<(ROZMIAR-1); ++j)
            {
                if(k==i) k++;
                for(int l=0; l<(ROZMIAR-1); ++l)
                    Temp(l,j)=(*this)(l,k++);
            }

            Wynik+=m*(*this)(0, i)*Temp.wyznacznikLaplace();
            m*=(-1);
        }

    }
    return Wynik;
}

*/
