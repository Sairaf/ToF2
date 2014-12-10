#include "Item.h"

const int Item::MAX_DURABILIDADE = 99;

Item::Item(string nome, string descricao)
:nome_Item(nome), descricao_Item(descricao)
{
  this->durabilidade = 5;
  this->consumivel = true;
}

Item::Item(const string& nome,const string& descricao, const int& durabilidade, const bool& consumivel)
{
  this->nome_Item = nome;
  this->descricao_Item = descricao;
  this->durabilidade = durabilidade;
  this->consumivel = true;
}

Item::~Item()
{
}

Item::Item(const Item& item_Cpy){
  this->nome_Item = item_Cpy.nome_Item;
  this->descricao_Item = item_Cpy.descricao_Item;
  this->durabilidade = item_Cpy.durabilidade;
  this->consumivel = item_Cpy.consumivel;
}

void Item::set_Nome_Item(const string& nome){
  if(nome.empty() == false)
   this->nome_Item = nome;
  else
   this->nome_Item = "Desconhecido";
}
void Item::set_Descricao_Item(const string&descricao){
  if(descricao.empty() == false)
   this->descricao_Item =descricao;
  else
   this->descricao_Item = "Desconhecido";
}

void Item::set_Durabilidade(const int& durabilidade){
  if(durabilidade >= 1)
   this->durabilidade = durabilidade;
  else
    this->durabilidade = 1;
}

string Item::get_Nome_Item() const{
  return this->nome_Item;
}

string Item::get_Descricao_Item() const{
  return this->descricao_Item;
}

int Item::get_Durabilidade() const{
  return this->durabilidade;
}


ostream& operator<<(ostream& output, const Item& item){
 output << "Nome do item" << item.get_Nome_Item() << endl;
 output << "Descricao do item" << item.get_Descricao_Item() << endl;
 output << "Durabilidade" << item.get_Durabilidade() << endl;
 if(item.consumivel == true)
  output<< "Este item e consumivel"    << endl;
 else{
  output<< "Este item nao e consumivel"    << endl;
 }
 return output;
}

Item* Item::operator+=(const Item& item)
{
 this->durabilidade+= item.durabilidade;
 return this;
}

void Item::Diminuir_Durabilidade(Item& item)
{
 if(item.consumivel == true)
 {
  srand(time(NULL))   ;
  int sorte = rand()%5 +0;
  item.durabilidade-= sorte +1;
 }
}
