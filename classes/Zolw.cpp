#include "Zolw.h"
#include <iostream>
using namespace std;
Zolw::Zolw(int polozenie_x, int polozenie_y, Swiat& swiat) :Zwierze(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 2;
	inicjatywa = 1;
	oznaczenie = 'Z';
	nazwa = "Zolw";
}
Zolw::Zolw(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Zwierze(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
}
bool Zolw::czyOdbilAtak(Organizm* atakujacy)
{
	if (atakujacy->getSila() < 5)
		return true;
	else return false;
}
void Zolw::akcja()
{
	
	int ruch_x[4] = { 1,-1,0,0 };
	int ruch_y[4] = { 0,0,-1,1 };
	bool wykonano = false;
	while (wykonano == false && wiek > 0 )
	{
		int losuj = rand() % 4;
		int czyruch = rand() % 4;
		int nowapoz_x = polozenie_x + ruch_x[losuj];
		int nowapoz_y = polozenie_y + ruch_y[losuj];
		if (czyruch < 3)
		{
			//cout << nazwa << " (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") nie ruszyl sie" << endl;
			break;
		}
		else if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
		{
			Organizm* przeciwnik = swiat.coStoi(nowapoz_x, nowapoz_y);
			if (przeciwnik == nullptr) //nic nie stoi tam
			{
				//cout << nazwa << "rusza z (" << polozenie_x + 1 << "," << polozenie_y + 1 << ")";
				swiat.usunOznaczenie(polozenie_x, polozenie_y);
				polozenie_x = nowapoz_x;
				polozenie_y = nowapoz_y;
				//cout << "i idzie na (" << nowapoz_x + 1 << "," << nowapoz_y + 1 << ")" << endl;
				swiat.ustawOznaczenie(polozenie_x, polozenie_y, oznaczenie);
			}
			else
			{
				if (przeciwnik->getNazwa() == nazwa) //rozmnazanie
				{
					if (przeciwnik->getWiek() != 0)
						rozmnazanie();
					//else
					//	cout << nazwa << " (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") " << "zakaz rozmnazania z wiekiem 0" << endl;
				}
				else // walka
				{
					kolizja(przeciwnik);
				}
			}
			wykonano = true;
		}
	}
		wiek++;
}
void Zolw::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new Zolw(x, y, swiat));
}