#pragma once
#include "Robo.h"
class UsaRobo : public Robo
{
public:
	string name;         //название
	string range;		 //расстояние
	string power;		 //мощность
	string weapon;		 //Тип вооружения
	string caliber;		 //калибр вооружения
	string area;		 //метод пеоедвижения
	string year;		 //дата изготовления
	string amount;		 //количество в ангаре
	string weight;		 //вес

	string setName();
	string setRange();
	string setPower();
	string setWeapon();
	string setCaliber();
	string setArea();
	string setYear();
	string setAmount();
	string setWeight();
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
};