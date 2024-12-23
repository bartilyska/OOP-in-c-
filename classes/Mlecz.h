#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
public:
	Mlecz(int polozenie_x, int polozenie_y, Swiat& swiat);
	Mlecz(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void akcja() override;
	void wstawMlode(int x, int y, Swiat& swiat);
};

