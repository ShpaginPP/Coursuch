#pragma once
#include "Factory.h"
#include "RusTank.h"
class RusFactory: public Factory
{
public:
	Tank** Data;
	int size;
	void createTank();
	void editTank();
	void deleteTank();
	void loadTank();
	void saveTank();
	void printTank();
};

