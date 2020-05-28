#pragma once
#include "Tank.h"
class Factory
{
	public:
		virtual void createTank() = 0;
		virtual void printTank() = 0;
		virtual void editTank() = 0;
		virtual void deleteTank() = 0;
		virtual void loadTank() = 0;
		virtual void saveTank() = 0;
		virtual void createBTR() = 0;
		virtual void printBTR() = 0;
		virtual void editBTR() = 0;
		virtual void deleteBTR() = 0;
		virtual void loadBTR() = 0;
		virtual void saveBTR() = 0;
		virtual ~Factory() {};
};

