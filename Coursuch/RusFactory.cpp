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

	if (!size_br)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a tank." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_br; i++)
		{
			cout << i << ")." << DataBTR[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_br - 1)
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
			if (size_br == 1)
			{
				delete[] DataBTR;
				DataBTR = nullptr;
				cout << "Unit deleted." << endl;
				size_br--;
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
	ofstream fout("rusbtr.txt");
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

void  RusFactory::createRobo()
{
	{
		Robo** tmp = new Robo * [size_rr + 1];
		for (int i = 0; i < size_rr; i++)
		{
			tmp[i] = DataRobo[i];
		}
		tmp[size_rr] = new RusRobo;
		tmp[size_rr]->setName();
		tmp[size_rr]->setRange();
		tmp[size_rr]->setPower();
		tmp[size_rr]->setWeapon();
		tmp[size_rr]->setCaliber();
		tmp[size_rr]->setArea();
		tmp[size_rr]->setYear();
		tmp[size_rr]->setAmount();
		tmp[size_rr]->setWeight();
		size_rr++;
		if (DataRobo)
			delete[] DataRobo;
		DataRobo = tmp;
		cout << "Robo is succesefully created." << endl;
	}
}

void  RusFactory::printRobo()
{
	try
	{
		if (!size_rr)
		{
			throw(string)"The Russian Factory is empty, download tanks or build tanks;";
		}
		cout << "Russian robots" << endl;
		for (int i = 0; i < size_rr; i++)
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

void RusFactory::editRobo()
{
	int index;
	int choice;
	if (!size_rr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a robot." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_rr; i++)
		{
			cout << i << ")." << DataRobo[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_rr - 1)
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

void  RusFactory::deleteRobo()
{
	int index;
	int choice;
	Robo** tmp;
	int j = 0;

	if (!size_rr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Robo." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_rr; i++)
		{
			cout << i << ")." << DataRobo[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_rr - 1)
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
			if (size_rr == 1)
			{
				delete[] DataRobo;
				DataRobo = nullptr;
				cout << "Unit deleted." << endl;
				size_rr--;
				system("pause");
				return;
			}
			tmp = new Robo * [size_rr - 1];
			j = 0;
			for (int i = 0; i < size_rr; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataRobo[i];
			}
			delete[] DataRobo;
			DataRobo = tmp;
			cout << "Unit deleted." << endl;
			size_rr--;
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

void RusFactory::loadRobo()
{
	ifstream fin("rusrobo.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Robo** tmp = new Robo * [size_rr + 1];
		for (int i = 0; i < size_rr; i++)
		{
			tmp[i] = DataRobo[i];
		}
		tmp[size_rr] = new RusRobo;
		if (tmp[size_rr]->load(fin) != -1)
		{
			size_rr++;
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
	cout << "Units load on file rusrobo.txt" << endl;
	system("pause");
}

void RusFactory::saveRobo()
{
	ofstream fout("rusrobo.txt");
	for (int i = 0; i < size_rr; i++)
	{
		for (int i = 0; i < size_rr; i++)
		{
			DataRobo[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rusrobo.txt" << endl;
	system("pause");
}

void RusFactory::createHowitzer()
{
	Howitzer** tmp = new Howitzer * [size_hr + 1];
	for (int i = 0; i <size_hr; i++)
	{
		tmp[i] = DataHowitzer[i];
	}
	tmp[size_hr] = new RusHowitzer;
	tmp[size_hr]->setName();
	tmp[size_hr]->setRange();
	tmp[size_hr]->setPower();
	tmp[size_hr]->setWeapon();
	tmp[size_hr]->setCaliber();
	tmp[size_hr]->setArea();
	tmp[size_hr]->setYear();
	tmp[size_hr]->setAmount();
	tmp[size_hr]->setWeight();
	tmp[size_hr]->setCrew();
	size_hr++;
	if (DataHowitzer)
		delete[] DataHowitzer;
	DataHowitzer = tmp;
	cout << "Howitzer is succesefully created." << endl;
}

void RusFactory::printHowitzer()
{
	try
	{
		if (!size_hr)
		{
			throw(string)"The Russian Factory is empty, download Howitzers or build Howitzers;";
		}
		cout << "Russian Howitzers" << endl;
		for (int i = 0; i < size_hr; i++)
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

void RusFactory::editHowitzer()
{
	int index;
	int choice;
	if (!size_hr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Howitzer." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_hr; i++)
		{
			cout << i << ")." << DataHowitzer[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_hr - 1)
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

void RusFactory::deleteHowitzer()
{
	int index;
	int choice;
	Howitzer** tmp;
	int j = 0;

	if (!size_hr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Howitzer." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_hr; i++)
		{
			cout << i << ")." << DataHowitzer[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_hr - 1)
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
			if (size_hr == 1)
			{
				delete[] DataHowitzer;
				DataHowitzer = nullptr;
				cout << "Unit deleted." << endl;
				size_hr--;
				system("pause");
				return;
			}
			tmp = new Howitzer * [size_hr - 1];
			j = 0;
			for (int i = 0; i < size_hr; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataHowitzer[i];
			}
			delete[] DataHowitzer;
			DataHowitzer = tmp;
			cout << "Unit deleted." << endl;
			size_hr--;
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

void RusFactory::loadHowitzer()
{
	ifstream fin("rushowitzer.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Howitzer** tmp = new Howitzer * [size_hr + 1];
		for (int i = 0; i < size_hr; i++)
		{
			tmp[i] = DataHowitzer[i];
		}
		tmp[size_hr] = new RusHowitzer;
		if (tmp[size_hr]->load(fin) != -1)
		{
			size_hr++;
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
	cout << "Units load on file rushowitzer.txt" << endl;
	system("pause");
}

void RusFactory::saveHowitzer()
{
	ofstream fout("rushowitzer.txt");
	for (int i = 0; i < size_hr; i++)
	{
		for (int i = 0; i < size_hr; i++)
		{
			DataHowitzer[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rushowitzer.txt" << endl;
	system("pause");
}

void RusFactory::createPlane()
{
	Plane** tmp = new Plane * [size_pr + 1];
	for (int i = 0; i < size_pr; i++)
	{
		tmp[i] = DataPlane[i];
	}
	tmp[size_pr] = new RusPlane;
	tmp[size_pr]->setName();
	tmp[size_pr]->setRange();
	tmp[size_pr]->setPower();
	tmp[size_pr]->setWeapon();
	tmp[size_pr]->setCaliber();
	tmp[size_pr]->setArea();
	tmp[size_pr]->setYear();
	tmp[size_pr]->setAmount();
	tmp[size_pr]->setWeight();
	tmp[size_pr]->setCrew();
	size_pr++;
	if (DataPlane)
		delete[] DataPlane;
	DataPlane = tmp;
	cout << "Plane is succesefully created." << endl;
}

void RusFactory::printPlane()
{
	try
	{
		if (!size_pr)
		{
			throw(string)"The Russian Factory is empty, download Planes or build Planes;";
		}
		cout << "Russian Planes" << endl;
		for (int i = 0; i < size_pr; i++)
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

void RusFactory::editPlane()
{
	int index;
	int choice;
	if (!size_pr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Plane." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_pr; i++)
		{
			cout << i << ")." << DataPlane[i]->getName() << endl;
		}
		cout << "Select unit to edit:" << endl;
		cin >> index;
		if (index < 0 || index > size_pr - 1)
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

void RusFactory::deletePlane()
{
	int index;
	int choice;
	Plane** tmp;
	int j = 0;

	if (!size_pr)
	{
		cout << "There are no combat units in the hangar. Download information from a file or create a Plane." << endl;
		system("pause");
		return;
	}
	try
	{
		for (int i = 0; i < size_pr; i++)
		{
			cout << i << ")." << DataPlane[i]->getName() << endl;
		}
		cout << "Select unit to delete:" << endl;
		cin >> index;
		if (index < 0 || index > size_pr - 1)
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
			if (size_pr == 1)
			{
				delete[] DataPlane;
				DataPlane = nullptr;
				cout << "Unit deleted." << endl;
				size_pr--;
				system("pause");
				return;
			}
			tmp = new Plane * [size_pr - 1];
			j = 0;
			for (int i = 0; i < size_pr; i++)
			{
				if (index == i)
					continue;
				tmp[j++] = DataPlane[i];
			}
			delete[] DataPlane;
			DataPlane = tmp;
			cout << "Unit deleted." << endl;
			size_pr--;
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

void RusFactory::loadPlane()
{
	ifstream fin("rusplane.txt");
	while (!fin.eof())
	{
		if (fin.peek() == -1)
			break;
		Plane** tmp = new Plane * [size_pr + 1];
		for (int i = 0; i < size_pr; i++)
		{
			tmp[i] = DataPlane[i];
		}
		tmp[size_pr] = new RusPlane;
		if (tmp[size_pr]->load(fin) != -1)
		{
			size_pr++;
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
	cout << "Units load on file rusplane.txt" << endl;
	system("pause");
}

void RusFactory::savePlane()
{
	ofstream fout("rusplane.txt");
	for (int i = 0; i < size_pr; i++)
	{
		for (int i = 0; i < size_pr; i++)
		{
			DataPlane[i]->save(fout);
		}
	}
	fout.close();
	cout << "Units saves to file rusplane.txt" << endl;
	system("pause");
}