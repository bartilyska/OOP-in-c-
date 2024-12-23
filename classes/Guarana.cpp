#include "Guarana.h"
#include <iostream>
using namespace std;
Guarana::Guarana(int polozenie_x, int polozenie_y, Swiat& swiat) : Roslina(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 0;
	inicjatywa = 0;
	oznaczenie = 'G';
	nazwa = "Guarana";
	szansa_zasiania = 15;
}
Guarana::Guarana(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Roslina(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
	szansa_zasiania = 15;
}
void Guarana::efektPoZjedzeniu(Organizm* atakujacy)
{
	atakujacy->setSila(atakujacy->getSila() + 3);
}
void Guarana::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new Guarana(x, y, swiat));
}
