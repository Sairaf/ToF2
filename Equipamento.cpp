#include "Equipamento.h"

int     Equipamento::max_elementos = 4;

Equipamento::Equipamento(string nome, string desc)
:Item(nome, desc)
{
 this->bonus_Atk = 0;
 this->bonus_Def = 0;
 this->bonus_Mag = 0;
 this->bonus_Vel = 0;

}


Equipamento::Equipamento(int b_Atk)
:Item()
{
 this->bonus_Atk = b_Atk;
 this->bonus_Def = 0;
 this->bonus_Mag = 0;
 this->bonus_Vel = 0;
}

Equipamento::Equipamento(int b_Atk, int dif)
:Item()
{
 dif = 0;
 this->bonus_Atk = b_Atk;
 this->bonus_Def = dif;
 this->bonus_Mag = 0;
 this->bonus_Vel = 0;
}

Equipamento::Equipamento(const string& nome,const string& descricao,const int& b_Atk,const int& b_Def,const int& b_Mag,const int& b_Vel,const int& durabilidade)
:Item(nome, descricao, durabilidade, false)
{
 this->bonus_Atk = b_Atk;
 this->bonus_Def = b_Def;
 this->bonus_Mag = b_Mag;
 this->bonus_Vel = b_Vel;
}

Equipamento::~Equipamento(){
}


Equipamento::Equipamento(const Equipamento& equipamento_Cpy)
:Item(equipamento_Cpy)
{
 this->bonus_Atk = equipamento_Cpy.bonus_Atk;
 this->bonus_Def = equipamento_Cpy.bonus_Def;
 this->bonus_Mag = equipamento_Cpy.bonus_Mag;
 this->bonus_Vel = equipamento_Cpy.bonus_Vel;
 this->Elementos = equipamento_Cpy.Elementos;
}


void Equipamento::setAtk(const int& stat){
 if(stat>= 0)
  this->bonus_Atk = stat;
 else
  this->bonus_Atk = 0;
}

void Equipamento::setDef(const int& stat){
 if(stat>= 0)
  this->bonus_Def = stat;
 else
  this->bonus_Def = 0;
}

void Equipamento::setMag(const int& stat){
 if(stat>= 0)
  this->bonus_Mag = stat;
 else
  this->bonus_Mag = 0;
}

void Equipamento::setVel(const int& stat){
 if(stat>= 0)
  this->bonus_Vel = stat;
 else
  this->bonus_Vel = 0;
}


int Equipamento::getAtk() const {
return this->bonus_Atk;
}

int Equipamento::getDef() const {
return this->bonus_Def;
}

int Equipamento::getMag() const {
return this->bonus_Mag;
}

int Equipamento::getVel() const {
return this->bonus_Vel;
}

ostream& operator<<(ostream& output, const Equipamento& equipamento){
 output << static_cast <const Item&> (equipamento) << "\n";
 output << "Bonus de ataque: " << equipamento.getAtk() << endl;
 output << "Bonus de defesa: " << equipamento.getDef() << endl;
 output << "Bonus de magia: "  << equipamento.getMag() << endl;
 output << "Bonus de velocidade: " << equipamento.getVel() << endl;
 output << endl;
 return output;
}

Equipamento* Equipamento::operator+=(const Equipamento& cpy)
{
 Equipamento::operator+=(cpy);
 this->bonus_Atk+= cpy.bonus_Atk;
 this->bonus_Def+= cpy.bonus_Def;
 this->bonus_Mag+= cpy.bonus_Mag;
 this->bonus_Vel+= cpy.bonus_Vel;
 return this;
}
