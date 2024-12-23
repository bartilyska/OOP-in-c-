#include "WilczeJagody.h"
#include <iostream>
using namespace std;
WilczeJagody::WilczeJagody(int polozenie_x, int polozenie_y, Swiat& swiat) : Roslina(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 9999;
	inicjatywa = 0;
	oznaczenie = 'J';
	nazwa = "WilczeJagody";
	szansa_zasiania = 15;
}
WilczeJagody::WilczeJagody(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Roslina(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
	szansa_zasiania = 15;
}
void WilczeJagody::efektPoZjedzeniu(Organizm* atakujacy)
{
	swiat.usunOznaczenie(polozenie_x, polozenie_y);
	swiat.usunOrganizm(this);
}
void WilczeJagody::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new WilczeJagody(x, y, swiat));
}
