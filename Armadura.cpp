#include "Armadura.h"

Armadura::Armadura(const string& nome, const string& descricao, const int& atk,const int& def,const int& mag,const int& vel,const int& dur)
:Equipamento(nome, descricao, atk, def,mag,vel,dur)
{

}

Armadura::Armadura(const Armadura& armadura_Cpy)
:Equipamento(armadura_Cpy)
{

}

Armadura::Armadura(int def)
:Equipamento(def,0)
{

}

Armadura::~Armadura()
{
}

ostream& operator<<(ostream& output, const Armadura& armadura)
{
 output << static_cast <const Equipamento&> (armadura) << "\n";
 return output;
}

Armadura* Armadura::operator+=(const Armadura& armadura)
{
 Armadura::operator+=(armadura);
 return this;
}
