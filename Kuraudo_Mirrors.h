#ifndef KURAUDO_MIRRORS_H
#define KURAUDO_MIRRORS_H

#include "Item.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>


using namespace std;

class Kuraudo_Mirrors: public Item
{
friend ostream& operator<<(ostream&, const Item&);
public:
	Kuraudo_Mirrors();
	Kuraudo_Mirrors(const Kuraudo_Mirrors&);
	~Kuraudo_Mirrors();

    Kuraudo_Mirrors* operator+=(const Kuraudo_Mirrors&);
    void Diminuir_Durabilidade(){};
    void Efeito();
};


#endif

