#ifndef CAJADO_H
#define CAJADO_H

#include <iostream>
#include <vector>
#include <string>
#include "Arma.h"

class Cajado: public Arma
{
 friend ostream& operator<<(ostream&, const Cajado&)   ;
 public:
 Cajado(int poder = 0);
 Cajado();
 Cajado(const Cajado&);
 ~Cajado();

 inline void Efeito(){cout << "...Nada aconteceu" << endl;};
 void Add_Bonus(const int&){};
 Cajado* operator+=(const Cajado&);
};

#endif // CAJADO_H
