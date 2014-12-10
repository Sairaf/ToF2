#ifndef CAVERNA_MONSTRO_H
#define CAVERNA_MONSTRO_H

#include <iostream>
#include <vector>
#include <string>
#include "Dungeon.h"
#include "Kuraudo.h"
#include "Camtasia.h"
#include "Monstro.h"

using namespace std;

class Caverna_Monstro : public Dungeon
{
 friend ostream& operator<<(ostream&, const Caverna_Monstro&)   ;
 public:
    Caverna_Monstro(string nome = "Caverna do Monstro", int salas =3 );
    Caverna_Monstro(const Caverna_Monstro&);
    virtual ~Caverna_Monstro();

    Caverna_Monstro* operator+=(const Caverna_Monstro&);
    void Salas(Grupo& grupo);
    void Mostrar_Salas(const int&);

};

#endif // DUNGEON_H



