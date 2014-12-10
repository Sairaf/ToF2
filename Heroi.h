#ifndef HEROI_H
#define HEROI_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Armadura.h"
#include "Equipamento.h"
#include "Arma.h"
#include "Acessorio.h"

class Heroi
{
 friend ostream& operator<<(ostream&, const Heroi&);
protected:
	string nomeHeroi;
	string descricao;
	int pontosExperiencia;
  	Arma* arma;
 	Armadura* armadura;
 	Acessorio* acessorio;
    int lv_Atual;
	int HP;
	int HP_atual;
	int MP_atual;
	int MP;
	int ataque;
	int defesa;
	int velocidade;
	int magia;
    static int MAX_LV ;
	const static int MAX_HP = 9999;
	const static int MAX_MP = 9999;

public:
	Heroi(string nome = "HERO", string descricai = "UM HEROI");
	Heroi(const string& ,const string&, const int&, const int&, const int&, const int&, const int&, const int&);
	Heroi(const Heroi&);
	virtual~Heroi();

	void set_Nome_Heroi(const string&);
	void set_Descricao_Heroi(const string&);
	void set_HP_Heroi(const int&);
	void set_MP_Heroi(const int&);
	void set_HP_Atual(const int&);
	void set_MP_Atual(const int&);
	void set_Atk_Heroi(const int&);
	void set_Def_Heroi(const int&);
	void set_Mag_Heroi(const int&);
	void set_Vel_Heroi(const int&);
    	void set_Arma_Heroi(Arma*);
   	void set_Armadura_Heroi(Armadura*);
   	void set_Acessorio_Heroi(Acessorio*);


	string get_Nome_Heroi() const;
	string get_Descricao_Heroi() const;
	int    get_HP_Heroi() const;
	int    get_MAX_HP_Heroi() const;
	int    get_HP_ATUAL() const;
	int    get_MP_Heroi() const;
	int    get_MP_ATUAL() const;
	int    get_MAX_MP_Heroi() const;
	int    get_Atk_Heroi() const;
	int    get_Def_Heroi() const;
	int    get_Mag_Heroi() const;
	int    get_Vel_Heroi() const;
	Arma*  get_Arma_Heroi () const;
	Armadura*  get_Armadura_Heroi () const;
	Acessorio*  get_Acessorio_Heroi () const;
	int    get_Nivel_Heroi() const;

  	bool operator==(const int&);
  	bool operator!=(const int&);
  	bool operator==(const Heroi&);
   	bool operator!=(const Heroi&);
   	bool operator<(const Heroi&);
    	Heroi* operator=(const Heroi&);
   	Heroi* operator+=(Heroi*);

	virtual void Menu_ataque() = 0;
	virtual void Subir_De_Nivel(const int&) = 0;
	virtual void Equipar(Equipamento* equipamento) = 0;
	static Heroi* Def_Stats(Heroi*);

};


#endif
