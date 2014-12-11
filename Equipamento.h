#ifndef EQUIPAMENTO_H
#define EQUIPAMENTO_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Item.h"

class Equipamento : public Item
{
friend ostream& operator<<(ostream&, const Equipamento&);
protected:
	int bonus_Atk;
	int bonus_Def;
	int bonus_Mag;
	int bonus_Vel;
    vector <string> Elementos;
    static int max_elementos;
public:
	Equipamento(string nome = "Equipamento", string descricao = "**********");
	Equipamento(int bonus = 0);
	Equipamento(int bonus = 0, int dif = 0);
	Equipamento(const Equipamento&);
	Equipamento(const string& nome,const string& descricao, const int&, const int&, const int&, const int&, const int&, const int&);
	virtual ~Equipamento();

	void setAtk(const int&);
	void setDef(const int&);
	void setMag(const int&);
	void setVel(const int&);
    void setElement(const string&);


	int getAtk() const;
	int getDef() const;
	int getMag() const;
	int getVel() const;
    vector <string> getElement() const;

    virtual void Efeito() = 0;
	virtual void Add_Bonus(const int&) = 0;

    Equipamento* operator+=(const Equipamento&);

};


#endif
