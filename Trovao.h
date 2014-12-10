#ifndef TROVAO_H
#define TROVAO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include "Mago.h"
#include "Magia.h"

using namespace std;
class Trovao: public Magia
{
friend ostream& operator<<(ostream&, const Trovao&);
public:

	Trovao();
	Trovao(const Trovao&);
	~Trovao();

	Trovao* operator+=(const Trovao&);
    int Efeito(const int&) ;
};


#endif
