#include "Sepolopolis.h"

Sepolopolis::Sepolopolis(string nome)
:Cidade("Sepolopolis")
{

}

Sepolopolis::Sepolopolis(const Sepolopolis& Sepol)
:Cidade(Sepol)
{

}

Sepolopolis::~Sepolopolis(){}

void Sepolopolis::Add_NPC(const string& npc){
 if(npc.empty () == false && this->npc.size() < 5)
    this->npc.push_back(npc);

}

void Sepolopolis::Menu_Cidade(Grupo& grupo)
{
 int opcao;
 this->Menu_Texto_Cidade();
 cin >> opcao;
 switch(opcao)
 {
  case 1:
      //Criar um item para o vendedor vender
      cout << "Aparentemente o vendedor saiu de ferias" << endl;
      cout << "Volte outra hora" << endl;
      getch();
      system("cls");
      this->Menu_Texto_Cidade();
      cin >> opcao;
  break;
  case 2:
      cout << "Com qual morador voce quer falar?" << endl;
      cout << "(Escolha um numero entre 0 e" << this->npc.size() << endl;
      cin >> opcao;
      if(opcao >= 0 && opcao <= (int)this->npc.size())
      {
       cout << this->npc[opcao] << endl;
      }else{
       cout << "Opcao invalida" << endl;
      }
      getch();
      system("cls");
      this->Menu_Texto_Cidade();
      cin >> opcao;
  break;
  case 3:

  break;

  case 4:
    grupo.Menu();
    getch();
    system("cls");
    this->Menu_Texto_Cidade();
    cin >> opcao;
  break;
  default:
    cout <<"Opcao invalida" << endl;
    getch();
    system("cls");
    this->Menu_Texto_Cidade();
    cin >> opcao;
 }


}

void Sepolopolis::Menu_Texto_Cidade()
{
 cout << "1 - Falar com o vendedor" << endl;
 cout << "2 - Falar com os moradores da cidade" <<endl;
 cout << "3 - Ir para a caverna do monstro" <<endl;
 cout << "4 - Abrir menu principal" << endl;
}

void Sepolopolis::Vendedor(Grupo& grupo)
{
 int opcao;
 cout << "Bem-vindo estranho" << endl;
 cout << "Ei, queres comprar alguma coisa?" << endl << endl;
 cout << "1 - Comprar itens" <<endl;
 cout << "0 - Sair" << endl;
 cin >> opcao;
 while(opcao != 0)
 {
  switch(opcao)
  {
   case 1:
   //cout <<
   break;
  }
 }
}
ostream& operator<<(ostream& output, const Sepolopolis& sepol)
{
 output << static_cast <const Cidade&> (sepol) << endl;
 return output;
}

Sepolopolis* Sepolopolis::operator+=(const Sepolopolis& sepol)
{
 Cidade::operator+=(sepol);
 return this;
}
