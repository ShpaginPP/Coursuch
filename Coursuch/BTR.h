
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class BTR
{
public:
	virtual string setName() = 0;//Сеттеры
	virtual string setArea() = 0;
	virtual string setYear() = 0;
	virtual string setAmount() = 0;
	virtual string setWeight() = 0;
	virtual string setCrew() = 0;
	virtual void print() = 0;
	virtual void save(ofstream& fout) = 0;
	virtual int load(ifstream& fin) = 0;
	virtual string getName() = 0;//Геттеры

	virtual string getArea() = 0;
	virtual string getYear() = 0;
	virtual string getAmount() = 0;
	virtual string getWeight() = 0;
	virtual string getCrew() = 0;
	virtual ~BTR() {};
};

