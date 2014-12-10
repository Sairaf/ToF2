#ifndef GUERREIRO_H
#define GUERREIRO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "Espada.h"
#include "Equipamento.h"
#include "Heroi.h"


class Guerreiro : public Heroi
{
 friend ostream& operator<< (ostream&, const Guerreiro&);
 public:

	Guerreiro(string nome = "Guerreiro", string descricao = "Descricao");
	Guerreiro(const string& ,const string&, const int&, const int&, const int&, const int&, const int&, const int&);
	virtual ~Guerreiro();
	Guerreiro(const Guerreiro&);

 	void Equipar(Equipamento*);
	void Subir_De_Nivel(const int&);
 	void Def_Stats();
 	Guerreiro* operator+=(Guerreiro*);
};

#endif
