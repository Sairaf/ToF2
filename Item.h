#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

using namespace std;

class Item
{
friend ostream& operator<<(ostream&, const Item&);
protected:
	string nome_Item;
	string descricao_Item;
	int durabilidade;
    const static int MAX_DURABILIDADE;
    int preco;
public:
    bool consumivel;
	Item(string nome = "Item", string descricao = "Um item");
	Item(const string& nome,const string& descricao, const int& durabilidade, const bool&, const int&);
	Item(const Item&);
	virtual  ~Item();

	void set_Nome_Item(const string&);
	void set_Descricao_Item(const string&);
	void set_Durabilidade(const int&);
    void set_Preco(const int&);

	string get_Nome_Item      () const;
	string get_Descricao_Item () const;
	int    get_Durabilidade   () const;
    int    get_Preco          () const;

	static void Diminuir_Durabilidade(Item& item);

    virtual void Efeito() = 0;
    Item* operator+=(const Item&);
};


#endif
