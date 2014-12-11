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
static void Menu_Escolha_Personagem(Heroi*, Grupo&);

int main()
{
 Cidade* cidade = new Sepolopolis();
 Grupo grupo;
 Heroi* heroi;
 Monstro* monstro = new Kuraudo();
 Item* espelho = new Kuraudo_Mirrors();
 Menu_Principal();
 Menu_Escolha_Personagem(heroi, grupo);

 if(monstro != 0)
 {
  grupo.Batalhar(monstro);
 }
 cidade = dynamic_cast<Sepolopolis*>(cidade);
 grupo.inventario.push_back(espelho);
 if(cidade != 0)
 {

  //cidade->Add_NPC("Ola, viajante. De boa na lagoa?");
 // cidade->Add_NPC("Voce e novo por aqui? Nao lembro de te-lo visto por aqui antes.");
 // cidade->Add_NPC("I am Error... Brincadeira XD.");
  cidade->Menu_Cidade(grupo);
 }else{
 cout << "Error. Finalizando o programa" << endl;
 exit(1);
 }
 //system("pause");
 return 0;
}


static void Menu_Principal()
{
	int opcao;
    cout << "            --/\\------------------------/\\--"  <<endl;
    cout << "              \\/   TALES OF PHANTASIA   \\/   " <<endl;
    cout << "            --------------------------------"    <<endl;
    cout << endl << endl;
    cout << "               Escolha uma das opcoes abaixo" << endl << endl;
    cout << "                   1 - Iniciar Partida     " << endl;
    cout << "                       2 - Sair                " << endl << endl;
    cout << "                  2014@ Elog Studios" << endl;
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

static void Menu_Escolha_Personagem(Heroi* heroi, Grupo& grupo){
  int opcao;
  string nome, descricao;
  cout << "Hel  lo" << endl;
  Mago mago;
  Arma* arma = new Cajado(5);
  Armadura* armadura = new Roupas_Leves;
  Acessorio* acessorio = new Anel;
  cout << grupo.equipe.size();
  system("cls");
  cout << "Digite o nome do personagem: ";
  cin >> nome;
  cout << "Digite a descricao do heroi: ";
  cin >> descricao;
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
	  heroi = new Mago(nome, descricao);
      heroi = dynamic_cast<Mago*>(heroi);

	  if(heroi != 0)
      {
       heroi->set_Arma_Heroi(arma);
       heroi->set_Armadura_Heroi(armadura);
       heroi->set_Acessorio_Heroi(acessorio);
      }else{
       cout << "ERROR. FECHANDO O JOGO!!! :(" <<endl;
       exit(1);
      }
	  opcao = 4;
	  break;
   case 2:
      cout << "Guerreiro selecionado. " << endl;
      heroi = new Guerreiro(nome, descricao);
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
      heroi = new Ladino(nome, descricao);
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
 cout << "Heroi selecionado:" << endl << endl;
 cout << endl<< heroi[0];
 grupo.set_Heroi(heroi);
}
