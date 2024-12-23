#pragma once
#include "Zwierze.h"
class Zolw : public Zwierze
{
public:
	Zolw(int polozenie_x, int polozenie_y, Swiat& swiat);
	Zolw(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void akcja() override;
	bool czyOdbilAtak(Organizm* atakujacy)override;
	void wstawMlode(int x, int y, Swiat& swiat) override;
};

