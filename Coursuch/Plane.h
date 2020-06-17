#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Plane
{
public:
	virtual string setName() = 0;
	virtual string setRange() = 0;
	virtual string setPower() = 0;
	virtual string setWeapon() = 0;
	virtual string setCaliber() = 0;
	virtual string setArea() = 0;
	virtual string setYear() = 0;
	virtual string setAmount() = 0;
	virtual string setWeight() = 0;
	virtual string setCrew() = 0;
	virtual void print() = 0;
	virtual void save(ofstream& fout) = 0;
	virtual int load(ifstream& fin) = 0;
	virtual string getName() = 0;
	virtual string getRange() = 0;
	virtual string getPower() = 0;
	virtual string getWeapon() = 0;
	virtual string getCaliber() = 0;
	virtual string getArea() = 0;
	virtual string getYear() = 0;
	virtual string getAmount() = 0;
	virtual string getWeight() = 0;
	virtual string getCrew() = 0;
	virtual ~Plane() {};
};

