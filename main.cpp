#include <iostream>
#include <cstdlib>
#include <string>
#include <string.h>
#include <conio.h>
#include <vector>
#include <typeinfo>

#include "includer.h"


using namespace std;

static void Menu_Principal();
static void Menu_Escolha_Personagem(Heroi*, Grupo*);

int main()
{
 Cidade* cidade = new Sepolopolis()   ;
 Grupo* grupo;
 Heroi* heroi;
 Heroi* heroina;

 Menu_Principal();
 Menu_Escolha_Personagem(heroi, grupo);
 cidade = dynamic_cast<Sepolopolis*>(cidade);
 //system("pause");
 return 0;
}


static void Menu_Principal()
{
	int opcao;

    cout << "--/\\------------------------/\\--" <<endl;
    cout << "  \\/   TALES OF PHANTASIA   \\/   " <<endl;
    cout << "--------------------------------" <<endl;
    cout << endl << endl;
    cout << "Escolha uma das opcoes abaixo" << endl << endl;
    cout << "     1 - Iniciar Partida     " << endl;
    cout << "     2 - Sair                " << endl;

	cin >> opcao;
	while(opcao != 3){
	switch(opcao){
	 case 1:
			cout << "Iniciando jogo. " << endl;
			opcao = 3;
			break;
	 case 2:
            cout << "Muito obrigado por jogar" << endl;
            opcao = 3;
            exit(1);
            break;
	 default:
        system("cls");
        cout << "Opcao invalida. Por favor digite novamente a opcao";
        cin >> opcao;
     break;
	}

 }


}

static void Menu_Escolha_Personagem(Heroi* heroi, Grupo* grupo){
  int opcao;
  string nome;
  Mago mago;
  Arma* arma = new Cajado(5);
  grupo->set_Heroi(&mago);
  system("cls");
  cout << "Digite o nome do personagem: ";
  cin >> nome;
  cout << "Escolha sua especializacao: " << endl << endl;
  cout << "1 - Mago" << endl;
  cout << "2 - Guerreiro" << endl;
  cout << "3 - Ladino" << endl;
  cout << endl << endl;
  cout << "Escolha uma das opcoes acima:" << endl;
  cout << "(Escolha uma... Escolha sabiamente)" << endl;
  cin >> opcao;
  cout << endl;
 while(opcao != 4)
 {
  switch(opcao)
  {
   case 1:
	  cout << "Mago selecionado " << endl;
	  heroi = new Mago(nome);
      heroi = dynamic_cast<Mago*>(heroi);

	  if(heroi != 0)
      {
       heroi->set_Arma_Heroi(arma);
       cout << endl<< heroi[0];
       grupo->set_Heroi(heroi);
      }else{
       cout << "ERROR. FECHANDO O JOGO!!! :(" <<endl;
       exit(1);
      }
	  opcao = 4;
	  break;
   case 2:
      cout << "Guerreiro selecionado. " << endl;
      heroi = new Guerreiro();
      heroi = dynamic_cast<Guerreiro*>(heroi);

	  if(heroi != 0)
      {
      }else{
       cout << "ERROR. FECHANDO O JOGO!!! :(" <<endl;
       exit(1);
      }
	  opcao = 4;
	  break;
   case 3:
      cout << "Ladino selecionado" << endl;
      heroi = new Ladino(nome);
      heroi = dynamic_cast<Ladino*>(heroi);

	  if(heroi != 0)
      {
      }else{
       cout << "ERROR. FECHANDO O JOGO!!! :(" <<endl;
       exit(1);
      }
	  opcao = 4;
	  break;
   default:
      system("cls");
      cout << "Opcao invalida. Por favor digite novamente a opcao";
      cin >> opcao;
   break;
  }
 }

}
