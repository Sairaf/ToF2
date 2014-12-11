#include "Magia.h"

const int Magia::BONUS = 5;

Magia::Magia(string nome, int poder)
:nome_Magia(nome), poder_Magia(poder)
{
 this->set_Descricao_Magia("Desconhecida");
 this->set_Elemento_Magia("Sem tipo");
}

Magia::Magia(const string& nome, const int& poder_Magia, const string& descricao, const string& elemento)
{
  this->set_Nome_Magia(nome);
  this->set_Poder_Magia(poder_Magia);
  this->set_Descricao_Magia(descricao);
  this->set_Elemento_Magia(elemento);
}

Magia::Magia(const Magia& magia_Cpy){
  this->nome_Magia = magia_Cpy.nome_Magia;
  this->poder_Magia = magia_Cpy.poder_Magia;
  this->descricao_Magia  = magia_Cpy.descricao_Magia;
  this->elemento = magia_Cpy.elemento;
}

Magia::~Magia()
{

}

void Magia::set_Nome_Magia(const string& nome){
  if(nome.empty() == false )
  {
    this->nome_Magia = nome;
  }else{
    this->nome_Magia = "Desconhecida";
  }
}

void Magia::set_Poder_Magia(const int& poder){
  if(poder >= 0){
   this->poder_Magia = poder;
  }else{
   this->poder_Magia = 0;
  }
}

void Magia::set_Descricao_Magia(const string& descricao){
  if(descricao.empty() == false){
    this->descricao_Magia = descricao;
  }else{
    this->descricao_Magia
     = "Nao possui";
  }
}

void Magia::set_Elemento_Magia(const string& elemento){
  if(elemento.empty() == false)
   this->elemento = elemento;
  else
   this->elemento = "Sem elemento";
}

string Magia::get_Nome_Magia() const{
  return this->nome_Magia;
}

int Magia::get_Poder_Magia() const{
  return this->poder_Magia;
}

string Magia::get_Descricao_Magia() const{
  return this->descricao_Magia;
}

string Magia::get_Elemento_Magia() const{
  return this->elemento ;
}

ostream& operator<<(ostream& output, const Magia& magia){
  output << "Nome da magia: " << magia.get_Nome_Magia() << endl;
  output << "Descricao: " << magia.get_Descricao_Magia() << endl;
  output << "Poder da magia: " << magia.get_Poder_Magia() << endl;
  output << "Elemento da magia" << magia.get_Elemento_Magia() << endl;
  return output;
}

Magia* Magia::operator+=(const Magia& magia)
{
 this->poder_Magia+= magia.poder_Magia;
 return this;
}

bool Magia::operator==(const Magia& magia){
 if(this->nome_Magia == magia.nome_Magia  && this->poder_Magia == magia.poder_Magia && this->descricao_Magia == magia.descricao_Magia && this->elemento == magia.elemento)
  return true;
 else
  return false;
}

bool Magia::operator!=(const Magia& magia){
  return !(*this == magia);
}

Magia* Magia::operator=(const Magia& magia){
  this->nome_Magia = magia.nome_Magia;
  this->poder_Magia = magia.poder_Magia;
  this->descricao_Magia = magia.descricao_Magia;
  this->elemento = magia.elemento;
  return this;
}


