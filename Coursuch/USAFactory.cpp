#include "UsaFactory.h"

void UsaFactory::createTank()
{
	Tank** tmp = new Tank * [size_tu + 1];
	for (int i = 0; i < size_tu; i++)
	{
		tmp[i] = Data[i];
	}
	tmp[size_tu] = new UsaTank;
	tmp[size_tu]->setName();
	tmp[size_tu]->setRange();
	tmp[size_tu]->setPower();
	tmp[size_tu]->setWeapon();
	tmp[size_tu]->setCaliber();
	tmp[size_tu]->setArea();
	tmp[size_tu]->setYear();
	tmp[size_tu]->setAmount();
	tmp[size_tu]->setWeight();
	tmp[size_tu]->setCrew();
	size_tu++;
	if (Data)
		delete[] Data;
	Data = tmp;
	cout << "Tank is succesefully created." << endl;
}

void UsaFactory::printTank()
{
	try
	{
		if (!size_tu)
		{
			throw(string)"The USA Factory is empty, download tanks or build tanks;";
		}
		cout << "USA tanks" << endl;
		for (int i = 0; i < size_tu; i++)
		{
			Data[i]->print();
		}
		system("pause");
		return;
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void UsaFactory::editTank()
{
	int index;
	int choice;
	if (!size_tu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_tu; i++)
		{
			cout << i << ")." << Data[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_tu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		Data[index]->print();
		cout << "Select an atribute to edit." << endl
			<< "1).Name;    " << endl
			<< "2).Range;	" << endl
			<< "3).Power;	" << endl
			<< "4).Weapon and caliber;	" << endl
			<< "5).Area;	" << endl
			<< "6).Year;	" << endl
			<< "7).Amount;	" << endl
			<< "8).Weight;	" << endl
			<< "9).Crew;	" << endl;
		cin >> choice;
		if (choice < 1 || choice>10)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << Data[index]->getName() << endl;
			Data[index]->setName();
			break;
		case 2:
			cout << "Current value:" << Data[index]->getRange() << endl;
			Data[index]->setRange();
			break;
		case 3:
			cout << "Current value:" << Data[index]->getPower() << endl;
			Data[index]->setPower();
			break;
		case 4:
			cout << "Current value:" << Data[index]->getWeapon() << endl;
			Data[index]->setWeapon();
			cout << "Current value:" << Data[index]->getCaliber() << endl;
			Data[index]->setCaliber();
			break;
		case 5:
			cout << "Current value:" << Data[index]->getArea() << endl;
			Data[index]->setArea();
			break;
		case 6:
			cout << "Current value:" << Data[index]->getYear() << endl;
			Data[index]->setYear();
			break;
		case 7:
			cout << "Current value:" << Data[index]->getAmount() << endl;
			Data[index]->setAmount();
			break;
		case 8:
			cout << "Current value:" << Data[index]->getWeight() << endl;
			Data[index]->setWeight();
			break;
		case 9:
			cout << "Current value:" << Data[index]->getCrew() << endl;
			Data[index]->setCrew();
			break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;

	}
}


void UsaFactory::deleteTank()
{
	int index;
	int choice;
	Tank** tmp;
	int j = 0;

	if (!size_tu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_tu; i++)
		{
			cout << i << ")." << Data[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_tu - 1)
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
			if (size_tu == 1)
			{
				delete[] Data;
				Data = nullptr;
				cout << "Unit deleted." << endl;
				size_tu--;
				system("pause");
				return;
			}
			tmp = new Tank * [size_tu - 1];
			j = 0;
			for (int i = 0; i < size_tu; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = Data[i];
			}
			delete[] Data;
			Data = tmp;
			cout << "Unit deleted." << endl;
			size_tu--;
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

void UsaFactory::loadTank()
{
	ifstream fin("usatank.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Tank** tmp = new Tank * [size_tu + 1];
		for (int i = 0; i < size_tu; i++)
		{
			tmp[i] = Data[i];
		}
		tmp[size_tu] = new UsaTank;
		if (tmp[size_tu]->load(fin) != -1)
		{
			size_tu++;
			delete[] Data;
			Data = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file usatank.txt" << endl;
	system("pause");
}

void UsaFactory::saveTank()
{
	ofstream fout("usatank.txt");
	for (int i = 0; i < size_tu; i++)
	{
		for (int i = 0; i < size_tu; i++)
		{
			Data[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file usatank.txt" << endl;
	system("pause");
}