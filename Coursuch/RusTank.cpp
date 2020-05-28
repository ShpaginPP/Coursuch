#include "RusTank.h"

string RusTank::setName()
{
	while (true)
	{
		try
		{
		cout << "Enter a tank's name:" << endl;
		string tmp;
		cin >> tmp;
		if (tmp == "");
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

string RusTank::setPower()
{
	while(true)
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

string RusTank::setWeapon()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Choose a weapon: Cannon or Howitzer" << endl;
			cin >> tmp;
			if (tmp != "Cannon" && tmp != "Howitzer")
				throw (string)"You can choose only between Cannon and Howitzer";
			weapon = tmp;
			return weapon;
		}
		catch(string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusTank::setRange()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter range of weapon(until 1000 km)" << endl;
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
			if (test > 1000)
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

string RusTank::setCaliber()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter caliber of weapon(Russian weapon: Howitzer - 152 mm, Cannon - 125 mm)" << endl;
			cin >> tmp;
			if (weapon == "Howitzer" && tmp!= "152")
			{
				throw (string)"For a russian howitzer you can choose only 152 mm.";
			}
			else if (weapon == "Cannon" && tmp!= "125")
			{
				throw (string)"For a russian cannon you can choose only 125 mm.";
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

string RusTank::setArea()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a tank, it can only move on the ground." << endl;
			cin >> tmp;
			if (tmp != "ground")
				throw (string)"You can choose only \"ground\" as an movament area.";
			area = tmp;
			return area;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusTank::setYear()
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

string RusTank::setAmount()
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

string RusTank::setWeight()
{
	while (true)
	{
		try
		{
			cout << "Enter a weight of your tank (from 45 tons to 70 tons)." << endl;
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
			if ((test1 > 70) || (test1 < 45))
				throw(string)"The a tank cannot weigh less than 45 tons and more than 70";
			weight = tmp;
			return weight;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusTank::setCrew()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter a number of people of your tank (from 2 to 5 man)." << endl;
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
			if ((test > 5) || (test < 2))
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

void RusTank::print()
{
	cout << "Tank's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
}

void RusTank::save(ofstream& fout)
{
	fout << "Tank's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

int RusTank::load(ifstream& fin)
{
	try 
	{
		string tmp;
		string line;
		tmp = "Tank's name: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
		}
		name = line;
		tmp = "Range: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
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
		if (test > 1000)
		{
			throw(string)"Too much range.";
		}
		range = line;
		tmp = "Firepower: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
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
			throw(string)"The name of the tank is not in the file.";
		}
		if (line != "Cannon" && line != "Howitzer")
		{
			throw (string)"You can choose only between Cannon and Howitzer";
		}
		weapon = line;
		tmp = "Caliber: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (weapon == "Howitzer" && line != "152")
		{
			throw (string)"For a russian howitzer you can choose only 152 mm.";
		}
		else if (weapon == "Cannon" && line != "125")
		{
			throw (string)"For a russian cannon you can choose only 125 mm.";
		}
		caliber = line;
		tmp = "Area of movement: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
		}
		if (line != "ground")
		{
			throw (string)"You can choose only \"ground\" as an movament area.";
		}
		area = line;
		tmp = "Date of assembly: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
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
		tmp = "Amount of Tanks in hangar: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
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
			throw(string)"The name of the tank is not in the file.";
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
		if ((test1 > 70) || (test1 < 45))
			throw(string)"The a tank cannot weigh less than 45 tons and more than 70";
		weight = line;
		tmp = "Number of people in the crew: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the tank is not in the file.";
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
		if ((test > 5) || (test < 2))
			throw(string)"The number of people is incorrect.";
		crew = line;
		getline(fin, line);
	}
	catch(string error)
	{
		cout << "ERROR:" + error << endl;
		return -1;//error signal.
	}
}

string RusTank::getName()
{
	return name;
}

string RusTank::getRange()
{
	return range;
}

string RusTank::getPower()
{
	return power;
}

string RusTank::getWeapon()
{
	return weapon;
}

string RusTank::getCaliber()
{
	return caliber;
}

string RusTank::getArea()
{
	return area;
}

string RusTank::getYear()
{
	return year;
}

string RusTank::getAmount()
{
	return amount;
}

string RusTank::getWeight()
{
	return weight;
}

string RusTank::getCrew()
{
	return crew;
}