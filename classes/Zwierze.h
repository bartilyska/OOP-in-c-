#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
public:
	Zwierze(int polozenie_x, int polozenie_y, Swiat& swiat);
	Zwierze(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void utworzLogOdbicie(Organizm* broniacy);
	void utworzLogWalkaWygrana(Organizm* broniacy);
	void utworzLogWalkaPrzegrana(Organizm* broniacy);
	void utworzLogUcieczka(Organizm* atakujacy);
	void utworzLogRozmnozenie();
	virtual void akcja() override;
	virtual void kolizja(Organizm*broniacy) override;
	virtual void rozmnazanie() override;
	virtual bool czyOdbilAtak(Organizm* atakujacy) override;
	virtual bool czyMozeUciec() override;
	virtual void ucieczka(Organizm* atakujacy) override;
	virtual void wstawMlode(int x,int y,Swiat& swiat) = 0;
};
