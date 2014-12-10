#include "Monstro.h"


Monstro::Monstro(string nome, string descricao)
:nome_Monstro(nome), descricao_Monstro(descricao)
{

 //this->magia_Monstro = new vector <Magia*>;
 this->exp_Ganha = 1000;
 this->set_HP_Monstro(100);
 this->set_MP_Monstro(100);
 this->HP_atual = this->HP;
 this->MP_atual = this->MP;
 this->set_Atk_Monstro(10);
 this->set_Def_Monstro(10);
 this->set_Mag_Monstro(5);
 this->set_Vel_Monstro(5);
// this->drop = new Item;
}

Monstro::Monstro(const string& nome,const string& descricao_Monstro, const int& hp, const int& mp, const int& ataque, const int& defesa, const int& magia, const int& velocidade, const int& exp)
{
 //this->magia_Monstro = new vector <Magia*>;
 this->exp_Ganha = exp;
 this->set_HP_Monstro(100);
 this->set_MP_Monstro(100);
 this->HP_atual = this->HP;
 this->MP_atual = this->MP;
 this->set_Atk_Monstro(10);
 this->set_Def_Monstro(10);
 this->set_Mag_Monstro(5);
 this->set_Vel_Monstro(5);
 this->drop = 0;
}

Monstro::~Monstro()
{
// delete [] this->magia_Monstro;
 delete [] this->drop;
}

Monstro::Monstro(const Monstro& monstro_Cpy){
 this->magia_Monstro = monstro_Cpy.magia_Monstro;
 this->exp_Ganha = monstro_Cpy.exp_Ganha;
 this->HP = monstro_Cpy.HP;
 this->HP_atual = monstro_Cpy.HP_atual;
 this->MP = monstro_Cpy.MP;
 this->MP_atual = monstro_Cpy.MP_atual;
 this->ataque = monstro_Cpy.ataque;
 this->defesa = monstro_Cpy.defesa;
 this->magia = monstro_Cpy.magia;
 this->velocidade = monstro_Cpy.velocidade;
 this->drop = monstro_Cpy.drop;
}


void Monstro::set_Nome_Monstro(const string&nome){
   if(nome.empty() == false)
     this->nome_Monstro = nome;
   else
     this->nome_Monstro = "desconhecido";
}

void Monstro::set_Descricao_Monstro(const string& descricao){
   if(descricao.empty() == false)
     this->nome_Monstro = descricao;
   else
     this->nome_Monstro = "desconhecido";
}

void Monstro::set_HP_Monstro(const int& hp){
   if(hp >= 0)
     this->HP_atual = hp;
   else
    this->HP_atual = 0;
}

void Monstro::set_MP_Monstro(const int& mp){
   if(mp >= 0)
     this->MP_atual = mp;
   else
     this->MP_atual = 0;
}


void Monstro::set_HP_Atual_Monstro(const int& hp){
   if(hp >= 0)
     this->HP_atual = hp;
   else
    this->HP_atual = 0;
}

void Monstro::set_MP_Atual_Monstro(const int& mp){
   if(mp >= 0)
     this->MP_atual = mp;
   else
     this->MP_atual = 0;
}



void Monstro::set_Atk_Monstro(const int& atk){
   if(atk >= 0)
     this->ataque = atk;
   else
     this->ataque = 5;
}

void Monstro::set_Def_Monstro(const int& def){
   if(def >= 0)
     this->defesa = def;
   else
     this->defesa = 5;
}

void Monstro::set_Mag_Monstro(const int& mag){
   if(mag >= 0)
     this->magia = mag;
   else
     this->magia = 5;
}
void Monstro::set_Vel_Monstro(const int& vel){
   if(vel >= 0)
     this->velocidade = vel;
   else
     this->velocidade = 5;
}

void Monstro::set_Exp(const int& exp){
   if(exp >= 0)
     this->exp_Ganha = exp;
   else
     this->exp_Ganha = 0;
}


void Monstro::set_Habilidade_Monstro(Magia* magia){

if(magia != 0)
    this->magia_Monstro.push_back(magia);
}

void Monstro::set_Item(Item* item)
{
 if(item != 0)
    this->drop = item;
}

string Monstro::get_Nome_Monstro() const{
return this->nome_Monstro;
}

string Monstro::get_Descricao_Monstro() const{
return this->descricao_Monstro;
}


int Monstro::get_HP_Monstro() const{
return this->HP;
}

int Monstro::get_HP_Atual_Monstro() const{
return this->HP_atual;
}

int Monstro::get_MP_Monstro() const{
return this->MP_atual;
}

int Monstro::get_MP_Atual_Monstro() const{
return this->MP_atual;
}

int Monstro::get_MAX_HP_Monstro() const{
return this->max_Hp;
}

int Monstro::get_MAX_MP_Monstro() const{
return this->max_Mp;
}

int Monstro::get_Def_Monstro() const{
return this->defesa;
}


int Monstro::get_Atk_Monstro() const{
return this->ataque;
}


int Monstro::get_Mag_Monstro() const{
return this->magia;
}

int Monstro::get_Vel_Monstro() const{
return this->velocidade;
}

vector <Magia*> Monstro::get_Habilidades_Monstro() const{
return this->magia_Monstro;
}

int Monstro::get_Exp() const{
return this->exp_Ganha;
}

Item* Monstro::get_Item() const
{
 return this->drop;
}

ostream& operator<<(ostream& output, const Monstro& monstro)
{
    output << "Nome do monstro: " << monstro.get_Nome_Monstro() << endl;
    output << "Descricao: " << monstro.get_Descricao_Monstro() << endl;
    output << "Atributos:" <<endl;
    output << "HP:" << monstro.get_HP_Atual_Monstro() << "/" <<monstro.get_MAX_HP_Monstro() << endl;
    output << "MP:" << monstro.get_MP_Atual_Monstro() << "/" <<monstro.get_MAX_MP_Monstro() << endl;
    output << "Ataque: " << monstro.get_Atk_Monstro() << endl;
    output << "Defesa:" << monstro.get_Def_Monstro() << endl;
    output << "Magia:" << monstro.get_Mag_Monstro() << endl;
    output << "Velocidade:"<< monstro.get_Vel_Monstro() << endl;
    output << "Item deixado: " << monstro.get_Item() << endl;
    output << "Experiencia ganha: " << monstro.get_Exp() << endl;
    output << "Magias:" << endl;
    int i;
    for(i = 0; i < (int) monstro.magia_Monstro.size(); i++)
    {
     output << monstro.magia_Monstro[i] << endl;
    }

    return output;
}

Monstro* Monstro::operator+=(const Monstro& monstro)
{
 this->ataque+=monstro.ataque;
 this->defesa+=monstro.defesa;
 this->magia+=monstro.magia;
 this->velocidade+=monstro.velocidade;
 this->HP+=monstro.HP;
 this->MP+=monstro.MP;
 return this;
}
