#include <iostream>
#include "Factory.h"
#include "RusFactory.h"
#include "UsaFactory.h"
using namespace std;

int main()
{
	UsaFactory Data1;
	RusFactory Data2;
	int menu;
	int choice_veh;
	int choice_option;
	do
	{
		system("cls");
		cout << "Hi, anon, what do you want to do?:" << endl
			<< "1). Check USA Hangar." << endl
			<< "2). Check Russian Hangar." << endl
			<< "3). Leave." << endl;
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			system("cls");
			cout << "Choose vehicle:" << endl
				<< "1).Tank" << endl
				<< "2).BTR" << endl
				<< "3).Robot" << endl
				<< "4).Howitzer" << endl
				<< "5).Plane" << endl
				<< "6).Leave program" << endl;
			cin >> choice_veh;
			switch (choice_veh)
			{
			case 1:
			{
				cout << "What do you want to do with tanks?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data1.createTank();
					break;
				}
				case 2:
				{
					Data1.printTank();
					break;
				}
				case 3:
					Data1.loadTank();
					break;
				case 4:
					Data1.saveTank();
					break;
				case 5:
					Data1.deleteTank();
					break;
				case 6:
					Data1.editTank();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 2:
			{
				cout << "What do you want to do with BTR?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data1.createBTR();
					break;
				}
				case 2:
				{
					Data1.printBTR();
					break;
				}
				case 3:
					Data1.loadBTR();
					break;
				case 4:
					Data1.saveBTR();
					break;
				case 5:
					Data1.deleteBTR();
					break;
				case 6:
					Data1.editBTR();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 3:
			{
				cout << "What do you want to do with Robo?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data1.createRobo();
					break;
				}
				case 2:
				{
					Data1.printRobo();
					break;
				}
				case 3:
					Data1.loadRobo();
					break;
				case 4:
					Data1.saveRobo();
					break;
				case 5:
					Data1.deleteRobo();
					break;
				case 6:
					Data1.editRobo();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
			break;
			}
			case 4:
			{
				cout << "What do you want to do with Howitzer?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data1.createHowitzer();
					break;
				}
				case 2:
				{
					Data1.printHowitzer();
					break;
				}
				case 3:
					Data1.loadHowitzer();
					break;
				case 4:
					Data1.saveHowitzer();
					break;
				case 5:
					Data1.deleteHowitzer();
					break;
				case 6:
					Data1.editHowitzer();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
			break;
			}
			case 5:
			{
				cout << "What do you want to do with Plane?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data1.createPlane();
					break;
				}
				case 2:
				{
					Data1.printPlane();
					break;
				}
				case 3:
					Data1.loadPlane();
					break;
				case 4:
					Data1.savePlane();
					break;
				case 5:
					Data1.deletePlane();
					break;
				case 6:
					Data1.editPlane();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 6:
				cout << "Exit program..." << endl;
				return 0;
			default:
				cout << "You choose wrong number" << endl;
				return 0;
				;
			}
			break;
		}
		case 2:
		{
			system("cls");
			cout << "Choose vehicle:" << endl
				<< "1).Tank" << endl
				<< "2).BTR" << endl
				<< "3).Robot" << endl
				<< "4).Howitzer" << endl
				<< "5).Plane" << endl
				<< "6).Leave program" << endl;
			cin >> choice_veh;
			switch (choice_veh)
			{
			case 1:
			{
				cout << "What do you want to do with tanks?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data2.createTank();
					break;
				}
				case 2:
				{
					Data2.printTank();
					break;
				}
				case 3:
					Data2.loadTank();
					break;
				case 4:
					Data2.saveTank();
					break;
				case 5:
					Data2.deleteTank();
					break;
				case 6:
					Data2.editTank();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 2:
			{
				cout << "What do you want to do with BTR?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data2.createBTR();
					break;
				}
				case 2:
				{
					Data2.printBTR();
					break;
				}
				case 3:
					Data2.loadBTR();
					break;
				case 4:
					Data2.saveBTR();
					break;
				case 5:
					Data2.deleteBTR();
					break;
				case 6:
					Data2.editBTR();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 3:
			{
				cout << "What do you want to do with Robo?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data2.createRobo();
					break;
				}
				case 2:
				{
					Data2.printRobo();
					break;
				}
				case 3:
					Data2.loadRobo();
					break;
				case 4:
					Data2.saveRobo();
					break;
				case 5:
					Data2.deleteRobo();
					break;
				case 6:
					Data2.editRobo();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 4:
			{
				cout << "What do you want to do with Howitzer?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data2.createHowitzer();
					break;
				}
				case 2:
				{
					Data2.printHowitzer();
					break;
				}
				case 3:
					Data2.loadHowitzer();
					break;
				case 4:
					Data2.saveHowitzer();
					break;
				case 5:
					Data2.deleteHowitzer();
					break;
				case 6:
					Data2.editHowitzer();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 5:
			{
				cout << "What do you want to do with Plane?" << endl
					<< "1).Create" << endl
					<< "2).Print" << endl
					<< "3).Load" << endl
					<< "4).Save" << endl
					<< "5).Delete" << endl
					<< "6).Edit" << endl
					<< "7).Leave program" << endl;
				cin >> choice_option;
				switch (choice_option)
				{
				case 1:
				{
					Data2.createPlane();
					break;
				}
				case 2:
				{
					Data2.printPlane();
					break;
				}
				case 3:
					Data2.loadPlane();
					break;
				case 4:
					Data2.savePlane();
					break;
				case 5:
					Data2.deletePlane();
					break;
				case 6:
					Data2.editPlane();
					break;
				case 7:
					cout << "Exit program..." << endl;
					return 0;
				default:
					cout << "You choose wrong number" << endl;
					return 0;
				}
				break;
			}
			case 6:
				cout << "Exit program..." << endl;
				return 0;
			default:
				cout << "You choose wrong number" << endl;
				return 0;
				;
			}
			break;
		}
		case 3:
		{
			cout << "Exit..." << endl;
			return 0;
		}
		default:
			cout << "You choose wrong number" << endl;
			return 0;
		}
	} while (true);
}