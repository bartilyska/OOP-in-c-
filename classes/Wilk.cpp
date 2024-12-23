#include "Wilk.h"
#include <iostream>
using namespace std;
Wilk::Wilk(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje):
	Zwierze(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
}
Wilk::Wilk(int polozenie_x, int polozenie_y, Swiat& swiat) :Zwierze(polozenie_x, polozenie_y,swiat)
{
	wiek = 0;
	sila = 9;
	inicjatywa = 5;
	oznaczenie = 'W';
	nazwa = "Wilk";
}
void Wilk::wstawMlode(int x, int y,Swiat& swiat)
{
	swiat.dodajOrganizm(new Wilk(x, y, swiat));
}