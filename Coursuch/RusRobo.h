#pragma once
#include "Robo.h"
class RusRobo : public Robo
{
public:
	string name;        
	string range;		
	string power;		
	string weapon;		
	string caliber;		
	string area;		
	string year;		
	string amount;		
	string weight;		

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