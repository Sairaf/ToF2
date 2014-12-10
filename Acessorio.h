#ifndef ACESSORIO_H
#define ACESSORIO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>

#include "Equipamento.h"

using namespace std;


class Acessorio : public Equipamento
{
 friend ostream& operator<<(ostream&, const Acessorio&);
 protected:

 public:
        Acessorio(int poder = 0);
	Acessorio(string nome = "Acessorio", string descricao = "**********");
	Acessorio(const string& nome,const string& descricao,const int& b_Atk,const int& b_Def,const int& b_Mag,const int& b_Vel, const string&, const int&);
	Acessorio(const Acessorio&);
	~Acessorio();

	Acessorio* operator=(const Acessorio&);
	Acessorio* operator+=(const Acessorio&);
	virtual void Efeito() = 0;
  	//virtual void Add_Elemento(const string&) = 0;
};

#endif
