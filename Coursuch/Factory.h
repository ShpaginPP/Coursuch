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
		virtual void createRobo() = 0;
		virtual void printRobo() = 0;
		virtual void editRobo() = 0;
		virtual void deleteRobo() = 0;
		virtual void loadRobo() = 0;
		virtual void saveRobo() = 0;
		virtual void createHowitzer() = 0;
		virtual void printHowitzer() = 0;
		virtual void editHowitzer() = 0;
		virtual void deleteHowitzer() = 0;
		virtual void loadHowitzer() = 0;
		virtual void saveHowitzer() = 0;
		virtual ~Factory() {};
};

