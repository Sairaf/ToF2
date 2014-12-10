#include "Grupo.h"

Grupo::Grupo(string nome)
:Grupo_Geral(nome)
{

}


Grupo::Grupo(const Grupo& grupo_Cpy)
:Grupo_Geral(grupo_Cpy)
{
 this->equipe = grupo_Cpy.equipe;
 this->inventario = grupo_Cpy.inventario;
}

Grupo::Grupo(Heroi* grupo,Item* inventario)
:Grupo_Geral("Party")
{
this->equipe.push_back(grupo);
this->inventario.push_back(inventario);
}


void Grupo::set_Heroi(Heroi* heroi){
   if(this->equipe.size() < 3 /*this->MAX_HEROIS*/)
    this->equipe.push_back(heroi);
   else
    cout << "Equipe esta cheia" << endl;
 }

Grupo::~Grupo(){

}

void Grupo::set_Item(Item* item){
  if(this->inventario.size() < 99 /*this->MAX_ITENS*/)
    this->inventario.push_back(item);
   else
    cout << "Limite de itens alcançado" << endl;
}

void Grupo::set_Dinheiro(const int& dinheiro)
{
 if(dinheiro >= 0)
    this->Dinheiro = dinheiro;
 else
    this->Dinheiro = 0;
}

int Grupo::get_Dinheiro() const
{
 return this->Dinheiro;
}

void Grupo::Text_Menu()
{
 cout << "1 - Mostrar inventario"  << endl;
 cout << "2 - Mostrar status dos personagens" << endl;
 cout << "3 - Sair" <<endl;
}


void Grupo::Menu()
{
 int opcao;
 this->Text_Menu();
 cin >> opcao;
 switch(opcao)
 {


  case 1:
    cout << endl << endl;
    cout <<"--------------------------------- <<" << endl ;
    cout <<"|           Inventario           |" << endl;
    cout <<"--------------------------------- <<" <<endl ;

    Mostrar_Inventario(*this);
    cout << "Voce tem" << this->inventario.size() << " Itens" << endl;
  break;
  case 2:
    cout << endl << endl;
    cout <<"--------------------------------- <<" << endl ;
    cout <<"|           Inventario           |" << endl;
    cout <<"--------------------------------- <<" <<endl ;
    Mostrar_Herois(*this);
    cout << "Voce tem" << this->equipe.size() << " integrantes no grupo" << endl;
  break;
  case 3:
     system("cls");
     cout << "" << endl;
  break;
  default:
  system("cls");
  cout << "Opcao invalida" << endl;;
  this->Text_Menu();
  cin >> opcao;
 }
}

Grupo* Grupo::operator=(const Grupo& grupo){
    this->equipe = grupo.equipe;
    this->inventario = grupo.inventario;
    return this;
}


void Grupo::Batalhar(Monstro* monstro){

 bool pode_Batalhar_Monstro = false;
 vector <bool> apto_Grupo (this->MAX_HEROIS);
 Heroi* aux_Heroi;
 bool M_Atacou = false;
 int cont, num_Herois_apto, result= 0, max_Vel;
 int aux_Stat_Her, Magia_Utilizada, flag = 0, alvo, cont_turno;
 vector<Magia*> aux_Magia;

srand(time(NULL));
 alvo = rand()%this->equipe.size() + 0;
 Magia_Utilizada = rand()%aux_Magia.size() + 0;

  do
  {
   if(monstro->get_HP_Atual_Monstro() > 0){
   pode_Batalhar_Monstro = true;
   }else{
    pode_Batalhar_Monstro = false;
   }

   for(cont = 0; cont < (int) this->equipe.size(); cont++)
   {
   if(this->equipe[cont]->get_HP_ATUAL() > 0){
    apto_Grupo[cont]= true;
    num_Herois_apto++;
   }else{
    apto_Grupo[cont]= false;
    num_Herois_apto--;
   }
  }

  if(pode_Batalhar_Monstro == false && num_Herois_apto> 0)
  {
   cout <<" O grupo venceu a batalha" << endl;

   for(cont = 0; cont <(int)  this->equipe.size(); cont++)
   {
    this->equipe[cont]->Subir_De_Nivel(monstro->get_Exp());
   }

   result = 1;
  }else if (pode_Batalhar_Monstro == true && num_Herois_apto<= 0)
    {

   cout <<" Voce perdeu o jogo" << endl;
   result = 1;
   exit(1);

  }else{
    for(cont_turno = 0; cont_turno <(int) this->equipe.size(); cont_turno++)
    {


    this->Ordenar_Herois();
    max_Vel = this->equipe[cont_turno]->get_Vel_Heroi();
    if(monstro->get_Vel_Monstro() > max_Vel && M_Atacou == false)
     {
     alvo = rand()%this->equipe.size() + 0;
     cont = rand()%3 + 1;
     switch(cont){
     case 1: //atacar
      aux_Stat_Her = this->equipe[alvo]->get_HP_ATUAL();
      aux_Stat_Her-= 2* monstro->get_Atk_Monstro() - this->equipe[alvo]->get_Def_Heroi();
      this->equipe[alvo]->set_HP_Atual(aux_Stat_Her);
      break;
     case 2:
        //Verificando se o monstro possui magias
        aux_Magia = monstro->get_Habilidades_Monstro(); // aux_Magia  recebe as magias do monstro
        for(cont = 0; cont <(int) aux_Magia.size(); cont++){
         if(aux_Magia[cont] == 0) flag = 1;
         else flag = 0;
        }
        if(flag == 0)//verificar se o monstro tem magias
        {
         aux_Stat_Her = this->equipe[alvo]->get_HP_ATUAL();
         aux_Stat_Her-= aux_Magia[Magia_Utilizada]->Efeito(monstro->get_Mag_Monstro()) - this->equipe[alvo]->get_Mag_Heroi();
         this->equipe[alvo]->set_HP_Atual(aux_Stat_Her);
         break;
        }else{
        cout << "Monstro tenta usar magia. Nao consegue" << endl;
        }
        break;
     case 3:
        cout << monstro->get_Nome_Monstro() << " esta pensando no que fazer" << endl;
        break;
     default:
        cout << monstro->get_Nome_Monstro() << " esta pensando no que fazer" << endl;
        break;
      }
    M_Atacou = true;
    }else{
      aux_Heroi  = this->equipe[cont_turno];
      this->Atacar(aux_Heroi,monstro);
    }
   }
  }
 }while(result <=1);
}

void Grupo::Atacar(Heroi* heroi, Monstro* monstro)
{
 int opcao, hp_Monstro;
 int Magia_Utilizada;
 vector<Magia*> aux_Magia;

 Mago* aux = dynamic_cast<Mago*>(heroi);

 if(aux != 0)
 {
  heroi->Menu_ataque();
  cin >> opcao;
  while(opcao > 3 && opcao <= 0)
  {
   switch(opcao)
   {
    case 1:
     hp_Monstro = monstro->get_HP_Atual_Monstro();
     hp_Monstro-= 2*aux->get_Atk_Heroi() - monstro->get_Def_Monstro();
     monstro->set_HP_Atual_Monstro(hp_Monstro);
     break;
    case 2:
     aux_Magia = aux->get_Magias_Mago();
     aux->Show_Magics();
     cin >> Magia_Utilizada;

     hp_Monstro = monstro->get_HP_Atual_Monstro();
     hp_Monstro-= aux_Magia[Magia_Utilizada]->Efeito(heroi->get_Mag_Heroi()) - monstro->get_Def_Monstro();
     monstro->set_HP_Atual_Monstro(hp_Monstro);
     break;
    case 3:
     this->Usar_Item();
    break;
   }
  }


 }else
 {
  heroi->Menu_ataque();
  cin >> opcao;
  while(opcao > 3 && opcao <= 0)
  {
   switch(opcao)
   {
    case 1:
     hp_Monstro = monstro->get_HP_Atual_Monstro();
     hp_Monstro-= 2*aux->get_Atk_Heroi() - monstro->get_Def_Monstro();
     monstro->set_HP_Atual_Monstro(hp_Monstro);
     break;
    case 3:
     this->Usar_Item();
     break;
    default:
     system("cls");
     cout << "Opcao invalida. Digite novamente a sua acao" << endl;
     heroi->Menu_ataque();
     cin >> opcao;
     break;
    }
   }
 }
}

void Grupo::Usar_Item(){
 int opcao;
 Mostrar_Inventario(*this);
 if(opcao >= 0 && opcao <= 99)
 {
  if(this->inventario[opcao]->consumivel == false){
   //this->inventario[opcao]->Efeito();
  }else{
   this->inventario[opcao]->Efeito();
   this->inventario.erase(this->inventario.begin() + opcao);
  }
 }
}

void Grupo::Mostrar_Herois(const Grupo& grupo){
 int i;
 for(i = 0; i < (int)grupo.inventario.size(); i++)
    cout << i << " " << grupo.equipe[i] << endl;
}


void Grupo::Ordenar_Herois(){
sort(this->equipe.begin(), this->equipe.end());
}

void Grupo::Mostrar_Inventario(const Grupo& grupo)
{
 int i;
 for(i = 0; i < (int) grupo.inventario.size(); i++)
    cout << i << " " << grupo.inventario[i] << endl;
}

void Grupo::Imprimir(int dungeon [][TAM])
{
 int i, j;
 for(i = 0; i < TAM;i++){
  cout << endl;
  for(j = 0; j < TAM; j++){
   if(dungeon[i][j] == 1)
   cout << " x";
   else if(dungeon[i][j] == 2)
   cout << " C";
   else if(dungeon[i][j] == 3)
   cout << " E";
   else if(dungeon[i][j] == 4)
   cout << " L";
   else if(dungeon[i][j] == 5)
   cout << " P";
   else cout << "  " ;
 }
}
cout << endl << endl;;
}

int Grupo::Pesquisar(int dungeon [][TAM], int valor){
  int flag = 0, i = 0, j = 0, cont = 0;
  for(i = 0; i < TAM;i++){
     for(j = 0; j < TAM;j++){
       if(dungeon[i][j] == valor)    {
           flag = 1;
           cont++;
          }
         }
        }

  if(flag == 0)
    return 0;
  else
    return cont;

}

Posicao Grupo::get_Pos(int dungeon [][TAM]){
  Posicao aux;
  int flag = 0, i = 0, j = 0, cont = 0;
  for(i = 0; i < TAM;i++){
     for(j = 0; j < TAM;j++){
       if(dungeon[i][j] == 3 )    {
           flag = 1;
           cont  = 3;
           aux.c_X= j;
           aux.c_Y = i;
          }else if(dungeon[i][j] == 4  && cont != 3)    {
           flag = 1;
           cont  = 4;
           aux.c_X= j;
           aux.c_Y = i;
          }
         }
        }

  if(flag == 0){
   aux.c_X= 0;
   aux.c_Y = 0;
   return aux;
  }else{
    return aux;
   }
}


void Grupo::Menu(int dungeon[][TAM], Posicao& pos_Heroi, Grupo& grupo)
{
  system("cls");
  pos_Heroi = get_Pos(dungeon);
  dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 5;
  Imprimir(dungeon);

  string opcao;
  cout << "Escolha qual posicao queres andar" <<endl;
  cout << "U - cima; D-Baixo; L-Esquerda;R-Direita" << endl;
  cout << "Q - Sair; M - Menu" << endl;
  cin >> opcao;


  if(opcao.compare("D") == 0){
   if(pos_Heroi.c_Y + 1 <TAM && dungeon[pos_Heroi.c_Y+1][pos_Heroi.c_X] != 1)
   {
    dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 0;
    pos_Heroi.c_Y++;
   }else{
    cout << "Colisao com a parede acima" << endl;
   }
  }else if(opcao.compare("U") == 0){
   if(pos_Heroi.c_Y - 1 > 0 && dungeon[pos_Heroi.c_Y-1][pos_Heroi.c_X] != 1)
   {
    dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 0;
    pos_Heroi.c_Y--;
   }else{
    cout << "Colisao com a parede abaixo" << endl;
   }
  }else if(opcao.compare("R") == 0){
   if(pos_Heroi.c_X + 1 < TAM && dungeon[pos_Heroi.c_Y][pos_Heroi.c_X+1] != 1)
   {
    dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 0;
    pos_Heroi.c_X++;
   }else{
    cout << "Colisao com a parede direita" << endl;
   }
  }else if(opcao.compare("L") == 0){
   if(pos_Heroi.c_X - 1 > 0 && dungeon[pos_Heroi.c_Y][pos_Heroi.c_X-1] != 1)
   {
    dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 0;
    pos_Heroi.c_X++;
   }else{
    cout << "Colisao com a parede esquerda" << endl;
   }
  }else if(opcao.compare("Q") == 0){
    exit(1);
  }else if(opcao.compare("M") == 0){
    grupo.Menu();
    getch();
    system("cls");
  }else{
  cout  << "Opcao invalida" << endl;
  getch();
 }
 dungeon[pos_Heroi.c_Y][pos_Heroi.c_X] = 5;
// system("cls");
 Imprimir(dungeon);
}


ostream& operator<<(ostream& output, const Grupo grupo)
{
 int i;
 output << static_cast <const Grupo_Geral&> (grupo) << endl;
 output << "Equipe :" << endl;
 for(i = 0; i < (int) grupo.equipe.size(); i++)
 {
  output << i << ": "  ;
  output << grupo.equipe[i] << endl;
 }

 output << "Inventario: " << endl;
 for(i = 0; i < (int) grupo.inventario.size(); i++)
 {
  output << i << ": "  ;
  output << grupo.inventario[i] << endl;
 }

 output << "Dinheiro: " << grupo.get_Dinheiro() << endl;
 return output;
}

Grupo* Grupo::operator+=(const Grupo& grupo)
{
 int i;
 Grupo::operator+=(grupo);
 for(i = 0; i < (int) grupo.equipe.size(); i++)
 {
  this->equipe[i] = grupo.equipe[i];
 }

for(i = 0; i < (int) grupo.equipe.size(); i++)
 {

  this->inventario[i] = grupo.inventario[i];
 }
 return this;
}
