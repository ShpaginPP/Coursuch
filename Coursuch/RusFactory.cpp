#include "RusFactory.h"

void RusFactory::createTank()
{
	Tank** tmp = new Tank * [size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = Data[i];
	}
	tmp[size] = new RusTank; 
	tmp[size]->setName();
	tmp[size]->setRange();
	tmp[size]->setPower();
	tmp[size]->setWeapon();
	tmp[size]->setCaliber();
	tmp[size]->setArea();
	tmp[size]->setYear();
	tmp[size]->setAmount();
	tmp[size]->setWeight();
	tmp[size]->setCrew();
	size++;
	if (Data)
		delete[] Data;
	Data = tmp;
	cout << "Tank is succesefully created." << endl;
}
void RusFactory::printTank()
{
	try
	{
		if (!size)
		{
			throw(string)"The Russian Factory is empty, download tanks or build tanks;";
		}
			cout << "Russian tanks" << endl;
			for (int i = 0; i < size; i++)
			{
				Data[i]->print();
			}
			system("pause");
			return;
	}
	catch(string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void RusFactory::editTank()
{
	int index;
	int choice;
	if (!size)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i; i < size; i++)
		{
			cout << i << ")." << Data[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		Data[index]->print();
		cout << "Select an atribute to edit." << endl
			<< "1).Name;    " << endl
			<< "2).Range;	" << endl
			<< "3).Power;	" << endl
			<< "4).Weapon;	" << endl
			<< "5).Caliber;	" << endl
			<< "6).Area;	" << endl
			<< "7).Year;	" << endl
			<< "8).Amount;	" << endl
			<< "9).Weight;	" << endl
			<< "10).Crew;	" << endl;
		cin >> choice;
		if (choice < 1 || choice>10)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
			case 1:
				cout << "Current value:"<< Data[index]->getName() <<endl
					<< "New value:" << endl;
				Data[index]->setName();
				break;
			case 2:
				cout << "Current value:" << Data[index]->getRange() << endl
					<< "New value:" << endl;
				Data[index]->setRange();
				break;
			case 3:
				cout << "Current value:" << Data[index]->getPower() << endl
					<< "New value:" << endl;
				Data[index]->setPower();
				break;
			case 4:
				cout << "Current value:" << Data[index]->getWeapon() << endl
					<< "New value:" << endl;
				Data[index]->setWeapon();
				break;
			case 5:
				cout << "Current value:" << Data[index]->getCaliber() << endl
					<< "New value:" << endl;
				Data[index]->setCaliber();
				break;
			case 6:
				cout << "Current value:" << Data[index]->getArea() << endl
					<< "New value:" << endl;
				Data[index]->setArea();
				break;
			case 7:
				cout << "Current value:" << Data[index]->getYear() << endl
					<< "New value:" << endl;
				Data[index]->setYear();
				break;
			case 8:
				cout << "Current value:" << Data[index]->getAmount() << endl
					<< "New value:" << endl;
				Data[index]->setAmount();
				break;
			case 9:
				cout << "Current value:" << Data[index]->getWeight() << endl
					<< "New value:" << endl;
				Data[index]->setWeight();
				break;
			case 10:
				cout << "Current value:" << Data[index]->getCrew() << endl
					<< "New value:" << endl;
				Data[index]->setCrew();
				break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;

	}
}


void RusFactory::deleteTank()
{
	int index;
	int choice;
	Tank** tmp;
	int j = 0;

	if (!size)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i; i < size; i++)
		{
			cout << i << ")." << Data[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		Data[index]->print();
		cout << "Are you sure you want to delete this unit?" << endl
			<< "1). Yes" << endl
			<< "2). No" << endl;
		cin >> choice;
		if (choice < 1 || choice>2)
		{
			throw(string)"statement is incorrect.";
		}
		switch (choice)
		{
		case 1:
			cout << "Start deleting" << endl;
			if (size == 1)
			{
				delete[] Data;
				Data = nullptr;
				cout << "Unit deleted." << endl;
				size--;
				system("pause");
				return;
			}
			tmp = new Tank * [size - 1];
			j = 0;
			for (int i = 0; i < size; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = Data[i];
			}
			delete[] Data;
			Data = tmp;
			cout << "Unit deleted." << endl;
			size--;
			system("pause");
			return;
		case 2:
			cout << "Returning to menu." << endl;
			system("pause");
			return;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void RusFactory::loadTank()
{
	ifstream fin("rustank.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Tank **tmp = new Tank * [size + 1];
		for (int i = 0; i < size; i++)
		{
			tmp[i] = Data[i];
		}
		tmp[size] = new RusTank;
		tmp[size]->load(fin);
		size++;
		delete[] Data;
		Data = tmp;
	}
	fin.close();
	cout << "Units load on file rustank.txt" << endl;
	system("pause");
}

void RusFactory::saveTank()
{
	ofstream fout("rustank.txt");
	for (int i = 0; i < size; i++)
	{
		for (int i = 0; i < size; i++)
		{
			Data[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rustank.txt" << endl;
	system("pause");
}

void loadTank()
{}


