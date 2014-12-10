#include "Acessorio.h"

Acessorio::Acessorio(int poder)
:Equipamento(poder,0)
{

}

Acessorio::Acessorio(string nome, string desc)
:Equipamento(nome,desc)
{

}

Acessorio::Acessorio(const string& nome,const string& descricao,const int& b_Atk,const int& b_Def,const int& b_Mag,const int& p_Def,const string& elemento, const int& durabilidade)
:Equipamento(nome,descricao, b_Atk, b_Def, b_Mag, p_Def, durabilidade )
{

}

Acessorio::~Acessorio()
{
}

Acessorio::Acessorio(const Acessorio& acessorio_Cpy)
:Equipamento(acessorio_Cpy)
{

}
ostream& operator<<(ostream& output, const Acessorio& aces){
 output << static_cast <const Equipamento&> (aces) << "\n";
 output << endl;
 return output;
}

Acessorio* Acessorio::operator+=(const Acessorio& acessorio)
{
 Acessorio::operator+=(acessorio);
 return this;
}
