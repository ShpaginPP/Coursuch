#pragma once
#include "Howitzer.h"
class UsaHowitzer : public Howitzer
{
public:
	string name;         //название
	string range;		 //рассто€ние
	string power;		 //мощность
	string weapon;		 //“ип вооружени€
	string caliber;		 //калибр вооружени€
	string area;		 //метод пеоедвижени€
	string year;		 //дата изготовлени€
	string amount;		 //количество в ангаре
	string weight;		 //вес
	string crew;		 //число экипажа

	string setName();
	string setRange();
	string setPower();
	string setWeapon();
	string setCaliber();
	string setArea();
	string setYear();
	string setAmount();
	string setWeight();
	string setCrew();
	void print();
	void save(ofstream& fout);
	int load(ifstream& fin);
	string getName();
	string getRange();
	string getPower();
	string getWeapon();
	string getCaliber();
	string getArea();
	string getYear();
	string getAmount();
	string getWeight();
	string getCrew();
};