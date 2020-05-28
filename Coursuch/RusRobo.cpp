#include "RusRobo.h"

string RusRobo::setName()
{
	while (true)
	{
		try
		{
			cout << "Enter a Robo's name:" << endl;
			string tmp;
			cin >> tmp;
			if (tmp.empty());
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

string RusRobo::setPower()
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

string RusRobo::setWeapon()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a robot, he can only have a SMG." << endl;
			cin >> tmp;
			if (tmp != "SMG")
				throw (string)"You can choose only \"SMG\" as a weapon.";
			weapon = tmp;
			return weapon;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusRobo::setRange()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "Enter range of weapon(until 10 km)" << endl;
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
			if (test > 10)
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

string RusRobo::setCaliber()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a robot, its SMG has 12 caliber." << endl;
			cin >> tmp;
			if (tmp != "12")
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

string RusRobo::setArea()
{
	while (true)
	{
		try
		{
			string tmp;
			cout << "This is a Robo, it can only move on the ground." << endl;
			cin >> tmp;
			if (tmp != "ground")
				throw (string)"You can choose only \"ground\" as an movement area.";
			area = tmp;
			return area;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

string RusRobo::setYear()
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

string RusRobo::setAmount()
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

string RusRobo::setWeight()
{
	while (true)
	{
		try
		{
			cout << "Enter a weight of your tank (from 1 tons to 3 tons)." << endl;
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
			if ((test1 > 3) || (test1 < 1))
				throw(string)"The a robo cannot weigh less than 1 tons and more than 3";
			weight = tmp;
			return weight;
		}
		catch (string error)
		{
			cout << "ERROR:" + error << endl;
		}
	}
}

void RusRobo::print()
{
	cout << "Robo's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Robos in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "====================================" << endl;
}

void RusRobo::save(ofstream& fout)
{
	fout << "Robo's name: " << this->name << endl
		<< "Range: " << this->range << endl
		<< "Firepower: " << this->power << endl
		<< "Weaponry: " << this->weapon << endl
		<< "Caliber: " << this->caliber << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Robots in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

int RusRobo::load(ifstream& fin)
{
	try
	{
		string tmp;
		string line;
		tmp = "Robo's name: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the robot is not in the file.";
		}
		name = line;
		tmp = "Range: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the robot is not in the file.";
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
		if (test > 10)
		{
			throw(string)"Too much range.";
		}
		range = line;
		tmp = "Firepower: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the robo is not in the file.";
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
			throw(string)"The data of the robo is not in the file.";
		}
		if (line != "SMG")
		{
			throw (string)"You can choose only SMG";
		}
		weapon = line;
		tmp = "Caliber: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the robo is not in the file.";
		}
		if (line != "12")
		{
			throw (string)"The caliber of SMG is 12.";
		}
		caliber = line;
		tmp = "Area of movement: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the robo is not in the file.";
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
			throw(string)"The data of the robot is not in the file.";
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
		tmp = "Amount of Robots in hangar: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The data of the robo is not in the file.";
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
			throw(string)"The data of the robo is not in the file.";
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
		if ((test1 > 3) || (test1 < 1))
			throw(string)"The a tank cannot weigh less than 1 tons and more than 3";
		weight = line;
		getline(fin, line);
	}
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
		return -1;//error signal.
	}
}

string RusRobo::getName()
{
	return name;
}

string RusRobo::getRange()
{
	return range;
}

string RusRobo::getPower()
{
	return power;
}

string RusRobo::getWeapon()
{
	return weapon;
}

string RusRobo::getCaliber()
{
	return caliber;
}

string RusRobo::getArea()
{
	return area;
}

string RusRobo::getYear()
{
	return year;
}

string RusRobo::getAmount()
{
	return amount;
}

string RusRobo::getWeight()
{
	return weight;
}