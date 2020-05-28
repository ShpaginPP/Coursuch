#pragma once
#include "Factory.h"
#include "UsaTank.h"
#include "UsaBTR.h"
#include "UsaRobo.h"
#include "UsaHowitzer.h"
#include "UsaPlane.h"
class UsaFactory : public Factory
{
public:
	Tank** DataTank;
	BTR** DataBTR;
	Robo** DataRobo;
	Howitzer** DataHowitzer;
	Plane** DataPlane;
			  
	int size_tu;
	int size_bu;
	int size_ru;
	int size_hu;
	int size_pu;
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
	void createRobo();
	void printRobo();
	void editRobo();
	void deleteRobo();
	void loadRobo();
	void saveRobo();
	void createHowitzer();
	void printHowitzer();
	void editHowitzer();
	void deleteHowitzer();
	void loadHowitzer();
	void saveHowitzer();
	void createPlane();
	void printPlane();
	void editPlane();
	void deletePlane();
	void loadPlane();
	void savePlane();
};

