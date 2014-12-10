#ifndef DUNGEON_H
#define DUNGEON_H

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include "Grupo.h"
#include "Monstro.h"
using namespace std;

class Dungeon
{
 friend ostream& operator<<(ostream&, const Dungeon&);
 protected:
     string nome_Dungeon;
     int num_Salas;
     const static int MAX_SALAS;
 public:
    Dungeon(string nome= "Caverna",int num_Salas = 3);
    Dungeon(const string&, const int&,const int&);
    Dungeon(const Dungeon&);
    virtual ~Dungeon();

    void set_Nome(const string&);
    void set_Sala(const int&);

    int get_Sala() const;
    string get_Nome() const;

    virtual void Salas(Grupo& grupo) = 0;
    virtual void Mostrar_Salas(const int& num_sala) = 0;
    static void Verificar_Num_Salas(const Dungeon&);
    Dungeon* operator+=(const Dungeon&);
};

#endif // DUNGEON_H


