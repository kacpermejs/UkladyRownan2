#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cassert>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona utworz(int rzeczywista, int urojona);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona sprz(LZespolona Skl1);

double mod(LZespolona Skl1);

LZespolona operator + (LZespolona zesp, double rzeczywista);

LZespolona operator - (LZespolona zesp, double rzeczywista);

LZespolona operator * (LZespolona zesp, double rzeczywista);

LZespolona operator / (LZespolona zesp, double rzeczywista);

bool operator == (LZespolona Skl1, LZespolona Skl2);

bool operator != (LZespolona Skl1, LZespolona Skl2);

std::istream & operator >> (std::istream & strm, LZespolona & Skl);

std::ostream & operator << (std::ostream & strm, const LZespolona & Skl);

#endif
