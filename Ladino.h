#ifndef LADINO_H
#define LADINO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Monstro.h"
#include "Equipamento.h"
#include "Heroi.h"
#include "Faca.h"
class Ladino : public Heroi
{
friend ostream& operator<<(ostream&, const Ladino&);
public:

	Ladino(string nome = "Ladino", string descricao = "Ladino");
	Ladino(const string& ,const string&, const int&, const int&, const int&, const int&, const int&, const int&);
	Ladino(const Ladino&);
	virtual ~Ladino();

   	Item* Roubar(Monstro&);
	void Equipar(Equipamento*);
	void Subir_De_Nivel(const int&);
    void Def_Stats();
	void Menu_Ataque();

    Ladino* operator+=(Ladino*);
};


#endif
