#pragma once
#include "Factory.h"
#include "RusTank.h"
#include "RusBTR.h"
class RusFactory: public Factory
{
public:
	Tank** DataTank;
	BTR** DataBTR;
	int size_tr;
	int size_br;
	void createTank();
	void editTank();
	void deleteTank();
	void loadTank();
	void saveTank();
	void printTank();
	void createBTR();
	void printBTR();
	void editBTR();
	void deleteBTR();
	void loadBTR();
	void saveBTR();
};

