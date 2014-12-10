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

typedef struct {
  int c_X;
  int c_Y;
}Posicao;


class Grupo : public Grupo_Geral
{
  friend ostream& operator<<(ostream&, const Grupo&);
  protected:
    int MAX_HEROIS;
    int MAX_ITENS;
    int Dinheiro;

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
    void Imprimir(int [][TAM]);
    int  Pesquisar(int [][TAM], int );
    void Menu(int [][TAM], Posicao&, Grupo&);
    Posicao get_Pos(int  [][TAM]);

    void Text_Menu();
    void Atacar(Heroi*, Monstro*);
    void Batalhar(Monstro*);
    void Ordenar_Herois();
    static void Mostrar_Herois(const Grupo&);
    static void Mostrar_Inventario(const Grupo&);
    void Usar_Item();
    Grupo* operator=(const Grupo&);
    void Menu();

    Grupo* operator+=(const Grupo&);
};
#endif // GRUPO_H
