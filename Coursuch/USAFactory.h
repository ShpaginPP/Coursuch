#pragma once
#include "Factory.h"
#include "UsaTank.h"
class UsaFactory : public Factory
{
public:
	Tank** Data;
	int size_tu;
	void createTank();
	void editTank();
	void deleteTank();
	void loadTank();
	void saveTank();
	void printTank();
};

