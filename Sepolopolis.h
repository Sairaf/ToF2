#ifndef SEPOLOPOLIS_G
#define SEPOLOPOLIS_G

#include <iostream>
#include <cstdlib>
#include <string>
#include "Cidade.h"


using namespace std;

class Sepolopolis: public Cidade
{
 friend ostream& operator<<(ostream&, const Sepolopolis&);
 public:
      Sepolopolis(string nome ="Sepolopolis");
      Sepolopolis(const Sepolopolis&);
      virtual ~Sepolopolis();

  void Vendedor(Grupo&);
  void Add_NPC(const string&);
  void Menu_Cidade(Grupo&);
  void Menu_Texto_Cidade();

  Sepolopolis* operator+=(const Sepolopolis&);
};

#endif
