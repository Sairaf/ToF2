#include "Dungeon.h"

const int Dungeon::MAX_SALAS = 5;

Dungeon::Dungeon(string nome, int num_Salas)
:nome_Dungeon(nome), num_Salas(num_Salas)
{

}

Dungeon::Dungeon(const Dungeon& dung_Cpy)
{
 this->nome_Dungeon = dung_Cpy.nome_Dungeon;
 this->num_Salas = dung_Cpy.num_Salas;
}

Dungeon::Dungeon(const string& nome, const int& num_Salas, const int& x)
{
 this->set_Nome(nome);
 this->set_Sala(num_Salas);
}

Dungeon::~Dungeon()
{

}

void Dungeon::set_Nome(const string& nome)
{
  if(nome.empty() == false)
    this->nome_Dungeon = nome;
  else
    this->nome_Dungeon = "Caverna";
}

void Dungeon::set_Sala(const int& num_Sala)
{
 if(num_Sala >0 && num_Sala <= 5)
    this->num_Salas = num_Sala;
 else
    this->num_Salas = 3;
}

int Dungeon::get_Sala() const
{
 return this->num_Salas;
}

string Dungeon::get_Nome() const
{
  return this->nome_Dungeon;
}

static void Verificar_Num_Salas(const Dungeon& dung)
{
 cout << "Existem "<< dung.get_Sala()<< "Salas nesta caverna" << endl;
}

ostream& operator<<(ostream& output, const Dungeon& dung)
{
 output << "Nome: " << dung.get_Nome() << endl;
 output << "Numero de salas" << dung.get_Sala() << endl;
 return output;
}

Dungeon* Dungeon::operator+=(const Dungeon& dung)
{
 this->nome_Dungeon+= this->nome_Dungeon+dung.nome_Dungeon;
 return this;
}
