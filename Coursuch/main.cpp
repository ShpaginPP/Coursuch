#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
using namespace std;

int main()
{
	RusFactory Data;
	Data.createTank();
	Data.saveTank();
	Data.loadTank();
	Data.editTank();
	Data.saveTank();
	Data.loadTank();
	Data.deleteTank();
	Data.createTank();
	Data.printTank();
	return 0;
}