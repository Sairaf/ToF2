#include "Mago.h"

Mago::Mago(string nome, string descricao)
:Heroi(nome, descricao)
{
// this->lista_Magias = new vector<Magia*>;
}

Mago::Mago(const string& nome,const string& descricao, const int& hp, const int& mp, const int& ataque, const int& defesa, const int& magia, const int& velocidade)
:Heroi(nome, descricao, hp, mp, ataque, defesa, magia, velocidade)
{
 // this->lista_Magias = new vector<Magia*>;
}

Mago::Mago(const Mago& mago_Cpy)
:Heroi(mago_Cpy)
{
 this->lista_Magias = mago_Cpy.lista_Magias;
}

Mago::~Mago(){
 int cont;
 for(cont = 0; cont < (int) this->lista_Magias.size(); cont++)
 delete [] this->lista_Magias[0];
}

void Mago::set_Magia_Mago(Magia* magia)
{
 if(magia != 0)
     this->lista_Magias.push_back(magia);
}

void Mago::Subir_De_Nivel(const int& experiencia)
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
//  this->pontosExperiencia = (floor) this->pontosExperiencia;
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

vector <Magia*> Mago::get_Magias_Mago() const{
 return this->lista_Magias;
}

void Mago::Equipar(Equipamento* equipamento)
{
 Cajado* cajado = dynamic_cast <Cajado*> (equipamento);
 if(cajado != 0)
 {
  this->set_Arma_Heroi(cajado);
 }
}

void Mago::Menu_ataque()
{
 cout << "E o turno de"<< this->get_Nome_Heroi() << endl;
 cout << "O que ele ira fazer?" << endl;
 cout << "1 - Atacar" << endl;
 cout << "2 - Usar magia" << endl;
 cout << "3 - Usar item" << endl;
}

void Mago::Show_Magics(){
 int i;
 for(i = 0; i < (int) this->lista_Magias.size(); i++)
    cout << this->lista_Magias[i]  << endl;
}


void Mago::Def_Stats(){
 this->lv_Atual =1;
 this->HP = 30;
 this->MP = 80;
 this->ataque = 5;
 this->defesa = 6;
 this->velocidade = 12;
 this->magia = 18;
}

Mago* Mago::operator+=(Mago* mago)
{
 Heroi::operator+=(mago);
 int i;
 for(i = 0; i < (int) this->lista_Magias.size(); i++)
 {
 // this->lista_Magias[i]+=magia.lista_Magias[i];
 }
 return this;
}

ostream& operator<<(ostream& output, Mago* mago)
{
 output << static_cast <const Heroi*> (mago);
 int i;
 for(i = 0; i < (int) mago->lista_Magias.size(); i++)
 {
  cout << mago->lista_Magias[i];
 }
 return output;
}
