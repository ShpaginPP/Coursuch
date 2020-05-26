#include "RusTank.h"

string RusTank::setName()
{
	cout << "Enter a tank's name:" << endl;
	string tmp;	
	getline(cin, tmp);
	name = tmp;
	return name;
}

string RusTank::setPower()
{
	while(true)
	{ 
		try
		{
			string tmp;
			cout << "Enter a quality of firepower" << endl;
			getline(cin, tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
			for (int i = 0; i < tmp.length(); i++)
			{
				if (((tmp[i] >= 'A') && (tmp[i] <= 'Z')) || ((tmp[i] >= 'a') && (tmp[i] <= 'z')))
				{
					throw(string)"This parameter must be numeric.";
					break;
				}
			}
			int test = stoi(tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
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
			getline(cin, tmp);
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
		<< "Weponry: " << this->weapon << endl
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
		<< "Weponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

void RusTank::load(ifstream& fin)
{
	string tmp;
	string line;
	tmp = "Tank's name: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	name = line;
	tmp = "Range: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	range = line;
	tmp = "Firepower: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	power = line;
	tmp = "Weponry: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	weapon = line;
	tmp = "Caliber: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	caliber = line;
	tmp = "Area of movement: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	area = line;
	tmp = "Date of assembly: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	year = line;
	tmp = "Amount of Tanks in hangar: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	amount = line;
	tmp = "Weight: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	weight = line;
	tmp = "Number of people in the crew: ";
	getline(fin, line);
	line.replace(line.find(tmp), tmp.length(), "");
	crew = line;
	getline(fin, line);
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