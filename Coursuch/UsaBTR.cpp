#include "UsaBTR.h"

string UsaBTR::setName()
{
	while (true)
	{
		try
		{
			cout << "Enter a BTR's name:" << endl;
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

string UsaBTR::setArea()
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

string UsaBTR::setYear()
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

string UsaBTR::setAmount()
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

string UsaBTR::setWeight()
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

string UsaBTR::setCrew()
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

void UsaBTR::print()
{
	cout << "BTR's name: " << this->name << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
}

void UsaBTR::save(ofstream& fout)
{
	fout << "BTR's name: " << this->name << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

int UsaBTR::load(ifstream& fin)
{
	try
	{
		string tmp;
		string line;
		tmp = "BTR's name: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the BTR is not in the file.";
		}
		name = line;
		tmp = "Area of movement: ";
		getline(fin, line);
		line.replace(line.find(tmp), tmp.length(), "");
		if (line.empty())
		{
			throw(string)"The name of the BTR is not in the file.";
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
			throw(string)"The name of the BTR is not in the file.";
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
			throw(string)"The name of the BTR is not in the file.";
		}
		for (int i = 0; i < line.length(); i++)
		{
			if (((line[i] >= 'A') && (line[i] <= 'Z')) || ((line[i] >= 'a') && (line[i] <= 'z')))
			{
				throw(string)"This parameter must be numeric.";
				break;
			}
		}
		int test;
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
			throw(string)"The name of the BTR is not in the file.";
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
			throw(string)"The name of the BTR is not in the file.";
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

string UsaBTR::getName()
{
	return name;
}

string UsaBTR::getArea()
{
	return area;
}

string UsaBTR::getYear()
{
	return year;
}

string UsaBTR::getAmount()
{
	return amount;
}

string UsaBTR::getWeight()
{
	return weight;
}

string UsaBTR::getCrew()
{
	return crew;
}