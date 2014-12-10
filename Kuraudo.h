#ifndef KURAUDO_H
#define KURAUDO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Monstro.h"
#include "Magia.h"
#include "Kuraudo_Mirrors.h"

using namespace std;
class Kuraudo: public Monstro
{
friend ostream& operator<<(ostream&, const Kuraudo&);
public:

	Kuraudo();
	Kuraudo(const Kuraudo&);
	~Kuraudo();

    void Def_Stats(){};
};

#endif

