#ifndef GRUPO_GERAL_H
#define GRUPO_GERAL_H

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdlib.h>

using namespace std;

class Grupo_Geral
{
 friend ostream& operator<<(ostream&, const Grupo_Geral&);
 protected:
     string nome_Grupo;
 public:
    Grupo_Geral(string nome = "Grupo");
    Grupo_Geral(const Grupo_Geral&);
    Grupo_Geral();
    ~Grupo_Geral();

    void set_Nome(const string&);
    string get_Nome() const;

    virtual inline void Welcome(){cout << "Este e o seu grupo" << endl;};
    Grupo_Geral* operator+=(const Grupo_Geral&);
};


#endif
