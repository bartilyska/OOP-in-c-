#include "Owca.h"
#include <iostream>
using namespace std;
Owca::Owca(int polozenie_x, int polozenie_y, Swiat& swiat) :Zwierze(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 4;
	inicjatywa = 4;
	oznaczenie = 'O';
	nazwa = "Owca";
}
Owca::Owca(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Zwierze(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
}
void Owca::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new Owca(x, y, swiat));
}