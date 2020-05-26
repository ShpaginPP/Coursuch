#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
using namespace std;

int main()
{
	RusFactory Data;
	Data.loadTank();
	Data.printTank();
	return 0;
}