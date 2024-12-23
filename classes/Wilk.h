#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
public:
	Wilk(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	Wilk(int polozenie_x, int polozenie_y, Swiat& swiat);
	void wstawMlode(int x, int y,Swiat& swiat) override;
};

