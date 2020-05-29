#include "UsaFactory.h"

void UsaFactory::createTank()
{
	Tank** tmp = new Tank * [size_tu + 1];
	for (int i = 0; i < size_tu; i++)
	{
		tmp[i] = DataTank[i];
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
	if (DataTank)
		delete[] DataTank;
	DataTank = tmp;
	cout << "Tank is succesefully created." << endl;
}

void UsaFactory::printTank()
{
	try
	{
		if (!size_tu)
		{
			throw(string)"The Usasian Factory is empty, download tanks or build tanks;";
		}
		cout << "Usasian tanks" << endl;
		for (int i = 0; i < size_tu; i++)
		{
			DataTank[i]->print();
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
			cout << i << ")." << DataTank[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_tu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataTank[index]->print();
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
		if (choice < 1 || choice>9)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << DataTank[index]->getName() << endl;
			DataTank[index]->setName();
			break;
		case 2:
			cout << "Current value:" << DataTank[index]->getRange() << endl;
			DataTank[index]->setRange();
			break;
		case 3:
			cout << "Current value:" << DataTank[index]->getPower() << endl;
			DataTank[index]->setPower();
			break;
		case 4:
			cout << "Current value:" << DataTank[index]->getWeapon() << endl;
			DataTank[index]->setWeapon();
			cout << "Current value:" << DataTank[index]->getCaliber() << endl;
			DataTank[index]->setCaliber();
			break;
		case 5:
			cout << "Current value:" << DataTank[index]->getArea() << endl;
			DataTank[index]->setArea();
			break;
		case 6:
			cout << "Current value:" << DataTank[index]->getYear() << endl;
			DataTank[index]->setYear();
			break;
		case 7:
			cout << "Current value:" << DataTank[index]->getAmount() << endl;
			DataTank[index]->setAmount();
			break;
		case 8:
			cout << "Current value:" << DataTank[index]->getWeight() << endl;
			DataTank[index]->setWeight();
			break;
		case 9:
			cout << "Current value:" << DataTank[index]->getCrew() << endl;
			DataTank[index]->setCrew();
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
			cout << i << ")." << DataTank[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_tu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataTank[index]->print();
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
				delete[] DataTank;
				DataTank = nullptr;
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
				tmp[j++] = DataTank[i];
			}
			delete[] DataTank;
			DataTank = tmp;
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
			tmp[i] = DataTank[i];
		}
		tmp[size_tu] = new UsaTank;
		if (tmp[size_tu]->load(fin) != -1)
		{
			size_tu++;
			delete[] DataTank;
			DataTank = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file Usatank.txt" << endl;
	system("pause");
}

void UsaFactory::saveTank()
{
	ofstream fout("usatank.txt");
	for (int i = 0; i < size_tu; i++)
	{
		for (int i = 0; i < size_tu; i++)
		{
			DataTank[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file Usatank.txt" << endl;
	system("pause");
}

void UsaFactory::createBTR()
{
	{
		BTR** tmp = new BTR * [size_bu + 1];
		for (int i = 0; i < size_bu; i++)
		{
			tmp[i] = DataBTR[i];
		}
		tmp[size_bu] = new UsaBTR;
		tmp[size_bu]->setName();
		tmp[size_bu]->setArea();
		tmp[size_bu]->setYear();
		tmp[size_bu]->setAmount();
		tmp[size_bu]->setWeight();
		tmp[size_bu]->setCrew();
		size_bu++;
		if (DataBTR)
			delete[] DataBTR;
		DataBTR = tmp;
		cout << "BTR is succesefully created." << endl;
	}
}

void UsaFactory::printBTR()
{
	try
	{
		if (!size_bu)
		{
			throw(string)"The Usa Factory is empty, download tanks or build BTR;";
		}
		cout << "Usa BTR" << endl;
		for (int i = 0; i < size_bu; i++)
		{
			DataBTR[i]->print();
		}
		system("pause");
		return;
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void UsaFactory::editBTR()
{
	int index;
	int choice;
	if (!size_bu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a BTR." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_bu; i++)
		{
			cout << i << ")." << DataBTR[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_bu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataTank[index]->print();
		cout << "Select an atribute to edit." << endl
			<< "1).Name;    " << endl
			<< "2).Area;	" << endl
			<< "3).Year;	" << endl
			<< "4).Amount;	" << endl
			<< "5).Weight;	" << endl
			<< "6).Crew;	" << endl;
		cin >> choice;
		if (choice < 1 || choice>6)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << DataBTR[index]->getName() << endl;
			DataBTR[index]->setName();
			break;
		case 2:
			cout << "Current value:" << DataBTR[index]->getArea() << endl;
			DataBTR[index]->setArea();
			break;
		case 3:
			cout << "Current value:" << DataBTR[index]->getYear() << endl;
			DataBTR[index]->setYear();
			break;
		case 4:
			cout << "Current value:" << DataBTR[index]->getAmount() << endl;
			DataBTR[index]->setAmount();
			break;
		case 5:
			cout << "Current value:" << DataBTR[index]->getWeight() << endl;
			DataBTR[index]->setWeight();
			break;
		case 6:
			cout << "Current value:" << DataBTR[index]->getCrew() << endl;
			DataBTR[index]->setCrew();
			break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}

}

void UsaFactory::deleteBTR()
{
	int index;
	int choice;
	BTR** tmp;
	int j = 0;

	if (!size_bu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_bu; i++)
		{
			cout << i << ")." << DataBTR[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_bu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataBTR[index]->print();
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
			if (size_bu == 1)
			{
				delete[] DataBTR;
				DataBTR = nullptr;
				cout << "Unit deleted." << endl;
				size_bu--;
				system("pause");
				return;
			}
			tmp = new BTR * [size_bu - 1];
			j = 0;
			for (int i = 0; i < size_bu; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataBTR[i];
			}
			delete[] DataBTR;
			DataBTR = tmp;
			cout << "Unit deleted." << endl;
			size_bu--;
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

void UsaFactory::loadBTR()
{
	ifstream fin("usabtr.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		BTR** tmp = new BTR * [size_bu + 1];
		for (int i = 0; i < size_bu; i++)
		{
			tmp[i] = DataBTR[i];
		}
		tmp[size_bu] = new UsaBTR;
		if (tmp[size_bu]->load(fin) != -1)
		{
			size_bu++;
			delete[] DataBTR;
			DataBTR = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file usabtr.txt" << endl;
	system("pause");
}

void UsaFactory::saveBTR()
{
	ofstream fout("usabtr.txt");
	for (int i = 0; i < size_bu; i++)
	{
		for (int i = 0; i < size_bu; i++)
		{
			DataBTR[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file Usabtr.txt" << endl;
	system("pause");
}

void  UsaFactory::createRobo()
{
	{
		Robo** tmp = new Robo * [size_ru + 1];
		for (int i = 0; i < size_ru; i++)
		{
			tmp[i] = DataRobo[i];
		}
		tmp[size_ru] = new UsaRobo;
		tmp[size_ru]->setName();
		tmp[size_ru]->setRange();
		tmp[size_ru]->setPower();
		tmp[size_ru]->setWeapon();
		tmp[size_ru]->setCaliber();
		tmp[size_ru]->setArea();
		tmp[size_ru]->setYear();
		tmp[size_ru]->setAmount();
		tmp[size_ru]->setWeight();
		size_ru++;
		if (DataRobo)
			delete[] DataRobo;
		DataRobo = tmp;
		cout << "Robo is succesefully created." << endl;
	}
}

void  UsaFactory::printRobo()
{
	try
	{
		if (!size_ru)
		{
			throw(string)"The Usasian Factory is empty, download tanks or build tanks;";
		}
		cout << "Usasian robots" << endl;
		for (int i = 0; i < size_ru; i++)
		{
			DataRobo[i]->print();
		}
		system("pause");
		return;
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void UsaFactory::editRobo()
{
	int index;
	int choice;
	if (!size_ru)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a robot." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_ru; i++)
		{
			cout << i << ")." << DataRobo[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_ru - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataRobo[index]->print();
		cout << "Select an atribute to edit." << endl
			<< "1).Name;    " << endl
			<< "2).Range;	" << endl
			<< "3).Power;	" << endl
			<< "4).Weapon and caliber;	" << endl
			<< "5).Area;	" << endl
			<< "6).Year;	" << endl
			<< "7).Amount;	" << endl
			<< "8).Weight;	" << endl;
		cin >> choice;
		if (choice < 1 || choice>8)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << DataRobo[index]->getName() << endl;
			DataRobo[index]->setName();
			break;
		case 2:
			cout << "Current value:" << DataRobo[index]->getRange() << endl;
			DataRobo[index]->setRange();
			break;
		case 3:
			cout << "Current value:" << DataRobo[index]->getPower() << endl;
			DataRobo[index]->setPower();
			break;
		case 4:
			cout << "Current value:" << DataRobo[index]->getWeapon() << endl;
			DataRobo[index]->setWeapon();
			cout << "Current value:" << DataRobo[index]->getCaliber() << endl;
			DataRobo[index]->setCaliber();
			break;
		case 5:
			cout << "Current value:" << DataRobo[index]->getArea() << endl;
			DataRobo[index]->setArea();
			break;
		case 6:
			cout << "Current value:" << DataRobo[index]->getYear() << endl;
			DataRobo[index]->setYear();
			break;
		case 7:
			cout << "Current value:" << DataRobo[index]->getAmount() << endl;
			DataRobo[index]->setAmount();
			break;
		case 8:
			cout << "Current value:" << DataRobo[index]->getWeight() << endl;
			DataRobo[index]->setWeight();
			break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;

	}
}

void  UsaFactory::deleteRobo()
{
	int index;
	int choice;
	Robo** tmp;
	int j = 0;

	if (!size_ru)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Robo." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_ru; i++)
		{
			cout << i << ")." << DataRobo[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_ru - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataRobo[index]->print();
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
			if (size_ru == 1)
			{
				delete[] DataRobo;
				DataRobo = nullptr;
				cout << "Unit deleted." << endl;
				size_ru--;
				system("pause");
				return;
			}
			tmp = new Robo * [size_ru - 1];
			j = 0;
			for (int i = 0; i < size_ru; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataRobo[i];
			}
			delete[] DataRobo;
			DataRobo = tmp;
			cout << "Unit deleted." << endl;
			size_ru--;
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

void UsaFactory::loadRobo()
{
	ifstream fin("usarobo.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Robo** tmp = new Robo * [size_ru + 1];
		for (int i = 0; i < size_ru; i++)
		{
			tmp[i] = DataRobo[i];
		}
		tmp[size_ru] = new UsaRobo;
		if (tmp[size_ru]->load(fin) != -1)
		{
			size_ru++;
			delete[] DataRobo;
			DataRobo = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file Usarobo.txt" << endl;
	system("pause");
}

void UsaFactory::saveRobo()
{
	ofstream fout("usarobo.txt");
	for (int i = 0; i < size_ru; i++)
	{
		for (int i = 0; i < size_ru; i++)
		{
			DataRobo[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file Usarobo.txt" << endl;
	system("pause");
}

void UsaFactory::createHowitzer()
{
	Howitzer** tmp = new Howitzer * [size_hu + 1];
	for (int i = 0; i < size_hu; i++)
	{
		tmp[i] = DataHowitzer[i];
	}
	tmp[size_hu] = new UsaHowitzer;
	tmp[size_hu]->setName();
	tmp[size_hu]->setRange();
	tmp[size_hu]->setPower();
	tmp[size_hu]->setWeapon();
	tmp[size_hu]->setCaliber();
	tmp[size_hu]->setArea();
	tmp[size_hu]->setYear();
	tmp[size_hu]->setAmount();
	tmp[size_hu]->setWeight();
	tmp[size_hu]->setCrew();
	size_hu++;
	if (DataHowitzer)
		delete[] DataHowitzer;
	DataHowitzer = tmp;
	cout << "Howitzer is succesefully created." << endl;
}

void UsaFactory::printHowitzer()
{
	try
	{
		if (!size_hu)
		{
			throw(string)"The Usasian Factory is empty, download Howitzers or build Howitzers;";
		}
		cout << "Usasian Howitzers" << endl;
		for (int i = 0; i < size_hu; i++)
		{
			DataHowitzer[i]->print();
		}
		system("pause");
		return;
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void UsaFactory::editHowitzer()
{
	int index;
	int choice;
	if (!size_hu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Howitzer." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_hu; i++)
		{
			cout << i << ")." << DataHowitzer[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_hu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataHowitzer[index]->print();
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
		if (choice < 1 || choice>9)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << DataHowitzer[index]->getName() << endl;
			DataHowitzer[index]->setName();
			break;
		case 2:
			cout << "Current value:" << DataHowitzer[index]->getRange() << endl;
			DataHowitzer[index]->setRange();
			break;
		case 3:
			cout << "Current value:" << DataHowitzer[index]->getPower() << endl;
			DataHowitzer[index]->setPower();
			break;
		case 4:
			cout << "Current value:" << DataHowitzer[index]->getWeapon() << endl;
			DataHowitzer[index]->setWeapon();
			cout << "Current value:" << DataHowitzer[index]->getCaliber() << endl;
			DataHowitzer[index]->setCaliber();
			break;
		case 5:
			cout << "Current value:" << DataHowitzer[index]->getArea() << endl;
			DataHowitzer[index]->setArea();
			break;
		case 6:
			cout << "Current value:" << DataHowitzer[index]->getYear() << endl;
			DataHowitzer[index]->setYear();
			break;
		case 7:
			cout << "Current value:" << DataHowitzer[index]->getAmount() << endl;
			DataHowitzer[index]->setAmount();
			break;
		case 8:
			cout << "Current value:" << DataHowitzer[index]->getWeight() << endl;
			DataHowitzer[index]->setWeight();
			break;
		case 9:
			cout << "Current value:" << DataHowitzer[index]->getCrew() << endl;
			DataHowitzer[index]->setCrew();
			break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;

	}
}

void UsaFactory::deleteHowitzer()
{
	int index;
	int choice;
	Howitzer** tmp;
	int j = 0;

	if (!size_hu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Howitzer." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_hu; i++)
		{
			cout << i << ")." << DataHowitzer[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_hu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataHowitzer[index]->print();
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
			if (size_hu == 1)
			{
				delete[] DataHowitzer;
				DataHowitzer = nullptr;
				cout << "Unit deleted." << endl;
				size_hu--;
				system("pause");
				return;
			}
			tmp = new Howitzer * [size_hu - 1];
			j = 0;
			for (int i = 0; i < size_hu; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataHowitzer[i];
			}
			delete[] DataHowitzer;
			DataHowitzer = tmp;
			cout << "Unit deleted." << endl;
			size_hu--;
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

void UsaFactory::loadHowitzer()
{
	ifstream fin("usahowitzer.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Howitzer** tmp = new Howitzer * [size_hu + 1];
		for (int i = 0; i < size_hu; i++)
		{
			tmp[i] = DataHowitzer[i];
		}
		tmp[size_hu] = new UsaHowitzer;
		if (tmp[size_hu]->load(fin) != -1)
		{
			size_hu++;
			delete[] DataHowitzer;
			DataHowitzer = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file Usahowitzer.txt" << endl;
	system("pause");
}

void UsaFactory::saveHowitzer()
{
	ofstream fout("usahowitzer.txt");
	for (int i = 0; i < size_hu; i++)
	{
		for (int i = 0; i < size_hu; i++)
		{
			DataHowitzer[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file Usahowitzer.txt" << endl;
	system("pause");
}

void UsaFactory::createPlane()
{
	Plane** tmp = new Plane * [size_pu + 1];
	for (int i = 0; i < size_pu; i++)
	{
		tmp[i] = DataPlane[i];
	}
	tmp[size_pu] = new UsaPlane;
	tmp[size_pu]->setName();
	tmp[size_pu]->setRange();
	tmp[size_pu]->setPower();
	tmp[size_pu]->setWeapon();
	tmp[size_pu]->setCaliber();
	tmp[size_pu]->setArea();
	tmp[size_pu]->setYear();
	tmp[size_pu]->setAmount();
	tmp[size_pu]->setWeight();
	tmp[size_pu]->setCrew();
	size_pu++;
	if (DataPlane)
		delete[] DataPlane;
	DataPlane = tmp;
	cout << "Plane is succesefully created." << endl;
}

void UsaFactory::printPlane()
{
	try
	{
		if (!size_pu)
		{
			throw(string)"The Usasian Factory is empty, download Planes or build Planes;";
		}
		cout << "Usasian Planes" << endl;
		for (int i = 0; i < size_pu; i++)
		{
			DataPlane[i]->print();
		}
		system("pause");
		return;
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
	}
}

void UsaFactory::editPlane()
{
	int index;
	int choice;
	if (!size_pu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Plane." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_pu; i++)
		{
			cout << i << ")." << DataPlane[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_pu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataPlane[index]->print();
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
		if (choice < 1 || choice>9)
		{
			throw(string)"Atribute doesn't exit, restarting edit.";
		}
		switch (choice)
		{
		case 1:
			cout << "Current value:" << DataPlane[index]->getName() << endl;
			DataPlane[index]->setName();
			break;
		case 2:
			cout << "Current value:" << DataPlane[index]->getRange() << endl;
			DataPlane[index]->setRange();
			break;
		case 3:
			cout << "Current value:" << DataPlane[index]->getPower() << endl;
			DataPlane[index]->setPower();
			break;
		case 4:
			cout << "Current value:" << DataPlane[index]->getWeapon() << endl;
			DataPlane[index]->setWeapon();
			cout << "Current value:" << DataPlane[index]->getCaliber() << endl;
			DataPlane[index]->setCaliber();
			break;
		case 5:
			cout << "Current value:" << DataPlane[index]->getArea() << endl;
			DataPlane[index]->setArea();
			break;
		case 6:
			cout << "Current value:" << DataPlane[index]->getYear() << endl;
			DataPlane[index]->setYear();
			break;
		case 7:
			cout << "Current value:" << DataPlane[index]->getAmount() << endl;
			DataPlane[index]->setAmount();
			break;
		case 8:
			cout << "Current value:" << DataPlane[index]->getWeight() << endl;
			DataPlane[index]->setWeight();
			break;
		case 9:
			cout << "Current value:" << DataPlane[index]->getCrew() << endl;
			DataPlane[index]->setCrew();
			break;
		}
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;

	}
}

void UsaFactory::deletePlane()
{
	int index;
	int choice;
	Plane** tmp;
	int j = 0;

	if (!size_pu)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Plane." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_pu; i++)
		{
			cout << i << ")." << DataPlane[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_pu - 1)
		{
			throw(string)"the selected unit doesn't exist.";
		}
		DataPlane[index]->print();
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
			if (size_pu == 1)
			{
				delete[] DataPlane;
				DataPlane = nullptr;
				cout << "Unit deleted." << endl;
				size_pu--;
				system("pause");
				return;
			}
			tmp = new Plane * [size_pu - 1];
			j = 0;
			for (int i = 0; i < size_pu; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataPlane[i];
			}
			delete[] DataPlane;
			DataPlane = tmp;
			cout << "Unit deleted." << endl;
			size_pu--;
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

void UsaFactory::loadPlane()
{
	ifstream fin("usaplane.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Plane** tmp = new Plane * [size_pu + 1];
		for (int i = 0; i < size_pu; i++)
		{
			tmp[i] = DataPlane[i];
		}
		tmp[size_pu] = new UsaPlane;
		if (tmp[size_pu]->load(fin) != -1)
		{
			size_pu++;
			delete[] DataPlane;
			DataPlane = tmp;
		}
		else
		{
			cout << "There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file Usaplane.txt" << endl;
	system("pause");
}

void UsaFactory::savePlane()
{
	ofstream fout("usaplane.txt");
	for (int i = 0; i < size_pu; i++)
	{
		for (int i = 0; i < size_pu; i++)
		{
			DataPlane[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file Usaplane.txt" << endl;
	system("pause");
}