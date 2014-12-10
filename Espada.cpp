#include "Espada.h"

Espada::Espada()
:Arma("Espada", "Espada sem nenhuma grande diferenca", 15,0,0,0,10)
{

}

Espada::~Espada()
{

}

Espada::Espada(const Espada& espada_Cpy)
:Arma(espada_Cpy)
{

}

void Espada::Efeito()
{
 cout << "...Nada acontece";
}

ostream& operator<<(ostream& output, const Espada& espada)
{
 cout << static_cast <const Arma&>(espada) << endl;
 return output;
}

Espada* Espada::operator+=(const Espada& espada)
{
 Arma::operator+=(espada);
 return this;
}
