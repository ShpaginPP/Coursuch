#include "RusBTR.h"

string RusBTR::setName()
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

string RusBTR::setArea()
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

string RusBTR::setYear()
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

string RusBTR::setAmount()
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

string RusBTR::setWeight()
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

string RusBTR::setCrew()
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

void RusBTR::print()
{
	cout << "Tank's name: " << this->name << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
}

void RusBTR::save(ofstream& fout)
{
	fout << "Tank's name: " << this->name << endl
		<< "Area of movement: " << this->area << endl
		<< "Date of assembly: " << this->year << endl
		<< "Amount of Tanks in hangar: " << this->amount << endl
		<< "Weight: " << this->weight << endl
		<< "Number of people in the crew: " << this->crew << endl
		<< "====================================" << endl;
	cout << "All data saved" << endl;
}

int RusBTR::load(ifstream& fin)
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
	catch (string error)
	{
		cout << "ERROR:" + error << endl;
		return -1;//error signal.
	}
}

string RusBTR::getName()
{
	return name;
}

string RusBTR::getArea()
{
	return area;
}

string RusBTR::getYear()
{
	return year;
}

string RusBTR::getAmount()
{
	return amount;
}

string RusBTR::getWeight()
{
	return weight;
}

string RusBTR::getCrew()
{
	return crew;
}