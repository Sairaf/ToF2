#ifndef Roupas_Leves_H
#define Roupas_Leves_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Armadura.h"


class Roupas_Leves : public Armadura
{
 friend ostream& operator<<(ostream&, const Roupas_Leves&);
 protected:

public:
	Roupas_Leves();
	~Roupas_Leves();
    Roupas_Leves(const Roupas_Leves&);
    void Efeito(){};
	void Add_Bonus(const int&){};
};

#endif

