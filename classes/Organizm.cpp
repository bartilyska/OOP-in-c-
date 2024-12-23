#include "Organizm.h"
#include "Swiat.h"
#include <iostream>
using namespace std;
Organizm::Organizm(int polozenie_x, int polozenie_y,Swiat &swiat):
	polozenie_x(polozenie_x),polozenie_y(polozenie_y),swiat(swiat),zyje(true)
{
}
Organizm::Organizm(int polozenie_x, int polozenie_y, int wiek, int sila, int inicjatywa, char oznaczenie, string nazwa, Swiat& swiat, bool zyje) :
	polozenie_x(polozenie_x), polozenie_y(polozenie_y),wiek(wiek),sila(sila),inicjatywa(inicjatywa),oznaczenie(oznaczenie), nazwa(nazwa),
	swiat(swiat), zyje(zyje)
{
}
int Organizm::getPolozenie_x()
{
	return polozenie_x;
}
int Organizm::getPolozenie_y()
{
	return polozenie_y;
}
void Organizm::setPolozenie_x(int pozx)
{
	polozenie_x = pozx;
}
void Organizm::setPolozenie_y(int pozy)
{
	polozenie_y = pozy;
}
int Organizm::getWiek()
{
	return wiek;
}
std::string Organizm::getNazwa()
{
	return nazwa;
}
int Organizm::getInicjatywa()
{
	return inicjatywa;
}
int Organizm::getSila()
{
	return sila;
}
void Organizm::setSila(int nowasila)
{
	sila = nowasila;
}
bool Organizm::getZyje()
{
	return zyje;
}
void Organizm::setZyje(bool zycie)
{
	zyje = zycie;
}
char Organizm::getOznacznie()
{
	return oznaczenie;
}
void Organizm::wypiszOrganizm()
{
	cout << nazwa << " " << polozenie_x+1 << " " << polozenie_y+1<< " " << wiek << " " << sila << " " << inicjatywa << " " << oznaczenie<<" "<<zyje << endl;
}
bool Organizm::czyOdbilAtak(Organizm* atakujacy)
{
	return false;
}
bool Organizm::czyMozeUciec() 
{
	return false;
}
void Organizm::rozmnazanie(){}
void Organizm::ucieczka(Organizm* atakujacy){}
void Organizm::efektPoZjedzeniu(Organizm* atakujacy){}