#include <iostream>
#include <cstdlib>

using namespace std;

class Menu
{
protected:
	int opcao;

public:
     
	void setOpcao(const int&) ;
    	
	int getOpcao() const;
	void teste();
	
	void Menu_Principal();
	void Menu_Escolha_Personagem();
};
