#pragma once
#include "Tank.h"
class Factory
{
	public:
		virtual void createTank() = 0;
		virtual void printTank(void) = 0;
		virtual void editTank() = 0;
		virtual void deleteTank() = 0;
		/*
		virtual void loadTank() = 0;
		*/
		virtual void saveTank() = 0;
		virtual ~Factory() {};
};

