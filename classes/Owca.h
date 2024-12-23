#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
public:
	Owca(int polozenie_x, int polozenie_y, Swiat& swiat);
	Owca(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void wstawMlode(int x, int y, Swiat& swiat) override;
};

