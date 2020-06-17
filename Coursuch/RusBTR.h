#pragma once
#include "BTR.h"
class RusBTR : public BTR
{
public:
	string name;        
	string area;		
	string year;		
	string amount;		
	string weight;		
	string crew;		

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

