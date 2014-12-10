#include "Faca.h"

Faca::Faca()
:Arma("Faca", "Faca de cozinha ordinaria", 10,0,0,0,10)
{

}

Faca::~Faca()
{

}

Faca::Faca(const Faca& faca_Cpy)
:Arma(faca_Cpy)
{

}

void Faca::Efeito()
{
 cout << "...Nada acontece" << endl;
}

ostream& operator<<(ostream& output, const Faca& faca)
{
 output << static_cast <const Arma&> (faca) << "\n";
 return output;
}

Faca* Faca::operator+=(const Faca& faca)
{
 Arma::operator+=(faca);
 return this;
}
