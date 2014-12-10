#include "Menu.h"

void Menu::Menu_Principal()
{
	int opcao;

    cout << "----------------------------" <<endl;
    cout << "     TALES OF PHANTASIA     " <<endl;
    cout << "----------------------------" <<endl;
    cout << endl << endl;
    cout << "Escolha uma das opcoes abaixo" << endl << endl;
    cout << "     1 - Iniciar Partida     " << endl;
    cout << "     2 - Continuar Partida     " << endl;
    cout << "     3 - Sair                " << endl;

	cin >> opcao;
	while(opcao != 3){
	switch(opcao){
	 case 1:
			cout << "Iniciando jogo. " << endl;
			opcao = 3;
			break;
     case 2:
			cout << "Continuando jogo. " << endl;
			opcao = 3;
			break;
     case 3:
			cout << "Saindo do programa" << endl;
			break;
	 default:
     system("cls");
	 cout << "Opcao invalida. Por favor digite novamente a opcao";
	 cin >> opcao;
	}

 }


}

void Menu::Menu_Escolha_Personagem(){
  int opcao;
  string nome;
  system("cls");
  cout << "Digite o nome do personagem: ";
  cin >> nome;

  cout << "Escolha sua especializacao: " << endl << endl;
  cout << "1 - Mago" << endl;
  cout << "2 - Guerreiro" << endl;
  cout << "3 - Ladino" << endl;
  cout << endl << endl;
  cout << "Escolha uma das opcoes acima" << endl;
  cin >> opcao;
  cout << endl;
  switch(opcao){
	 case 1:
			cout << "Mago selecionado " << endl;
			opcao = 3;
			break;
     case 2:
			cout << "Guerreiro selecionado. " << endl;
			opcao = 3;
			break;
     case 3:
			cout << "Ladino selecionado" << endl;
			break;
	 default:
     system("cls");
	 cout << "Opcao invalida. Por favor digite novamente a opcao";
	 cin >> opcao;
	}
 }
