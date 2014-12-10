#include "Grupo_Geral.h"

Grupo_Geral::Grupo_Geral(string nome )
:nome_Grupo(nome)
{

}

Grupo_Geral::Grupo_Geral(const Grupo_Geral& Cpy)
{
 this->nome_Grupo = Cpy.nome_Grupo;
}

Grupo_Geral::Grupo_Geral()
{
 this->nome_Grupo = "Grupo";
}
Grupo_Geral::~Grupo_Geral()
{

}

void Grupo_Geral::set_Nome(const string& nome)
{
 if(nome.empty() == false)
    this->nome_Grupo = nome;
 else
    this->nome_Grupo = "Grupo";
}

string Grupo_Geral::get_Nome() const
{
 return this->nome_Grupo;
}

ostream& operator<<(ostream& output, const Grupo_Geral& grupo)
{
 output << "Nome do grupo:" << grupo.get_Nome() << endl;
 return output;
}

Grupo_Geral* Grupo_Geral::operator+=(const Grupo_Geral& grupo)
{
 this->nome_Grupo+=grupo.nome_Grupo;
 return this;
}

