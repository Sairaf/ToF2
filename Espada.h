#ifndef ESPADA_H
#define ESPADA_H

#include <string>
#include <iostream>
#include "Arma.h"

using namespace std;

class Espada: public Arma
{
 friend ostream& operator<<(ostream& output, const Espada&);
public:
	Espada();
	Espada(int poder = 0);
	Espada(const Espada&);
	//Espada(const string&, const string&,const int& ,const int& ,const int&,const int&, const int& );
	~Espada();

    void Efeito();
    void Add_Bonus(const int&){};

    Espada* operator+=(const Espada&);
};
#endif
