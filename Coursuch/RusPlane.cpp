#include "RusPlane.h"

string RusPlane::setName()
{
	while (true)
	{
		try
		{
			cout << "Enter a Plane's name:" << endl;
			string tmp;
			cin >> tmp;
			if (tmp.empty())
			{
				throw(string)"The name cant be empty";
			}
			name = tmp;
			return name;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setPower()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter a quality of firepower" << endl;
			cin >> tmp;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			power = tmp;
			return power;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setWeapon()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a Plane, he can only have a MG." << endl;
			cin >> tmp;
			if (tmp != "MG")
				throw (string)"You can choose only \"MG\" as a weapon.";
			weapon = tmp;
			return weapon;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setRange()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter range of weapon(until 3 km)" << endl;
			cin >> tmp;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			int test;
			test = stoi(tmp);
			if (test > 3)
			{
				throw(string)"Too much range.";
			}
			range = tmp;
			return range;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setCaliber()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a Plane, its MG has 10 caliber." << endl;
			cin >> tmp;
			if (tmp != "10")
			{
				throw (string)"The caliber of SMG is 12.";
			}
			caliber = tmp;
			return caliber;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setArea()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a Plane, it can only move on the air." << endl;
			cin >> tmp;
			if (tmp != "ground")
				throw (string)"You can choose only \"air\" as an movement area.";
			area = tmp;
			return area;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setYear()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Set year of assembly" << endl;
			cin >> tmp;
			if (tmp.length() > 4)
				throw (string)"Incorrect size of year, try again.";
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			year = tmp;
			return year;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setAmount()
{
	while (true)
	{
		try
		{
			cout << "Enter amount of this tanks(until 10)." << endl;
			string tmp;
			cin >> tmp;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			int test = stoi(tmp);
			if (test > 10)
				throw(string)"The hangar is designed for 10 combat vehicles";
			amount = tmp;
			return amount;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setWeight()
{
	while (true)
	{
		try
		{
			cout << "Enter a weight of your plane (from 20 tons to 30 tons)." << endl;
			string tmp;
			cin >> tmp;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			int test1 = stoi(tmp);
			if ((test1 > 30) || (test1 < 20))
				throw(string)"The a Plane cannot weigh less than 20 tons and more than 30";
			weight = tmp;
			return weight;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusPlane::setCrew()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter a number of people of your plane (from 2 to 3 man)." << endl;
			cin >> tmp;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			int test = stoi(tmp);
			if ((test > 3) || (test < 2))
				throw(string)"The number of people is incorrect.";
			crew = tmp;
			return crew;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

void RusPlane::print()
{
	cout << "Plane's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Planes in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "====================================" << endl;
}

void RusPlane::save(ofstream& fout)
{
	fout << "Plane's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Planets in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

int RusPlane::load(ifstream& fin)
{
	try
	{
		string tmp;
		string line;
		tmp = "Plane's name: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		name = line;
		tmp = "Range: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric. ";
				break;
			}
		}
		int test;
		test = stoi(line);
		if (test > 3)
		{
			throw(string)"Too much range.";
		}
		range = line;
		tmp = "Firepower: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		power = line;
		tmp = "Weaponry: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		if (line != "MG")
		{
			throw (string)"You can choose only MG";
		}
		weapon = line;
		tmp = "Caliber: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		if (line != "12")
		{
			throw (string)"The caliber of MG is 12.";
		}
		caliber = line;
		tmp = "Area of movement: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the Plane is not in the file.";
		}
		if (line != "air")
		{
			throw (string)"You can choose only \"air\" as an movament area.";
		}
		area = line;
		tmp = "Date of assembly: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Planet is not in the file.";
		}
		if (line.length() > 4)
		{
			throw (string)"Incorrect size of year, try again.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		year = line;
		tmp = "Amount of Planes in hangar: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		test = stoi(line);
		if (test > 10)
		{
			throw(string)"The hangar is designed for 10 combat vehicles";
		}
		amount = line;
		tmp = "Weight: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the Plane is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		int test1 = stoi(line);
		if ((test1 > 30) || (test1 < 20))
			throw(string)"The a tank cannot weigh less than 1 tons and more than 3";
		weight = line;
		tmp = "Number of people in the crew: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the plane is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		test = stoi(line);
		if ((test > 3) || (test < 2))
			throw(string)"The number of people is incorrect.";
		crew = line;
		getline(fin, line);
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
		return -1;//error signal.
	}
}

string RusPlane::getName()
{
	return name;
}

string RusPlane::getRange()
{
	return range;
}

string RusPlane::getPower()
{
	return power;
}

string RusPlane::getWeapon()
{
	return weapon;
}

string RusPlane::getCaliber()
{
	return caliber;
}

string RusPlane::getArea()
{
	return area;
}

string RusPlane::getYear()
{
	return year;
}

string RusPlane::getAmount()
{
	return amount;
}

string RusPlane::getWeight()
{
	return weight;
}

string RusPlane::getCrew()
{
	return crew;
}