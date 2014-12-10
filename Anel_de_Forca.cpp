#include "Anel_de_Forca.h"

Anel::Anel(int poder)
:Acessorio(poder)
{


}

Anel::Anel()
:Acessorio("Anel de forca", "Anel que concede um bonus de forca ao usuario",1,1,0,0,"Fogo",15)
{

}

Anel::Anel(const Anel& Anel_Cpy)
:Acessorio(Anel_Cpy)
{

}

Anel::~Anel()
{

}
void Anel::Add_Elemento(const string& elemento)
{
 cout << "A ser implementado" << endl;
}

ostream& operator<<(ostream& output, const Anel& anel)
{
 output << static_cast <const Acessorio&> (anel) <<endl;
 output << "Isto e um acessorio" << endl;
 return output;
}

Anel* Anel::operator+=(const Anel& anel)
{
 Acessorio::operator+=(anel);
 return this;
}

