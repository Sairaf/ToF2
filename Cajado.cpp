#include "Cajado.h"

Cajado::Cajado(int poder)
:Arma(poder)
{

}

Cajado::Cajado()
:Arma("Cajado", "Cajado de madeira",3,0,5,0,10)
{

}

Cajado::~Cajado()
{

}

Cajado::Cajado(const Cajado& cajado)
:Arma(cajado)
{

}

ostream& operator<<(ostream& output, const Cajado& cajado)
{
 output << static_cast <const Arma&> (cajado) <<endl;
 return output;
}

Cajado* Cajado::operator+=(const Cajado& cajado)
{
 Arma::operator+=(cajado);
 return this;
}
