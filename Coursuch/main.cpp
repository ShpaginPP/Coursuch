#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
using namespace std;

int main()
{
	RusFactory Data;
	Data.loadTank();
	return 0;
}