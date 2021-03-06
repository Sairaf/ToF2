#ifndef GRUPO_GERAL__H
#define GRUPO_GERAL_H


#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <time.h>
#include <algorithm>
#include <conio.h>

#define TAM 5

class Grupo_Geral
{
 friend ostream& operator<<(ostream&, const Grupo_Geral&)
 protected:
     string nome_Grupo;
 public:
    Grupo_Geral(string nome = "Grupo");
    Grupo_Geral(const Grupo_Geral&);
    Grupo_Geral();
    ~Grupo_Geral();

    virtual inline void Welcome(){cout << "Este e o seu grupo" << endl};
    Grupo_Geral* operator+=(const Grupo_Geral&);
};
