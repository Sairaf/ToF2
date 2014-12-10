#include "Caverna_Monstro.h"

void Caverna_Monstro::Salas(Grupo& grupo)
{
 Monstro* monstro = new Kuraudo();
 Monstro* monstro2 = new Camtasia();

 srand(time(NULL));
 int opcao = 0, num_Sala = 0;
 int random = rand()%10 + 0;
 while(num_Sala >= 0 )
 {
   system("cls");
   this->Mostrar_Salas(num_Sala);
   cin >> opcao;
   while(opcao != 1 && opcao != 0)
   switch(opcao)
   {
    case 1:
        //Encontro aleatorio
     if(random == 5 && num_Sala < 5)
     {
      grupo.Batalhar(monstro2);
     }
      //movimento entre as salas
     if(num_Sala == 5) // Ultima Sala
     {
       while(opcao <0 || opcao > 1)
       {
        cout << "Desejas lutar contra o chefe (0-Y/1-N)" << endl;
        cin >> opcao;
       }
       if(opcao == 0)//Escolha se vai lutar contra o chefe
       {
        num_Sala--;
        this->Mostrar_Salas(num_Sala);
        cin >> opcao;
       }else{//Luta contra o chefe. Infepedente do resultado o jogo termina
         grupo.Batalhar(monstro);
         exit(1);
       }
     }else{// Caso nao encontre um monstroa aleatorio
       cout << "O grupo avancou" << endl;
       num_Sala++;
     }
    break;
    case 0:
     //encontro aleatorio
     if(random == 5 && num_Sala < 5)
     {
      grupo.Batalhar(monstro2);
     }

     if(num_Sala > 0)
     {
      while(opcao <0 || opcao > 1)
      {
       cout << "Desejas voltar a cidade(0-Y/1-N)" << endl;
       cin >> opcao;
      }
       if(opcao == 0)//Escolha se vai lutar contra o chefe
       {
        num_Sala--;
       }else{//Luta contra o chefe. Infepedente do resultado o jogo termina
         num_Sala++;
       }
     }else{
      num_Sala--;
      cout << "O grupo voltou" << endl;
     }

    break;
    default:
    cout <<"Opcao invalida" << endl;
    cout <<"Por favor digite novamente a sua opcao" << endl;
    cin >> opcao;
  }
 }
}

void Caverna_Monstro::Mostrar_Salas(const int& num_Sala)
{
if(num_Sala == 0)
   {
    cout << "Sala de numero"    << num_Sala << endl;
    cout << "Qual acao iras fazer?" << endl;
    cout << "1 -Prosseguir" << endl;
    cout << "0 - Sair" << endl;
   }else if(num_Sala > 0 && num_Sala < 5)
   {
    cout << "Sala de numero"    << num_Sala << endl;
    cout << "Qual acao iras fazer?" << endl;
    cout << "1 -Prosseguir" << endl;
    cout << "0 - Voltar" << endl;
   }else if(num_Sala == 5)
   {
    cout << "Sala de numero"    << num_Sala << endl;
    cout << "Qual acao iras fazer?" << endl;
    cout << "1 - Lutar contra o chefe" << endl;
    cout << "0 - Voltar" << endl;
   }
}
Caverna_Monstro::Caverna_Monstro(string nome, int salas)
:Dungeon(nome, salas)
{

}

Caverna_Monstro::Caverna_Monstro(const Caverna_Monstro& caverna)
:Dungeon(caverna)
{

}

Caverna_Monstro::~Caverna_Monstro(){}


Caverna_Monstro* Caverna_Monstro::operator+=(const Caverna_Monstro& caverna)
{
 Dungeon::operator+=(caverna);
 return this;
}

ostream& operator<<(ostream& output, const Caverna_Monstro& caverna)
{
 output << static_cast <const Dungeon&> (caverna);
 return output;
}
