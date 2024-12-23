#include "BarszczSosnowskiego.h"
#include "Zwierze.h"
#include <iostream>
using namespace std;
BarszczSosnowskiego::BarszczSosnowskiego(int polozenie_x, int polozenie_y, Swiat& swiat) : Roslina(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 9999;
	inicjatywa = 0;
	oznaczenie = 'B';
	nazwa = "BarszczSosnowskiego";
	szansa_zasiania = 10;
}
BarszczSosnowskiego::BarszczSosnowskiego(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Roslina(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
	szansa_zasiania = 10;
}
void BarszczSosnowskiego::akcja()
{
	if (wiek > 0)
	{
		int ruch_x[4] = { 1,-1,0,0 };
		int ruch_y[4] = { 0,0,-1,1 };
		for (int i = 0; i < 4; i++)
		{
			int nowapoz_x = polozenie_x + ruch_x[i];
			int nowapoz_y = polozenie_y + ruch_y[i];
			if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
			{
				Organizm* przeciwnik = swiat.coStoi(nowapoz_x, nowapoz_y);
				if (dynamic_cast<Zwierze*>(przeciwnik))
				{
					//cout << nazwa << " (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") zabija " << przeciwnik->getNazwa() <<
						//" (" << nowapoz_x + 1 << ", " << nowapoz_y + 1 << ")" << endl;
					utworzLogAtak(przeciwnik);
					swiat.usunOznaczenie(nowapoz_x, nowapoz_y);
					swiat.usunOrganizm(przeciwnik);
				}
			}
		}
	}
	int losuj = rand() % 100;
	if (losuj < szansa_zasiania)
	{
		int ruch_x[4] = { 1,-1,0,0 };
		int ruch_y[4] = { 0,0,-1,1 };
		int sprkierunki[4] = { 0 };
		while (wiek > 0)
		{
			int losuj = rand() % 4;
			int nowapoz_x = polozenie_x + ruch_x[losuj];
			int nowapoz_y = polozenie_y + ruch_y[losuj];
			if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
			{
				Organizm* przeciwnik = swiat.coStoi(nowapoz_x, nowapoz_y);
				if (przeciwnik == nullptr) //nic nie stoi tam
				{
					//cout << nazwa << " rozsiewa sie z (" << polozenie_x + 1 << "," << polozenie_y + 1 << ")";
					//cout << " na (" << nowapoz_x + 1 << "," << nowapoz_y + 1 << ")" << endl;
					utworzLogRozsianie(nowapoz_x, nowapoz_y);

					wstawMlode(nowapoz_x, nowapoz_y, swiat);
					swiat.ustawOznaczenie(nowapoz_x, nowapoz_y, oznaczenie);
					break;
				}
				sprkierunki[losuj] = 1;
			}
			sprkierunki[losuj] = 1;
			if (sprkierunki[0] == 1 && sprkierunki[1] == 1 && sprkierunki[2] == 1 && sprkierunki[3] == 1)
			{
				//cout << nazwa << " nie ma  miejsca by sie rozsiac" << endl;
				break;
			}
		}
	}
	wiek++;
}
void BarszczSosnowskiego::efektPoZjedzeniu(Organizm* atakujacy)
{
	swiat.usunOznaczenie(polozenie_x, polozenie_y);
	swiat.usunOrganizm(this);
}
void BarszczSosnowskiego::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new BarszczSosnowskiego(x, y, swiat));
}
