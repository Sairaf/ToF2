#include "Cidade.h"

Cidade::Cidade(string nome)
:nome(nome)
{
 int i;
 for(i = 0; i <(int) this->npc.size();i++)
  this->npc[i] = "Default";
}

Cidade::Cidade(const Cidade & cidade_Cpy)
{
 this->nome = cidade_Cpy.nome;
 this->npc = cidade_Cpy.npc;
}

Cidade::~Cidade()
{

}

void Cidade::setNome(const string& nome)
{
 if(nome.empty() == false)
    this->nome = nome;
 else
    this->nome = "Cidade";
}

string Cidade::getNome () const
{
 return this->nome;
}

ostream& operator<<(ostream& output, const Cidade& cidade)
{
 output << "Nome da cidade: " << cidade.getNome()<< endl;
 output << "Numero de habitantes da cidade: " <<cidade.npc.size() <<endl;
 return output;
}

Cidade* Cidade::operator+=(const Cidade& cidade)
{
 vector<string> novos_Habitantes;
 int i;
 this->nome+=cidade.nome;

 for(i = 0; i <(int) this->npc.size();i++)
 {
  novos_Habitantes.push_back(this->npc[i]);
 }

 for(i = 0; i <(int) this->npc.size();i++)
 {
  novos_Habitantes.push_back(cidade.npc[i]);
 }

 this->npc = novos_Habitantes;
 return this;
}
