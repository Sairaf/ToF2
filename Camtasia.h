#ifndef CAMTASIA_H
#define CAMTASIA_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Monstro.h"
#include "Magia.h"

using namespace std;
class Camtasia: public Monstro
{
friend ostream& operator<<(ostream&, const Camtasia&);
public:
    Camtasia();
    Camtasia(int hp, int mp, int ataque, int defesa, int magia, int velocidade);
	Camtasia(const Camtasia&);
	virtual ~Camtasia();

    void Def_Stats(){};
    Camtasia* operator+=(const Camtasia&);
};

#endif
