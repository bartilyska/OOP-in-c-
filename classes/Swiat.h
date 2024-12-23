#pragma once
#include <vector>
#include <string>
class Organizm; //forward deklaracja bo inaczej swiat zalezy od organizmu i organizm od swiata
class Swiat
{
private:
	std::vector<std::vector<char>> plansza;
	std::vector<Organizm*> organizmy;
	std::vector<std::string> logi;
	int rozmiar_x;
	int rozmiar_y;
	std::string kierunek_czlowieka;
	int cooldown_mocy;
public:
	Swiat(int x, int y);
	int getRozmiar_x();
	int getRozmiar_y();

	int getCooldownMoc();
	void setCooldownMoc(int moc);

	std::string getKierunekCzlowieka();
	void setKierunekCzlowieka(std::string ruch);

	void ustawOznaczenie(int x,int y,char oznaczenie);
	void usunOznaczenie(int x,int y);
	Organizm* coStoi(int x, int y);

	void wykonajTure();
	bool porownajOrganizmy(Organizm* org1,Organizm* org2);
	void aktualizujPlansze();

	void usunOrganizm(Organizm* org);
	void dodajOrganizm(Organizm* org);
	void dodajOrganizmNaPlansze(Organizm* org);

	void dodajLog(std::string log);
	void wypiszLogiIUsun();
	void wypiszOrganizmy();
	void rysujSwiat();

	void zapiszDoPliku();
	void wczytajZPliku();
};

