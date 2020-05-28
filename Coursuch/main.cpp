#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
#include "UsaFactory.h"
using namespace std;

int main()
{
	RusFactory Data1;
	Data1.loadTank();
	return 0;
}