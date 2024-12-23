#pragma once
#include <string>
#include "Swiat.h"
class Organizm
{
protected:
	int polozenie_x,polozenie_y;
	int wiek;
	int sila;
	int inicjatywa;
	char oznaczenie;
	std::string nazwa;
	Swiat& swiat;
	bool zyje;
public:
	Organizm(int polozenie_x, int polozenie_y,Swiat & swiat);
	Organizm(int polozenie_x, int polozenie_y,int wiek,int sila,int inicjatywa,char oznaczenie,std::string nazwa, Swiat& swiat,bool zyje); //z pliku
	int getPolozenie_x();
	void setPolozenie_x(int pozx);
	void setPolozenie_y(int pozy);
	int getPolozenie_y();
	int getWiek();
	std::string getNazwa();
	int getInicjatywa();
	int getSila();
	void setSila(int nowasila);
	bool getZyje();
	void setZyje(bool zycie);
	char getOznacznie();

	void wypiszOrganizm();

	virtual void akcja() = 0;
	virtual void kolizja(Organizm*broniacy) = 0;
	virtual bool czyOdbilAtak(Organizm* atakujacy);
	virtual bool czyMozeUciec();
	virtual void efektPoZjedzeniu(Organizm*atakujacy);
	virtual void rozmnazanie();
	virtual void ucieczka(Organizm* atakujacy);
	virtual void wstawMlode(int x, int y, Swiat& swiat) = 0;
};

