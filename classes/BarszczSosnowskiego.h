#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
public:
	BarszczSosnowskiego(int polozenie_x, int polozenie_y, Swiat& swiat);
	BarszczSosnowskiego(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void wstawMlode(int x, int y, Swiat& swiat);
	void akcja() override;
	void efektPoZjedzeniu(Organizm* atakujacy) override;
};

