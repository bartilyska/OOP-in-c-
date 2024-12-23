#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
protected:
	int szansa_zasiania;//w procentach
public:
	Roslina(int polozenie_x, int polozenie_y, Swiat& swiat);
	Roslina(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje);
	void utworzLogRozsianie(int nowapoz_x, int nowapoz_y);
	void utworzLogAtak(Organizm* przeciwnik);
	virtual void akcja() override;
	virtual void kolizja(Organizm* broniacy) override;
	virtual void wstawMlode(int x, int y, Swiat& swiat) =0;
};

