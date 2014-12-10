#include "Roupas_Leves.h"

Roupas_Leves::Roupas_Leves()
:Armadura("Roupas leves","Roupas para o dia-a-dia", 0, 5, 0,1, 10)
{

}

Roupas_Leves::Roupas_Leves(const Roupas_Leves& roupa_Cpy)
:Armadura(roupa_Cpy)
{

}

Roupas_Leves::~Roupas_Leves()
{
}

ostream& operator<<(ostream& output, const Roupas_Leves& armadura){
 output << static_cast <const Equipamento&> (armadura) << endl;
 return output;
}

Roupas_Leves* Roupas_Leves::operator+=(const Roupas_Leves& roupas)
{
 Armadura::operator+=(roupas);
 return this;
}
