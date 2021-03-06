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
 Welcome(*this);
 Dungeon* dungeon = new Caverna_Monstro();
 this->Menu_Texto_Cidade();
 cin >> opcao;
while(opcao != 5)
{
switch(opcao)
 {
  case 1:
      //Criar um item para o vendedor vender
      this->Vendedor(grupo);
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
  dungeon = dynamic_cast <Caverna_Monstro*>(dungeon);
  if(dungeon != 0)
  {
   dungeon->Salas(grupo);
  }
  break;

  case 4:
    grupo.Menu();
    getch();
    system("cls");
    this->Menu_Texto_Cidade();
    cin >> opcao;
  break;
  case 5:
    cout << "Obrigado por ter jogado" << endl;
    exit(1);
  default:
    cout <<"Opcao invalida" << endl;
    getch();
    system("cls");
    this->Menu_Texto_Cidade();
    cin >> opcao;
  }
 }
}

void Sepolopolis::Menu_Texto_Cidade()
{
 cout << "1 - Falar com o vendedor" << endl;
 cout << "2 - Falar com os moradores da cidade" <<endl;
 cout << "3 - Ir para a caverna do monstro" <<endl;
 cout << "4 - Abrir menu principal" << endl;
 cout << "5 - Sair do jogo" << endl;
}

void Sepolopolis::Vendedor(Grupo& grupo)
{
 int opcao;
 Item* espelho = new Kuraudo_Mirrors();
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
       opcao = 2;
    while(opcao != 1 && opcao != 0)
    {
     cout << "Voce quer comprar um espelho? (1 -Y/0-N)?" << endl;
     cin >> opcao;
    }

    if(opcao == 1)
    {
     if(grupo.Verificar_Dinheiro(grupo, espelho->get_Preco()) == 1)
     {

      grupo.Descontar_Dinheiro(grupo, espelho->get_Preco());
      grupo.set_Item(espelho);
      cout << "Obrigado por comprar conosco";
     }else{
      cout << "Voce nao tem dinheiro para comprar isto" << endl;
     }
    }else{
     cout << "Fica para outro dia" << endl;
    }
     cout <<endl <<endl  <<"Voce tem:" << grupo.get_Dinheiro() << endl;
     cout << "Deseja mais alguma coisa? " << endl;
     cin >> opcao;
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
