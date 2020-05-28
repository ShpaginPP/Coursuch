#include "RusFactory.h"

void RusFactory::createTank()
{
	Tank** tmp = new Tank * [size_tr + 1];
	for (int i = 0; i < size_tr; i++)
	{
		tmp[i] = DataTank[i];
	}
	tmp[size_tr] = new RusTank; 
	tmp[size_tr]->setName();
	tmp[size_tr]->setRange();
	tmp[size_tr]->setPower();
	tmp[size_tr]->setWeapon();
	tmp[size_tr]->setCaliber();
	tmp[size_tr]->setArea();
	tmp[size_tr]->setYear();
	tmp[size_tr]->setAmount();
	tmp[size_tr]->setWeight();
	tmp[size_tr]->setCrew();
	size_tr++;
	if (DataTank)
		delete[] DataTank;
	DataTank = tmp;
	cout << "Tank is succesefully created." << endl;
}

void RusFactory::printTank()
{
	try
	{
		if (!size_tr)
		{
			throw(string)"The Russian Factory is empty, download tanks or build tanks;";
		}
			cout << "Russian tanks" << endl;
			for (int i = 0; i < size_tr; i++)
			{
				DataTank[i]->print();
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
	if (!size_tr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i=0; i < size_tr; i++)
		{
			cout << i << ")." << DataTank[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_tr - 1)
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
				cout << "Current value:"<< DataTank[index]->getName() <<endl;
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

void RusFactory::deleteTank()
{
	int index;
	int choice;
	Tank** tmp;
	int j = 0;

	if (!size_tr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i=0; i < size_tr; i++)
		{
			cout << i << ")." << DataTank[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_tr - 1)
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
			if (size_tr == 1)
			{
				delete[] DataTank;
				DataTank = nullptr;
				cout << "Unit deleted." << endl;
				size_tr--;
				system("pause");
				return;
			}
			tmp = new Tank * [size_tr - 1];
			j = 0;
			for (int i = 0; i < size_tr; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataTank[i];
			}
			delete[] DataTank;
			DataTank = tmp;
			cout << "Unit deleted." << endl;
			size_tr--;
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
		Tank **tmp = new Tank * [size_tr + 1];
		for (int i = 0; i < size_tr; i++)
		{
			tmp[i] = DataTank[i];
		}
		tmp[size_tr] = new RusTank;
		if (tmp[size_tr]->load(fin) != -1)
		{
			size_tr++;
			delete[] DataTank;
			DataTank = tmp;
		}
		else
		{
			cout<<"There is an error in file, edit it correctly";
			fin.close();
			return;
		}
	}
	fin.close();
	cout << "Units load on file rustank.txt" << endl;
	system("pause");
}

void RusFactory::saveTank()
{
	ofstream fout("rustank.txt");
	for (int i = 0; i < size_tr; i++)
	{
		for (int i = 0; i < size_tr; i++)
		{
			DataTank[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rustank.txt" << endl;
	system("pause");
}

void RusFactory::createBTR()
{
	{
		BTR** tmp = new BTR * [size_br + 1];
		for (int i = 0; i < size_br; i++)
		{
			tmp[i] = DataBTR[i];
		}
		tmp[size_br] = new RusBTR;
		tmp[size_br]->setName();
		tmp[size_br]->setArea();
		tmp[size_br]->setYear();
		tmp[size_br]->setAmount();
		tmp[size_br]->setWeight();
		tmp[size_br]->setCrew();
		size_br++;
		if (DataBTR)
			delete[] DataBTR;
		DataBTR = tmp;
		cout << "BTR is succesefully created." << endl;
	}
}

void RusFactory::printBTR()
{
	try
	{
		if (!size_br)
		{
			throw(string)"The Russian Factory is empty, download tanks or build BTR;";
		}
		cout << "Russian BTR" << endl;
		for (int i = 0; i < size_br; i++)
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

void RusFactory::editBTR()
{
	int index;
	int choice;
	if (!size_br)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a BTR." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_br; i++)
		{
			cout << i << ")." << DataBTR[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_br - 1)
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

void RusFactory::deleteBTR()
{
	int index;
	int choice;
	BTR** tmp;
	int j = 0;

	if (!size_tr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_tr; i++)
		{
			cout << i << ")." << DataBTR[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_tr - 1)
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
			if (size_tr == 1)
			{
				delete[] DataBTR;
				DataBTR = nullptr;
				cout << "Unit deleted." << endl;
				size_tr--;
				system("pause");
				return;
			}
			tmp = new BTR * [size_br - 1];
			j = 0;
			for (int i = 0; i < size_br; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataBTR[i];
			}
			delete[] DataBTR;
			DataBTR = tmp;
			cout << "Unit deleted." << endl;
			size_br--;
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

void RusFactory::loadBTR()
{
	ifstream fin("rusbtr.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		BTR** tmp = new BTR * [size_br + 1];
		for (int i = 0; i < size_br; i++)
		{
			tmp[i] = DataBTR[i];
		}
		tmp[size_br] = new RusBTR;
		if (tmp[size_br]->load(fin) != -1)
		{
			size_br++;
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
	cout << "Units load on file rusbtr.txt" << endl;
	system("pause");
}

void RusFactory::saveBTR()
{
	ofstream fout("rusBTR.txt");
	for (int i = 0; i < size_br; i++)
	{
		for (int i = 0; i < size_br; i++)
		{
			DataBTR[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rusbtr.txt" << endl;
	system("pause");
}