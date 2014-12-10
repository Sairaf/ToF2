#include "Guerreiro.h"

Guerreiro::Guerreiro(string nome, string descricao)
:Heroi(nome,descricao)
{
}

Guerreiro::Guerreiro(const string& nome,const string& descricao,const int& hp,const int& mp,const int& ataque,const int& defesa, const int& magia,const int& velocidade)
:Heroi(nome, descricao, hp, mp, ataque, defesa, magia, velocidade)
{
}

Guerreiro::~Guerreiro(){

}

Guerreiro::Guerreiro(const Guerreiro& guerreiro_Cpy)
:Heroi(guerreiro_Cpy)
{

}


void Guerreiro::Subir_De_Nivel(const int& experiencia)
{
 srand(time(NULL));
 int b_Random = rand() %5 + 0;
 int excedente = experiencia - this->pontosExperiencia;
 this->pontosExperiencia-= experiencia;
 if(this->pontosExperiencia == 0 && this->lv_Atual <= MAX_LV){
  this->lv_Atual++;
  this->HP = 35 + b_Random;
  this->MP = 18 + b_Random;
  this->ataque = 4 + b_Random;
  this->defesa = 3 + b_Random -1;
  this->magia = b_Random;
  this->velocidade = 1 + b_Random;
  this->pontosExperiencia+= this->pontosExperiencia/10;
 }else if(this->pontosExperiencia < 0 && this->lv_Atual <= MAX_LV){
  this->lv_Atual++;
  this->HP = 35 + b_Random;
  this->MP = 18 + b_Random;
  this->ataque = 4 + b_Random;
  this->defesa = 3 + b_Random -1;
  this->magia = b_Random;
  this->velocidade = 1 + b_Random;
  this->pontosExperiencia+= this->pontosExperiencia/10;
  this->Subir_De_Nivel(excedente);
 }
}


void Guerreiro::Equipar(Equipamento* equipamento)
{
 Espada* espada = dynamic_cast<Espada*>(equipamento);
 if(espada != 0)
 {
  this->set_Arma_Heroi(espada);
 }
}

ostream& operator<<(ostream& output, const Guerreiro& heroi )
{
 output << static_cast <const Heroi&> (heroi) << endl;
 return output;
}

Guerreiro* Guerreiro::operator+=(Guerreiro* guerreiro)
{
 Heroi::operator+=(guerreiro);
 return this;
}

void Guerreiro::Def_Stats(){
 this->lv_Atual =1;
 this->HP = 100;
 this->MP = 20;
 this->ataque = 15;
 this->defesa = 14;
 this->velocidade = 5;
 this->magia = 5;
}
