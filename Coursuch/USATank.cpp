#include "UsaTank.h"

string UsaTank::setName()
{
	while (true)
	{
		try
		{
			cout << "Enter a tank's name:" << endl;
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

string UsaTank::setPower()
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

string UsaTank::setWeapon()
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
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string UsaTank::setRange()
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

string UsaTank::setCaliber()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter caliber of weapon(Usasian weapon: Howitzer - 150 mm, Cannon - 120 mm)" << endl;
			cin >> tmp;
			if (weapon == "Howitzer" && tmp != "150")
			{
				throw (string)"For a Usasian howitzer you can choose only 150 mm.";
			}
			else if (weapon == "Cannon" && tmp != "120")
			{
				throw (string)"For a Usasian cannon you can choose only 120 mm.";
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

string UsaTank::setArea()
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

string UsaTank::setYear()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Set year of assembly" << endl;
			cin >> tmp;
			if (tmp.length() > 4)
				throw (string)"Incorrect size_tu of year, try again.";
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

string UsaTank::setAmount()
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

string UsaTank::setWeight()
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

string UsaTank::setCrew()
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

void UsaTank::print()
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

void UsaTank::save(ofstream& fout)
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

int UsaTank::load(ifstream& fin)
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
			throw(string)"The data of the tank is not in the file.";
		}
		name = line;
		tmp = "Range: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the tank is not in the file.";
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
			throw(string)"The data of the tank is not in the file.";
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
			throw(string)"The data of the tank is not in the file.";
		}
		if (line != "Cannon" && line != "Howitzer")
		{
			throw (string)"You can choose only between Cannon and Howitzer";
		}
		weapon = line;
		tmp = "Caliber: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (weapon == "Howitzer" && line != "150")
		{
			throw (string)"For a USA howitzer you can choose only 150 mm.";
		}
		else if (weapon == "Cannon" && line != "120")
		{
			throw (string)"For a Usasian cannon you can choose only 120 mm.";
		}
		caliber = line;
		tmp = "Area of movement: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the tank is not in the file.";
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
			throw(string)"The data of the tank is not in the file.";
		}
		if (line.length() > 4)
		{
			throw (string)"Incorrect size_tu of year, try again.";
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
			throw(string)"The data of the tank is not in the file.";
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
			throw(string)"The data of the tank is not in the file.";
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
			throw(string)"The a data cannot weigh less than 45 tons and more than 70";
		weight = line;
		tmp = "Number of people in the crew: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the tank is not in the file.";
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
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
		return -1;//error signal.
	}
}

string UsaTank::getName()
{
	return name;
}

string UsaTank::getRange()
{
	return range;
}

string UsaTank::getPower()
{
	return power;
}

string UsaTank::getWeapon()
{
	return weapon;
}

string UsaTank::getCaliber()
{
	return caliber;
}

string UsaTank::getArea()
{
	return area;
}

string UsaTank::getYear()
{
	return year;
}

string UsaTank::getAmount()
{
	return amount;
}

string UsaTank::getWeight()
{
	return weight;
}

string UsaTank::getCrew()
{
	return crew;
}