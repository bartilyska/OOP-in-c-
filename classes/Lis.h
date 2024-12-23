#pragma once
#include "Zwierze.h"
class Lis :public Zwierze
{
public:
	Lis(int polozenie_x, int polozenie_y, Swiat& swiat);
	Lis(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void akcja() override;
	void wstawMlode(int x, int y, Swiat& swiat) override;
};

