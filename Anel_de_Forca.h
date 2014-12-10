
#ifndef Anel_H
#define Anel_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Acessorio.h"
#include "Equipamento.h"

using namespace std;


class Anel : public Acessorio
{
 friend ostream& operator<<(ostream&, const Anel&);
 public:
    Anel(int poder = 0);
	Anel();
	Anel(const Anel&);
	~Anel();

	Anel* operator=(const string&);


    void Efeito(){};
	void Add_Bonus(const int&){};
	void Add_Elemento(const string&) ;
	Anel* operator+=(const Anel&);
};

#endif
