#pragma once
#include "Factory.h"
#include "RusTank.h"
#include "RusBTR.h"
#include "RusRobo.h"
#include "RusHowitzer.h"
#include "RusPlane.h"
class RusFactory: public Factory
{
public:
	Tank** DataTank;
	BTR** DataBTR;
	Robo** DataRobo;
	Howitzer** DataHowitzer;
	Plane** DataPlane;

	int size_tr;
	int size_br;
	int size_rr;
	int size_hr;
	int size_pr;
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

