#ifndef MONSTRO_H
#define MONSTRO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <string.h>
#include <time.h>

#include "Item.h"
#include "Magia.h"

class Monstro
{
friend ostream& operator<<(ostream&, const Monstro&);
protected:
   	string nome_Monstro;
	string descricao_Monstro;
	vector <Magia*> magia_Monstro;
	int HP;
	int MP;
	int HP_atual;
	int MP_atual;
	int ataque;
	int defesa;
	int velocidade;
	int magia;
	int exp_Ganha;
	Item* drop;
	static const int max_Hp = 99999;
	static const int max_Mp = 99999;



public:
	Monstro(string nome = "Monstro", string descricao = "Descricao");
	Monstro(const string&,const string&, const int&, const int&,const int&,const int&,const int&,const int&, const int&);
	Monstro(const Monstro&);
	virtual ~Monstro();

	void set_Nome_Monstro(const string&);
	void set_Descricao_Monstro(const string&);
	void set_HP_Monstro(const int&);
	void set_MP_Monstro(const int&);
	void set_HP_Atual_Monstro(const int&);
	void set_MP_Atual_Monstro(const int&);
	void set_Atk_Monstro(const int&);
	void set_Def_Monstro(const int&);
	void set_Mag_Monstro(const int&);
	void set_Vel_Monstro(const int&);
	void set_Habilidade_Monstro(Magia*);
    void set_Exp (const int&);
    void set_Item (Item*);

	string get_Nome_Monstro() const;
	string get_Descricao_Monstro() const;
	int get_HP_Monstro() const;
	int get_MAX_HP_Monstro() const;
	int get_MP_Monstro() const;
	int get_MAX_MP_Monstro() const;
	int get_HP_Atual_Monstro() const;
	int get_MP_Atual_Monstro() const;
	int get_Atk_Monstro() const;
	int get_Def_Monstro() const;
	int get_Mag_Monstro() const;
	int get_Vel_Monstro() const;
	vector <Magia*> get_Habilidades_Monstro () const;
        int get_Exp()const;
        Item* get_Item() const;

        void Atacar(const int&);
        virtual void Def_Stats() = 0;
        Monstro* operator+=(const Monstro&);
};

#endif
