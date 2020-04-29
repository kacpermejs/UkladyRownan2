#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cassert>
#include <cmath>
#include "rozmiar.h"

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
class LZespolona {
public:
  double re;    /*! Pole repezentuje czesc rzeczywista. */
  double im;    /*! Pole repezentuje czesc urojona. */


    LZespolona()
    {
        this->re = 0;
        this->im = 0;
    }

    explicit LZespolona(double rzeczywista)
    {
        this->re=rzeczywista;
        this->im=0;
    }

    LZespolona(double rzeczywista, double urojona)
    {
        this->re=rzeczywista;
        this->im=urojona;
    }
//====================================================================================
    LZespolona & operator += (const LZespolona Skl2);
    LZespolona & operator -= (const LZespolona Skl2);
    LZespolona & operator *= (const LZespolona Skl2);
    LZespolona & operator /= (const LZespolona Skl2);

    const LZespolona  operator + (const LZespolona  Skl2) const { return LZespolona(*this)+=Skl2; }

    const LZespolona  operator - (const LZespolona  Skl2) const { return LZespolona(*this)-=Skl2; }

    const LZespolona  operator * (const LZespolona  Skl2) const { return LZespolona(*this)*=Skl2; }

    const LZespolona  operator / (const LZespolona  Skl2) const { return LZespolona(*this)/=Skl2; }
//====================================================================================
    LZespolona operator = (double rzeczywista);

    LZespolona sprz() const;

    double mod() const;
//====================================================================================
    LZespolona operator += (const double rzeczywista);
    LZespolona operator -= (const double rzeczywista);
    LZespolona operator *= (const double rzeczywista);
    LZespolona operator /= (const double rzeczywista);

    const LZespolona operator + (const double rzeczywista) const { return LZespolona(*this)+=rzeczywista; }

    const LZespolona operator - (const double rzeczywista) const { return LZespolona(*this)-=rzeczywista; }

    const LZespolona operator * (const double rzeczywista) const { return LZespolona(*this)*=rzeczywista; }

    const LZespolona operator / (const double rzeczywista) const { return LZespolona(*this)/=rzeczywista; }
//====================================================================================
    bool operator == (LZespolona Skl2)const;

    bool operator != (LZespolona Skl2)const;

    bool operator == (double Skl2)const;

    bool operator != (double Skl2)const;

    const double getRE() const {return (*this).re;}
    void setRE(double rzeczywista) {(*this).re=rzeczywista;}
    const double getIM() const {return (*this).im;}
    void setIM(double urojona) {(*this).im=urojona;}

};

std::istream & operator >> (std::istream & strm, LZespolona & Skl);

std::ostream & operator << (std::ostream & strm, const LZespolona & Skl);

#endif
