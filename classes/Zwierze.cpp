#include "Zwierze.h"
#include <iostream>
#include <string>
using namespace std;
Zwierze::Zwierze(int polozenie_x, int polozenie_y, Swiat& swiat) :Organizm(polozenie_x, polozenie_y,swiat)
{
}
Zwierze::Zwierze(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje):
	Organizm( polozenie_x,  polozenie_y,  wiek,  sila,  inicjatywa,  oznaczenie, nazwa, swiat, zyje)
{
}
void Zwierze::akcja()
{
	int ruch_x[4] = { 1,-1,0,0 };
	int ruch_y[4] = { 0,0,-1,1 };
	bool wykonano = false;
	while (wykonano == false && wiek>0)
	{
		int losuj = rand() % 4;
		int nowapoz_x = polozenie_x + ruch_x[losuj];
		int nowapoz_y = polozenie_y + ruch_y[losuj];
		if (nowapoz_x >= 0 && nowapoz_y >= 0 && nowapoz_x < swiat.getRozmiar_x() && nowapoz_y < swiat.getRozmiar_y())
		{
			Organizm* przeciwnik = swiat.coStoi(nowapoz_x, nowapoz_y);
			if (przeciwnik == nullptr) //nic nie stoi tam (lub organizm trup)
			{
				//cout << nazwa << "rusza z (" << polozenie_x + 1 << "," << polozenie_y + 1 << ")";
				swiat.usunOznaczenie(polozenie_x, polozenie_y);
				polozenie_x = nowapoz_x;
				polozenie_y = nowapoz_y;
				//cout << "i idzie na (" << nowapoz_x + 1 << "," << nowapoz_y + 1<<")" << endl;
				swiat.ustawOznaczenie(polozenie_x, polozenie_y, oznaczenie);
			}
			else
			{
				if (przeciwnik->getNazwa() == nazwa) //rozmnazanie zawsze tam bedzie ten zyjacy
				{
					if (przeciwnik->getWiek() != 0)
						rozmnazanie();
					//else
						//cout << nazwa << " (" << polozenie_x+1 << "," << polozenie_y+1 << ") " << "zakaz rozmnazania z wiekiem 0" << endl;
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
bool Zwierze::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}
bool Zwierze::czyMozeUciec()
{
	return false;
}
void Zwierze::ucieczka(Organizm* atakujacy)
{
}
void Zwierze::kolizja(Organizm* broniacy)
{
	if (broniacy->czyOdbilAtak(this))
	{
		//cout << broniacy->getNazwa() << " (" << broniacy->getPolozenie_x()+1<< "," <<broniacy->getPolozenie_y()+1<< ") " << "odbija atak" << nazwa
			//<< " (" << polozenie_x+1 << "," << polozenie_y+1 <<")" << endl;
		utworzLogOdbicie(broniacy);
	}
	else if (broniacy->czyMozeUciec())
	{
		broniacy->ucieczka(this);
	}
	else if (sila >= broniacy->getSila()) //atakujacy zajmie pozycje broniacego broniacy umiera (atakujacy to zawsze this)
	{
		//cout << nazwa << " (" << polozenie_x+1 << "," << polozenie_y+1 << ") " << "atakuje" << broniacy->getNazwa()
		//	<< " (" << broniacy->getPolozenie_x()+1 << "," << broniacy->getPolozenie_y()+1 << ") i go pokonuje" << endl;
		utworzLogWalkaWygrana(broniacy);
		broniacy->efektPoZjedzeniu(this);//this to atakujacy ktoremu trzeba zwiekszyc sile jak to guarana
		swiat.usunOznaczenie(polozenie_x, polozenie_y);
		polozenie_x=broniacy->getPolozenie_x();
		polozenie_y=broniacy->getPolozenie_y();
		swiat.ustawOznaczenie(polozenie_x, polozenie_y, oznaczenie); //czyli broniacego zostanie nadpisane
		swiat.usunOrganizm(broniacy);
	}
	else //broniacy wygral broniacy zostaje na swoim
	{
		utworzLogWalkaPrzegrana(broniacy);
		//cout << nazwa << " (" << polozenie_x + 1 << "," << polozenie_y + 1 << ") " << "atakuje" << broniacy->getNazwa()
			//<< " (" << broniacy->getPolozenie_x() + 1 << "," << broniacy->getPolozenie_y() + 1 << ") i od niego ginie" << endl;
		broniacy->efektPoZjedzeniu(this); //zabicie sie jagod i barszczu
		swiat.usunOznaczenie(polozenie_x, polozenie_y);
		swiat.usunOrganizm(this);
	}
}
void Zwierze::rozmnazanie()
{
	int kierunekx[8] = { 1,-1,0,0,1,-1,-1,1 };
	int kieruneky[8] = { 0,0,1,-1,-1,1,-1,1 }; //mozliwe miejsca by wstawic
	bool czy_rozmnozono = 0;
	for (int i = 0; i < 8; i++)
	{
		int dziecko_x = polozenie_x + kierunekx[i];
		int dziecko_y = polozenie_y + kieruneky[i];
		if (dziecko_x >= 0 && dziecko_y >= 0 && dziecko_x < swiat.getRozmiar_x() && dziecko_y < swiat.getRozmiar_y()
			&& swiat.coStoi(dziecko_x, dziecko_y)==nullptr) //mozna wtedy postawic
		{
			wstawMlode(dziecko_x, dziecko_y,swiat);
			swiat.ustawOznaczenie(dziecko_x, dziecko_y, oznaczenie);
			czy_rozmnozono = 1;
			//cout << nazwa << " (" << polozenie_x+1 << "," << polozenie_y+1 << ") " << "rozmnozyl sie" << endl;
			utworzLogRozmnozenie();
			break;
		}
	}
	//if (czy_rozmnozono == 0)
		//cout <<nazwa<<" ("<<polozenie_x+1<<","<<polozenie_y+1<< ") " << "probowal sie rozmnozyc ale nie ma miejsca"<< endl;
}
void Zwierze::utworzLogOdbicie(Organizm* broniacy)
{
	string log = broniacy->getNazwa() + " (" + to_string(broniacy->getPolozenie_x() + 1) + "," +  to_string(broniacy->getPolozenie_y() + 1) +
		") odbija atak " + nazwa +"(" + to_string(polozenie_x + 1) + "," + to_string(polozenie_y + 1) + ")";
	swiat.dodajLog(log);
}
void Zwierze::utworzLogWalkaWygrana(Organizm* broniacy)
{
	string log = nazwa + " (" + to_string(polozenie_x + 1) + "," + to_string(polozenie_y + 1) + ") atakuje " + broniacy->getNazwa() +
		" (" + to_string(broniacy->getPolozenie_x()+1) + "," + to_string(broniacy->getPolozenie_y()+1) + ") i wygrywa";
	swiat.dodajLog(log);
}
void  Zwierze::utworzLogWalkaPrzegrana(Organizm* broniacy)
{
	string log = nazwa + " (" + to_string(polozenie_x + 1) + "," + to_string(polozenie_y + 1) + ") atakuje " + broniacy->getNazwa() +
		" (" + to_string(broniacy->getPolozenie_x()+1) + "," + to_string(broniacy->getPolozenie_y()+1) + ") i od niego ginie";
	swiat.dodajLog(log);
}
void  Zwierze::utworzLogRozmnozenie()
{
	string log = nazwa + " (" + to_string(polozenie_x + 1) + "," + to_string(polozenie_y + 1) + ") rozmnozyl sie";
	swiat.dodajLog(log);
}
void  Zwierze::utworzLogUcieczka(Organizm* atakujacy)
{
	string log = nazwa + " uciekla na (" + to_string(polozenie_x + 1) + "," + to_string(polozenie_y + 1) + ") przed " + atakujacy->getNazwa() +
		" z ("+to_string(atakujacy->getPolozenie_x()+1)+","+to_string(atakujacy->getPolozenie_y()+1)+")";
	swiat.dodajLog(log);
}