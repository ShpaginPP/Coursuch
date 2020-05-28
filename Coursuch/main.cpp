#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
#include "UsaFactory.h"
using namespace std;

int main()
{
	RusFactory Data1;
	UsaFactory Data2;
	Data1.loadTank();
	return 0;
}