#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <string>
#include "Swiat.h"
using namespace std;
int main()
{
	srand(time(NULL));
	int rozmiarx=0, rozmiary=0;
	while (rozmiarx <= 7 || rozmiary <= 7)
	{
		cout << "Sterujesz Czlowiekiem - C" << endl;
		cout << "Sterowanie: wasd, pozostan w miejscu - e, moc - m" << endl;
		cout << "Zapis planszy - p, wczytanie planszy - l, wyjscie - q" << endl;
		cout << "Podaj wymiary planszy wieksze niz 7: ";
		cin >> rozmiarx >> rozmiary;
		system("cls");
	}
	Swiat swiat(rozmiarx, rozmiary);
	string wejscie,przekaz_kierunek;
	swiat.wykonajTure();//ustawienie organizmow na start z wiekiem 1
	swiat.aktualizujPlansze();
	while (1)
	{
		swiat.rysujSwiat();
		swiat.wypiszLogiIUsun();
		swiat.wypiszOrganizmy();
		cin >> wejscie;
		if (wejscie == "w" || wejscie == "W")
			przekaz_kierunek = "gora";
		else if (wejscie == "a" || wejscie == "A")
			przekaz_kierunek = "lewo";
		else if (wejscie == "s" || wejscie == "S")
			przekaz_kierunek = "dol";
		else if (wejscie == "d" || wejscie == "D")
			przekaz_kierunek = "prawo";
		else if (wejscie == "e" || wejscie == "E")
			przekaz_kierunek = "";
		else if (wejscie == "q" || wejscie == "Q")
			exit(0);
		else if ((wejscie == "m" || wejscie == "M") && swiat.getCooldownMoc()==0) //moc nieaktywna i nie ma cooldownu i chcemy odpalic
		{
			swiat.setCooldownMoc(10);
			//cout << "Aktywowano moc" << endl;
			//Sleep(1000);
			system("cls");
			continue;
		}
		else if (wejscie == "p" || wejscie == "P")
		{
			swiat.zapiszDoPliku();
			system("cls");
			continue;
		}
		else if (wejscie == "l" || wejscie == "L")
		{
			swiat.wczytajZPliku();
			system("cls");
			continue;
		}
		else
		{
			cout << "Moc niemozliwa do uzycia lub wybrano nielegalny klawisz" << endl;
			Sleep(1000);
			system("cls");
			continue;
		}
		swiat.setKierunekCzlowieka(przekaz_kierunek);
		swiat.wykonajTure();
		system("cls");
	}
	
	/*vector<vector<int>> plansza(y, vector <int>(x));*/
	
}
