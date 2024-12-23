#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
public:
	WilczeJagody(int polozenie_x, int polozenie_y, Swiat& swiat);
	WilczeJagody(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void wstawMlode(int x, int y, Swiat& swiat);
	void efektPoZjedzeniu(Organizm* atakujacy) override;
};

