#pragma once
#include "Zwierze.h"
class Czlowiek : public Zwierze
{
private:
	int ile_jeszcze_mocy;
public:
	Czlowiek(int polozenie_x, int polozenie_y, Swiat& swiat);
	Czlowiek(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, std::string nazwa, Swiat& swiat, bool zyje,int ile_jeszcze);
	int getIleJeszczeMocy();
	void specjalnaUmiejetnosc();
	void akcja() override;
	void wstawMlode(int x, int y, Swiat& swiat) override;
};

