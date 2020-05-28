#pragma once
#include "BTR.h"
class RusBTR : public BTR
{
public:
	string name;         //название
	string area;		 //метод пеоедвижения
	string year;		 //дата изготовления
	string amount;		 //количество в ангаре
	string weight;		 //вес
	string crew;		 //число экипажа

	string setName();
	string setArea();
	string setYear();
	string setAmount();
	string setWeight();
	string setCrew();
	void print();
	void save(ofstream& fout);
	int load(ifstream& fin);
	string getName();
	string getArea();
	string getYear();
	string getAmount();
	string getWeight();
	string getCrew();
};

