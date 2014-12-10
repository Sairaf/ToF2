#include "Camtasia.h"

Camtasia::Camtasia()
:Monstro("Camtasia", "Monstro especializado em enganar suas presas com ilusoes",210, 50, 30,30,30,30,200)
{
}

Camtasia::~Camtasia()
{

}

Camtasia::Camtasia(const Camtasia& camtasia_Cpy)
:Monstro(camtasia_Cpy)
{


}

ostream& operator<<(ostream& output, const Camtasia& camtasia)
{
 output << static_cast <const Monstro&> (camtasia) << endl;
 return output;
}

Camtasia* Camtasia::operator+=(const Camtasia& camtasia)
{
 Monstro::operator+=(camtasia);
 return this;
}
