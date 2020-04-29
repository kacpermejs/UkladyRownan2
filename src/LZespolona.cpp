#include "LZespolona.hh"


/*!===================================================================================================
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    (*this) - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 *====================================================================================================
 */
LZespolona & LZespolona::operator += (const LZespolona  Skl2)
{
  (*this).re += Skl2.re;
  (*this).im += Skl2.im;

  return *this;
}

/*!
 * Reszta funkcji to analogiczne funkcje przeciazajace operatory.
 */

LZespolona & LZespolona::operator -= (const LZespolona  Skl2)
{
  (*this).re -= Skl2.re;
  (*this).im -= Skl2.im;

  return *this;
}

LZespolona & LZespolona::operator *= (const LZespolona  Skl2)
{
  LZespolona  Temp=(*this);

  (*this).re = Temp.re * Skl2.re - Temp.im * Skl2.im;
  (*this).im = Temp.re * Skl2.im + Temp.im * Skl2.re;

  return *this;
}

LZespolona & LZespolona::operator /= (const LZespolona  Skl2)
{
  LZespolona  Temp=(*this);

  (*this)=Temp*Skl2.sprz()/pow(Skl2.mod(), 2);

  return *this;
}

/*!==========================================================================
 * Przeciazenie operatora = ustawiajace czesc rzeczywista na podana liczbe
 * czesc urojona wtedy jest rowna 0
 *===========================================================================
 */


LZespolona LZespolona::operator = (double rzeczywista)
  {
    this->re = rzeczywista;
    this->im = 0;
    return *this;
  }

//!Funkcja zwraca sprzezenie LZespolonej
LZespolona LZespolona::sprz() const
{
  LZespolona Wynik;

  Wynik.re = (*this).re;
  Wynik.im = (-1)*(*this).im;

  return Wynik;
}
//!Funkcja zwraca modul LZespolonej
double LZespolona::mod() const
{
  double Wynik;
  Wynik=sqrt(pow((*this).re, 2)+pow((*this).im, 2));
  return Wynik;
}
/*!====================================================================================================================================
 * Ponizsze funkcje to operatory ale ze skladnikiem rzeczywistym typu double
 */
LZespolona LZespolona::operator += (const double rzeczywista)
{
  (*this).re = (*this).re+rzeczywista;
  (*this).im = (*this).im;

  return *this;
}

LZespolona LZespolona::operator -= (const double rzeczywista)
{
  (*this).re-=rzeczywista;

  return *this;
}

LZespolona LZespolona::operator *= (const double rzeczywista)
{
  (*this).re*=rzeczywista;
  (*this).im*=rzeczywista;

  return *this;
}

LZespolona LZespolona::operator /= (const double rzeczywista)
{
  assert(rzeczywista!=0);
  (*this).re/=rzeczywista;
  (*this).im/=rzeczywista;

  return *this;
}
//==========================================================================================
bool LZespolona::operator == (LZespolona Skl2) const
{
  if(std::abs((*this).re - Skl2.re) < EPSILON && std::abs((*this).re - Skl2.re) < EPSILON)
    return true;
  else
    return false;
}

bool LZespolona::operator != (LZespolona Skl2) const
{
  return !((*this)==Skl2);
}

bool LZespolona::operator == (double Skl2) const
{
  if(std::abs((*this).re - Skl2) < EPSILON && std::abs((*this).re - Skl2) < EPSILON 
    && std::abs((*this).im)<EPSILON )
    return true;
  else
    return false;
}

bool LZespolona::operator != (double Skl2) const
{
  return !((*this)==Skl2);
}
/*!
 * Funkcja pobiera i sprawdza poprawnosc formatu odpowiedzi uzyskanej od uzytkownika
 * Parametry:
 *       Skl - referencja do LZespolona
 *       strm - strumien wejsciowy danych
 *
 * Warunki wstepne:
 *      - Brak
 *
 */

std::istream & operator >> (std::istream & strm, LZespolona & Skl)
{
  char znak;
  strm>>znak;

  double rzeczywista, urojona;

  if (znak != '(')
    strm.setstate(std::ios::failbit);
  strm>>rzeczywista>>urojona>>znak;
  Skl.setRE(rzeczywista);
  Skl.setIM(urojona);
  if (znak != 'i')
    strm.setstate(std::ios::failbit);
  strm>>znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  return strm;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & Skl)
{
  strm << '(' << Skl.getRE() << std::showpos << Skl.getIM() << std::noshowpos << "i)";
  return strm;
}

