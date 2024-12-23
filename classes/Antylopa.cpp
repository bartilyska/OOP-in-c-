#include "Antylopa.h"
#include <iostream>
using namespace std;
Antylopa::Antylopa(int polozenie_x, int polozenie_y, Swiat& swiat) :Zwierze(polozenie_x, polozenie_y, swiat)
{
	wiek = 0;
	sila = 4;
	inicjatywa = 4;
	oznaczenie = 'A';
	nazwa = "Antylopa";
}
Antylopa::Antylopa(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje) :
	Zwierze(polozenie_x, polozenie_y, wiek, sila, inicjatywa, oznaczenie, nazwa, swiat, zyje)
{
}
bool Antylopa::czyMozeUciec()
{
	int ucieczka = rand() % 2;
	if (ucieczka == 0)
		return false;
	int ruch_x[4] = { 1,-1,0,0 };
	int ruch_y[4] = { 0,0,1,-1};
	for (int i = 0; i < 4; i++)
	{
		int nowapoz_x = polozenie_x + ruch_x[i];
		int nowapoz_y = polozenie_y + ruch_y[i];
		if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
		{
			if (swiat.coStoi(nowapoz_x, nowapoz_y) == nullptr) //nic nie stoi tam
				return true;
		}
	}
	return false;
}
void Antylopa::ucieczka(Organizm* atakujacy)
{
	int ruch_x[4] = { 1,-1,0,0 };
	int ruch_y[4] = { 0,0,1,-1 };//antylopa ucieka
	for (int i = 0; i < 4; i++)
	{
		int nowapoz_x = polozenie_x + ruch_x[i];
		int nowapoz_y = polozenie_y + ruch_y[i];
		if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
		{
			if (swiat.coStoi(nowapoz_x, nowapoz_y) == nullptr)
			{
				swiat.usunOznaczenie(atakujacy->getPolozenie_x(), atakujacy->getPolozenie_y());
				swiat.ustawOznaczenie(polozenie_x, polozenie_y, atakujacy->getOznacznie()); //ruszenie atakujacego i antylopy
				atakujacy->setPolozenie_x(polozenie_x);
				atakujacy->setPolozenie_y(polozenie_y);
				polozenie_x = nowapoz_x;
				polozenie_y = nowapoz_y;
				swiat.ustawOznaczenie(nowapoz_x, nowapoz_y, oznaczenie);
				utworzLogUcieczka(atakujacy);
				//cout << nazwa << " uciekla na (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") przed " << atakujacy->getNazwa() << " z (" <<
					//atakujacy->getPolozenie_x() + 1 << "," << atakujacy->getPolozenie_y() + 1 << ")" << endl;
				break;
			}//musi znalezc jakies miejsce bo zostalo wczesniej sprawdzone w ifie
		}
	}
}
void Antylopa::akcja()
{
	int ruch_x[8] = { 2,-2,0,0,1,1,-1,-1 };
	int ruch_y[8] = { 0,0,2,-2,1,-1,1,-1 };
	bool wykonano = false;
	while (wykonano == false && wiek > 0)
	{
		int losuj = rand() % 8;
		int nowapoz_x = polozenie_x + ruch_x[losuj];
		int nowapoz_y = polozenie_y + ruch_y[losuj];
		if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
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
						//cout << nazwa << " (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") " << "zakaz rozmnazania z wiekiem 0" << endl;
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
void Antylopa::wstawMlode(int x, int y, Swiat& swiat)
{
	swiat.dodajOrganizm(new Antylopa(x, y, swiat));
}