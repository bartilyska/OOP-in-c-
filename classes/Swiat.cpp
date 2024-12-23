#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h"
#include "Owca.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Roslina.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <Windows.h>
using namespace std;
Swiat::Swiat(int x, int y):rozmiar_x(x),rozmiar_y(y),kierunek_czlowieka(""),cooldown_mocy(0)
{
	plansza.resize(y, vector<char> (x));
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			plansza[i][j] = '.';
		}
	}
	//dodawanie startowych organizmow do wektora
	/*organizmy.push_back(new Antylopa(2, 2, *this));
	organizmy.push_back(new Lis(3, 3, *this));
	organizmy.push_back(new Antylopa(0, 0, *this));
	organizmy.push_back(new Czlowiek(1, 2, *this));
	organizmy.push_back(new Owca(1, 1, *this));
	organizmy.push_back(new Zolw(4, 2, *this));
	organizmy.push_back(new Wilk(0, 2, *this));
	organizmy.push_back(new Antylopa(0, 3, *this));
	organizmy.push_back(new Antylopa(0, 4, *this));
	organizmy.push_back(new Owca(0, 5, *this));
	organizmy.push_back(new BarszczSosnowskiego(0, 6, *this));
	organizmy.push_back(new WilczeJagody(0, 8, *this));
	organizmy.push_back(new Guarana(9,8, *this));
	organizmy.push_back(new Trawa(9,9, *this));
	organizmy.push_back(new Antylopa(8, 7, *this));
	organizmy.push_back(new Lis(7, 7, *this));*/
	vector<pair<int, int>>pozycje;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			pozycje.push_back({ i,j });
		}
	}
	int ileorg = x * y / 50;
	int indeks = rand() % pozycje.size();
	auto para = pozycje[indeks];
	pozycje.erase(pozycje.begin() + indeks);
	organizmy.push_back(new Czlowiek(para.second, para.first, *this));
	vector<pair<int, int>> wylosowane;
	for (int i = 0; i < ileorg; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			indeks = rand() % pozycje.size();
			wylosowane.push_back(pozycje[indeks]);
			pozycje.erase(pozycje.begin() + indeks);
		}
		organizmy.push_back(new Antylopa(wylosowane[0].second, wylosowane[0].first, *this));
		organizmy.push_back(new BarszczSosnowskiego(wylosowane[1].second, wylosowane[1].first, *this));
		organizmy.push_back(new Guarana(wylosowane[2].second, wylosowane[2].first, *this));
		organizmy.push_back(new Lis(wylosowane[3].second, wylosowane[3].first, *this));
		organizmy.push_back(new Mlecz(wylosowane[4].second, wylosowane[4].first, *this));
		organizmy.push_back(new Owca(wylosowane[5].second, wylosowane[5].first, *this));
		organizmy.push_back(new Trawa(wylosowane[6].second, wylosowane[6].first, *this));
		organizmy.push_back(new WilczeJagody(wylosowane[7].second, wylosowane[7].first, *this));
		organizmy.push_back(new Wilk(wylosowane[8].second, wylosowane[8].first, *this));
		organizmy.push_back(new Zolw(wylosowane[9].second, wylosowane[9].first, *this));
		wylosowane.clear();
	}
}
int Swiat::getCooldownMoc()
{
	return cooldown_mocy;
}
void Swiat::setCooldownMoc(int moc)
{
	cooldown_mocy = moc;
}
void Swiat::usunOrganizm(Organizm* org) //oznacza zycie=false
{
	org->setZyje(false);
}
void Swiat::dodajOrganizm(Organizm* org)
{
	organizmy.push_back(org);
}
void Swiat::dodajOrganizmNaPlansze(Organizm* org)
{
	plansza[org->getPolozenie_y()][org->getPolozenie_x()] = org->getOznacznie();
}
Organizm* Swiat::coStoi(int x, int y)
{
	if (plansza[y][x] == '.')
		return nullptr;
	for (auto organizm : organizmy)
	{
		if (organizm->getPolozenie_y() == y && organizm->getPolozenie_x() == x && organizm->getZyje()==true)//organizm ma zyc a nie trup
			return organizm;
	}
	return nullptr;
}
bool Swiat::porownajOrganizmy(Organizm* org1, Organizm* org2)
{
	if (org1->getInicjatywa() > org2->getInicjatywa())
		return true;
	else if (org1->getInicjatywa() == org2->getInicjatywa())
	{
		if (org1->getWiek() > org2->getWiek())
			return true;
		else return false;
	}
	else return false;
}
void Swiat::wykonajTure()
{
	sort(organizmy.begin(), organizmy.end(), [this](Organizm* org1, Organizm* org2) { //trzeba zachowac this 
		return porownajOrganizmy(org1, org2);
	});
	for (int i = 0; i<organizmy.size(); i++)
	{
		if (organizmy[i]->getZyje() == true)//martwe nie beda wykonywac akcji, czekaj na usuniecie
			organizmy[i]->akcja();
	}
	for (int i = organizmy.size() - 1; i >= 0; i--) 
	{
		if (organizmy[i]->getZyje()==false) //usun martwe
			organizmy.erase(organizmy.begin() + i); // od konca nie bedzie kolizji
	}
}
void Swiat::aktualizujPlansze()
{
	for (int i = 0; i < getRozmiar_y(); i++)
	{
		for (int j = 0; j < getRozmiar_x(); j++)
		{
			plansza[i][j] = '.';
		}
	}
	for (int i = 0; i < organizmy.size(); i++)
	{
		dodajOrganizmNaPlansze(organizmy[i]);
	}
}
int Swiat::getRozmiar_x()
{
	return rozmiar_x;
}
int Swiat::getRozmiar_y()
{
	return rozmiar_y;
}
string Swiat::getKierunekCzlowieka()
{
	return kierunek_czlowieka;
}
void Swiat::setKierunekCzlowieka(string ruch)
{
	kierunek_czlowieka = ruch;
}
void Swiat::ustawOznaczenie(int x, int y,char oznaczenie)
{
	plansza[y][x] = oznaczenie;
}
void Swiat::usunOznaczenie(int x, int y)
{
	plansza[y][x] = '.';
}
void Swiat::dodajLog(string log)
{
	logi.push_back(log);
}
void Swiat::wypiszLogiIUsun()
{
	for (int i = 0; i < logi.size(); i++)
	{
		cout << logi[i] << endl;
	}
	logi.clear();
}
void Swiat::rysujSwiat()
{
	cout << "Bartosz Lyskanowski s198051" << endl<<endl;
	for (int i = 0; i < getRozmiar_y(); i++)
	{
		for (int j = 0; j < getRozmiar_x(); j++)
		{
			cout << plansza[i][j];
		}
		cout << endl;
	}
}
void Swiat::wypiszOrganizmy()
{
	for (int i = 0; i < organizmy.size(); i++) 
	{
		organizmy[i]->wypiszOrganizm();
	}
}
void Swiat::zapiszDoPliku()
{
	cout << "Podaj nazwe pliku do zapisu: " << endl;
	string nazwa;
	cin >> nazwa;
	ofstream plik(nazwa);
	if (plik.good() != true)
	{
		cout << "Cos nie tak z plikiem" << endl;
		Sleep(2000);
		exit(0);
	}
	else
	{
		plik << rozmiar_x << " " << rozmiar_y << " " << cooldown_mocy << endl; //rozmiar planszy
		for (int i = 0; i < organizmy.size(); i++)
		{
			plik << organizmy[i]->getNazwa() << " " << organizmy[i]->getPolozenie_x() << " " << organizmy[i]->getPolozenie_y() << " " << 
				organizmy[i]->getWiek() << " " << organizmy[i]->getSila() << " " <<
				organizmy[i]->getInicjatywa() << " " << organizmy[i]->getOznacznie()<< " "; //bez zyje bo zyje zawsze true po turze
			if (dynamic_cast<Czlowiek*>(organizmy[i]))
				plik << dynamic_cast<Czlowiek*> (organizmy[i])->getIleJeszczeMocy() << endl;
			else
				plik << endl;
		}
		plik.close();
	}
}
void Swiat::wczytajZPliku()
{
	cout << "Podaj nazwe pliku z danymi: " << endl;
	string nazwa;
	cin >> nazwa;
	ifstream plik(nazwa);
	if (plik.good() != true)
	{
		cout << "Cos nie tak z plikiem" << endl;
		Sleep(2000);
		exit(0);
	}
	else
	{
		organizmy.clear();
		plansza.clear();
		plik >> rozmiar_x >> rozmiar_y >> cooldown_mocy;
		plansza.resize(rozmiar_y, vector<char>(rozmiar_x));
		int x, y, wiek, sila, inicjatywa, ile_jeszcze_mocy;
		char oznaczenie;
		string nazwa;
		while (plik >> nazwa)
		{
			plik >> x >> y >> wiek >> sila >> inicjatywa >> oznaczenie;
			if(nazwa=="Antylopa")
				organizmy.push_back(new Antylopa(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true)); //konstruktor do kazdej klasy
			else if (nazwa == "BarszczSosnowskiego")
				organizmy.push_back(new BarszczSosnowskiego(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Czlowiek")
			{
				plik >> ile_jeszcze_mocy;
				organizmy.push_back(new Czlowiek(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true,ile_jeszcze_mocy));
			}
			else if (nazwa == "Guarana")
				organizmy.push_back(new Guarana(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Lis")
				organizmy.push_back(new Lis(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Mlecz")
				organizmy.push_back(new Mlecz(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Owca")
				organizmy.push_back(new Owca(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Trawa")
				organizmy.push_back(new Trawa(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "WilczeJagody")
				organizmy.push_back(new WilczeJagody(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Wilk")
				organizmy.push_back(new Wilk(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			else if (nazwa == "Zolw")
				organizmy.push_back(new Zolw(x, y, wiek, sila, inicjatywa, oznaczenie, nazwa, *this, true));
			//cout<<nazwa <<x << y << wiek << sila << inicjatywa << oznaczenie<<endl;
		}
		plik.close();
	}
	aktualizujPlansze();
}