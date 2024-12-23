#pragma once
#include "Zwierze.h"
class  Antylopa :public Zwierze
{
public:
	Antylopa(int polozenie_x, int polozenie_y, Swiat& swiat);
	Antylopa(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void akcja() override;
    bool czyMozeUciec() override;
	void ucieczka(Organizm* atakujacy) override;
	void wstawMlode(int x, int y, Swiat& swiat) override;
};

