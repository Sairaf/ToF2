#ifndef ARMADURA_H
#define ARMADURA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Equipamento.h"


class Armadura : public Equipamento
{
 friend ostream& operator<<(ostream&, const Armadura&);
 protected:

public:
	Armadura(int b_Defesa = 0);
	Armadura(const string&, const string&, const int&,const int&,const int&,const int&,const int&);
	Armadura(const Armadura&);
	virtual ~Armadura();

	void set_P_Def(const int&);
	int get_P_Def() const;

	virtual void Add_Bonus(const int&) = 0;
	Armadura* operator+=(const Armadura&);
};

#endif
