#include "Ladino.h"


Ladino::Ladino( string nome, string descricao)
:Heroi(nome, descricao)
{
}

Ladino::Ladino(const string& nome, const string& descricao, const int& hp, const int& mp, const int& ataque, const int& defesa, const int& magia, const int& velocidade)
:Heroi(nome,descricao, hp, mp, ataque, defesa, magia, velocidade)
{
}

Ladino::Ladino(const Ladino& ladino_Cpy)
:Heroi(ladino_Cpy)
{

}

Ladino::~Ladino(){

}

void Ladino::Subir_De_Nivel(const int& experiencia)
{
 srand(time(NULL));
 int b_Random = rand() %5 + 0;
 int excedente = experiencia - this->pontosExperiencia;
 this->pontosExperiencia-= experiencia;
 if(this->pontosExperiencia == 0 && this->lv_Atual <= MAX_LV){
  this->lv_Atual++;
  this->HP = 24 + b_Random;
  this->MP = 22 + b_Random;
  this->ataque = 4 + b_Random;
  this->defesa = 2 + b_Random -1;
  this->magia = 3+ b_Random;
  this->velocidade = 6 + b_Random;
  this->pontosExperiencia+= this->pontosExperiencia/10;
 }else if(this->pontosExperiencia < 0 && this->lv_Atual <= MAX_LV){
  this->lv_Atual++;
  this->HP = 24 + b_Random;
  this->MP = 22 + b_Random;
  this->ataque = 4 + b_Random;
  this->defesa = 2 + b_Random -1;
  this->magia = 3+ b_Random;
  this->velocidade = 6 + b_Random;
  this->pontosExperiencia+= this->pontosExperiencia/10;
  this->Subir_De_Nivel(excedente);
 }
}


Item* Ladino::Roubar(Monstro& monstro)
{
 int sorte = rand()%10 + 0;
 if(sorte == 5)
 {
  return monstro.get_Item();
 }else
 return NULL;
}

void Ladino::Equipar(Equipamento *equipamento)
{
 Faca* faca = dynamic_cast<Faca*>(equipamento);
 if(faca != 0)
 {
  this->set_Arma_Heroi(faca);
 }
}

void Ladino::Def_Stats(){
 this->lv_Atual =1;
 this->HP = 50;
 this->MP = 50;
 this->ataque = 12;
 this->defesa = 10;
 this->velocidade = 20;
 this->magia = 14;
}

ostream& operator<<(ostream& output, const Ladino& ladino)
{
 output << static_cast <const Heroi&> (ladino) << endl;
 return output;
}

Ladino* Ladino::operator+=(Ladino* ladino)
{
 Heroi::operator+=(ladino);
 return this;
}
