#ifndef Faca_H
#define Faca_H

#include <string>
#include <iostream>
#include "Arma.h"

using namespace std;

class Faca: public Arma
{
 friend ostream& operator<<(ostream& output, const Faca&);
public:
	Faca();
	Faca(int poder = 0);
	Faca(const Faca&);
	//Faca(const string&, const string&,const int& ,const int& ,const int&,const int&, const int& );
	~Faca();

    void Efeito();
    void Add_Bonus(const int&){};

    Faca* operator+=(const Faca&);
};
#endif

