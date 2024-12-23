#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
public:
	Trawa(int polozenie_x, int polozenie_y, Swiat& swiat);
	Trawa(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void wstawMlode(int x, int y, Swiat& swiat);
};

