#ifndef GRUPO_H
#define GRUPO_H

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <conio.h>

#include "Heroi.h"
#include "Guerreiro.h"
#include "Mago.h"
#include "Ladino.h"
#include "Item.h"
#include "Monstro.h"
#include "Grupo_Geral.h"
#define TAM 5

using namespace std;


class Grupo //: public Grupo_Geral
{
  friend ostream& operator<<(ostream&, const Grupo&);
  protected:
    int MAX_HEROIS;
    int MAX_ITENS;
    int dinheiro;

  public:
    Grupo(string nome = "Grupo");
    Grupo(Heroi*,Item*);
    Grupo(const Grupo&);
    ~Grupo();
    vector <Heroi*> equipe ;
    vector <Item*> inventario;


    void set_Heroi(Heroi*);
    void set_Dinheiro(const int&);
    void set_Item(Item*);

    int get_Dinheiro() const;

    void Text_Menu();
    void Atacar(Heroi*, Monstro*);
    void Batalhar(Monstro*);
    void Ordenar_Herois();
    static void Mostrar_Herois(const Grupo&);
    static void Mostrar_Inventario(const Grupo&);
    void Usar_Item();
    static int Verificar_Dinheiro(Grupo&, const int&);
    static void Descontar_Dinheiro(Grupo&, const int&);
    Grupo* operator=(const Grupo&);
    void Menu();

    Grupo* operator+=(const Grupo&);
};
#endif // GRUPO_H
