#include <locale>
#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <conio.h>
#include <vector>
#include <typeinfo>

#include "includer.h"


using namespace std;

void Imprimir(int [][TAM]);
int Pesquisar(int [][TAM], int);
Posicao get_Pos(int [][TAM]);
void Menu(int [][TAM],Posicao heroi_Pos, Grupo&);
//void Menu_Inicial();

int main(){

    //                     1 2 3 4 5
 int dungeon[TAM][TAM] = {{0,0,1,1,1},
                          {1,1,0,0,1},
                          {1,0,4,0,1},
                          {1,2,0,0,1},
                          {1,1,1,1,1}};
 Grupo* grupo = new Grupo;
 Heroi* hero = new Mago;
 Magia* magia = new Trovao;

 system("pause");
 return 0;
}







/*
void Menu_Inicial()
{
 cout << "----------------------------" <<endl;
 cout << "     TALES OF PHANTASIA     " <<endl;
 cout << "----------------------------" <<endl;
 cout << endl << endl;
 cout << "Escolha uma das opcoes abaixo" << endl << endl;
 cout << "     1 - Iniciar Partida     " << endl;
 cout << "     2 - Sair                " << endl;
}
*/
