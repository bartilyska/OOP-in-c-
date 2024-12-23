#include "Trawa.h"
#include <iostream>
using namespace std;
Trawa::Trawa(int polozenie_x, int polozenie_y, Swiat& swiat) : Roslina(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 0;
	inicjatywa = 0;
	oznaczenie = 'T';
	nazwa = "Trawa";
	szansa_zasiania = 15;
}
Trawa::Trawa(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Roslina(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
	szansa_zasiania = 15;
}
void Trawa::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new Trawa(x, y, swiat));
}