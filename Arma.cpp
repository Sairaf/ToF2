#include "Arma.h"

Arma::Arma(int p_Atk)
:Equipamento(p_Atk,0)
{

}



Arma::Arma(const string& nome,const string& descricao,const int& b_Atk,const int& b_Def,const int& b_Mag,const int&b_Vel, const int& durabilidade)
:Equipamento(nome, descricao, b_Atk, b_Def, b_Mag,b_Vel, durabilidade)
{

}

Arma::~Arma()
{
}

Arma::Arma(const Arma& arma)
:Equipamento(arma)
{
 this->bonus_Atk = arma.bonus_Atk;
}

void Arma::Add_Bonus(const int& bonus){
   int aux = this->getAtk();
   aux+=bonus;
   this->setAtk(aux) ;
}

ostream& operator<<(ostream& output , const Arma& arma){
 output << static_cast <const Equipamento&> (arma) << "\n";
 return output;
}

Arma* Arma::operator+=(const Arma& arma)
{
 Arma::operator+=(arma);
 return this;
}
