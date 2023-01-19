/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Parking.h"
#include <cstring>
#include <fstream>

using std::endl;
using std::cin;
using std::cout;

namespace sdds
{
	void Parking::setEmpty()
	{
		delete[] this->filePath;
		this->filePath = nullptr;
		//parkingMenu.setIndent(0);
		parkingMenu.indent = 0;
		parkingMenu.setTitle("");

		//vehicleMenu.setIndent(0);
		vehicleMenu.indent = 0;
		vehicleMenu.setTitle("");
	}

	bool Parking::loadDataFile()
	{
		bool ret = true;
		if (!isEmpty())
		{
			/*cout << "---------------------------------" << endl;
			cout << "loading data from " << this->filePath << endl;
			cout << "---------------------------------" << endl << endl;*/
			std::ifstream f(this->filePath, std::ios::in);


			if (!f.is_open())
			{
				this->setEmpty();
				ret = true;
			}
			else
			{
				char temp{};
				Vehicle* V = nullptr;

				while (f.get(temp))
				{

					f.ignore(1000, ',');
					if (temp == 'M')
					{
						V = new Motorcycle();
						V->setCsv(true);
						V->read(f);

						parkingSpot[V->getParkingSpot() - 1] = V;
						this->noParkedVehicles++;
					}
					else if (temp == 'C')
					{
						V = new Car();
						V->setCsv(true);
						V->read(f);

						parkingSpot[V->getParkingSpot() - 1] = V;
						this->noParkedVehicles++;
					}
					else
					{
						delete V;
						V = nullptr;
						ret = false;
					}

				}
				f.close();
			}

		}
		else
			ret = false;

		return ret;

	}
	void Parking::saveDataFile()
	{

		if (!isEmpty())
		{
			//cout << "---------------------------------" << endl;
			//cout << "Saving data into " << this->filePath << endl;
			//cout << "---------------------------------" << endl;
		//	cout << "BEFORE:" << this->filePath << endl << endl;
			std::ofstream f(this->filePath, std::ios::out);
			bool val = true;
			//	cout << "AFTER:" << this->filePath << endl << endl;

			if (!f)
			{
				//	cout << "ERROR openeing file for writing";
			}
			else
			{
				for (int i = 0; i < this->noOfSpot; i++)
				{
					if (this->parkingSpot[i] != nullptr)
					{
						this->parkingSpot[i]->setCsv(val);
						this->parkingSpot[i]->write(f);
					}
				}
				f.close();
			}
		}

		//
	}



	Parking::Parking()
	{
		this->filePath = nullptr;
		this->noParkedVehicles = 0;

	}
	Parking::Parking(const char* c, int num)
	{
		if (c != nullptr && c[0] != '\0')
		{
			this->filePath = new char[strlen(c) + 1];
			strcpy(this->filePath, c);
			//this->noOfSpot = num;


			if (this->loadDataFile())
			{
				this->parkingMenu.indent = 0;
				parkingMenu.setTitle("Parking Menu, select an action:");
				parkingMenu.add("Park Vehicle");
				parkingMenu.add("Return Vehicle");
				parkingMenu.add("List Parked Vehicles");
				parkingMenu.add("Find Vehicle");
				parkingMenu.add("Close Parking (End of day)");
				parkingMenu.add("Exit Program");

				vehicleMenu.indent = 1;
				vehicleMenu.setTitle("Select type of the vehicle:");
				vehicleMenu.add("Car");
				vehicleMenu.add("Motorcycle");
				vehicleMenu.add("Cancel");

			}
			else
			{
				cout << "Error in data file" << endl;

				delete[] this->filePath;
				this->filePath = nullptr;

				parkingMenu.indent = 0;
				parkingMenu.setTitle("");
				vehicleMenu.indent = 0;
				vehicleMenu.setTitle("");
				this->noOfSpot = 0;
			}
		}

		else
		{
			cout << "Error in data file" << endl;


			this->filePath = nullptr;

			parkingMenu.indent = 0;
			parkingMenu.setTitle("");
			vehicleMenu.indent = 0;
			vehicleMenu.setTitle("");
		}

		if (noOfSpot > 10 && noOfSpot < maxSpotNo)
		{
			this->noParkedVehicles = 0;
			this->noOfSpot = 0;
		}
		else
		{
			this->noOfSpot = num;
		}
	}

	Parking::~Parking()
	{

		this->saveDataFile();
		delete[] this->filePath;

		this->filePath = nullptr;

		for (int i = 0; i < this->noOfSpot; i++)
		{
			delete this->parkingSpot[i];
			this->parkingSpot[i] = nullptr;

		}
	}
	bool Parking::isEmpty()const
	{
		return this->filePath == nullptr;
	}

	void Parking::parkingStatus()const
	{
		std::cout << "****** Valet Parking ******" << std::endl;
		cout << "*****  Available spots: ";
		cout.width(4);
		cout.setf(std::ios::left);
		cout << this->noOfSpot - this->noParkedVehicles << " *****" << endl;

	}

	void Parking::parkVehicle()
	{
		//int selection = 0;
		//cin >> selection;

		////do
		////{
		//if (selection == 1)
		//{
		//	cout << "---------------------------------" << endl
		//		<< "Parking Car" << endl
		//		<< "---------------------------------" << endl;
		//}
		//else if (selection == 2)
		//{
		//	cout << "---------------------------------" << endl
		//		<< "Parking Motorcycle" << endl
		//		<< "---------------------------------" << endl;
		//}
		//else if (selection == 3)
		//{
		//	cout << "---------------------------------" << endl
		//		<< "Cancelled parking" << endl
		//		<< "---------------------------------" << endl;
		//}

		////} while (selection < 1 || selection > 3);

		Vehicle* V{};
		bool cancelled = true;


		if (this->noParkedVehicles < this->noOfSpot)
		{
			int run = this->vehicleMenu.run();

			if (run == 1)
			{
				cancelled = false;
				V = new Car();
			}
			else if (run == 2)
			{
				cancelled = false;
				V = new Motorcycle();
			}
			else if (run == 3)
			{
				cout << "Parking Cancelled" << endl;
			}
		}
		else
		{
			cout << "Parking is full" << endl;
		}

		if (!cancelled) {
			V->setCsv(false);
			V->read(cin);

			for (int i = 0; i < this->noOfSpot; i++)
			{
				if (this->parkingSpot[i] == nullptr)
				{
					this->parkingSpot[i] = V;
					this->parkingSpot[i]->setParkingSpot(i + 1);
					cout << endl << "Parking Ticket" << endl;
					this->parkingSpot[i]->write(cout) << endl;
					this->noParkedVehicles++;
				}
			}
		}




	}

	void Parking::returnVehicle()
	{
		char templno[9]{};
		bool check = true;

		cout << "Return Vehicle" << endl;
		cout << "Enter License Plate Number: ";
		while (true)
		{

			cin >> templno;
			cin.ignore(1000, '\n');
			if (strlen(templno) > 8)
			{
				cout << "Invalid License Plate, try again: ";
			}
			else
			{
				for (int i = 0; i < (int)strlen(templno); i++)
				{
					templno[i] = toupper(templno[i]);
				}


				for (int i = 0; i < this->noOfSpot; i++)
				{
					if (this->parkingSpot[i] != nullptr)
					{
						if (*this->parkingSpot[i] == templno)
						{
							check = true;

							cout << endl << "Returning:" << endl;
							this->parkingSpot[i]->setCsv(false);
							this->parkingSpot[i]->write(cout) << endl;
							delete this->parkingSpot[i];
							this->parkingSpot[i] = nullptr;
							this->noParkedVehicles--;
							break;
						}
						else
							check = false;
					}
				}

				if (check == false)
				{
					cout << endl << "License plate " << templno << " Not found" << endl << endl;
				}

				cout << "Press <ENTER> to continue....";
				cin.ignore(1000, '\n');
				break;
			}

		}

	}

	void Parking::listParkedVehicles()const
	{
		cout << "*** List of parked vehicles ***" << endl;
		for (int i = 0; i < 100; i++)
		{
			if (this->parkingSpot[i] != nullptr)
			{
				this->parkingSpot[i]->setCsv(false);
				this->parkingSpot[i]->write(std::cout);
				cout << "-------------------------------" << endl;

			}
		}
		cout << "Press <ENTER> to continue....";
		cin.ignore(1000, '\n');
	}

	void Parking::findVehicle()const
	{
		char templno[9]{};
		bool check = true;

		cout << "Vehicle Search" << endl;
		cout << "Enter Licence Plate Number: ";
		while (true)
		{

			cin >> templno;
			cin.ignore(1000, '\n');
			if (strlen(templno) > 8)
			{
				cout << "Invalid License Plate, try again: ";
			}
			else
			{
				for (int i = 0; i < (int)strlen(templno); i++)
				{
					templno[i] = toupper(templno[i]);
				}


				for (int i = 0; i < this->noOfSpot; i++)
				{
					if (this->parkingSpot[i] != nullptr)
					{
						if (*this->parkingSpot[i] == templno)
						{
							check = true;

							cout << endl << "Vehicle found:" << endl;
							this->parkingSpot[i]->setCsv(false);
							this->parkingSpot[i]->write(cout) << endl;
							break;
						}
						else
							check = false;
					}
				}

				if (check == false)
				{
					cout << endl << "License plate " << templno << " Not found" << endl << endl;
				}

				cout << "Press <ENTER> to continue....";
				cin.ignore(1000, '\n');
				break;
			}



		}

	}
	bool Parking::closeParking()
	{
		char selection;
		bool check = false;

		cout << "This will Remove and tow all remaining vehicles from the parking!" << endl
			<< "Are you sure? (Y)es/(N)o: ";
		do
		{
			cin >> selection;
			cin.ignore(1000, '\n');
			char up = toupper(selection);
			if (up != 'Y' && up != 'N')
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
			else
				break;

		} while (true);



		if (toupper(selection) == 'Y')
		{
			cout << "Closing Parking" << endl;
			for (int i = 0; i < this->noOfSpot; i++)
			{

				if (this->parkingSpot[i] != nullptr)
				{
					cout << endl << "Towing request" << endl <<
						"*********************" << endl;
					this->parkingSpot[i]->setCsv(false);
					this->parkingSpot[i]->write(std::cout);
					delete this->parkingSpot[i];
					this->parkingSpot[i] = nullptr;
					this->noParkedVehicles--;
				}
			}
			check = true;
		}
		else if (toupper(selection) == 'N')
		{
			check = false;
		}
		return check;
	}


	bool Parking::exitParking()const
	{
		char selection;
		cout << "This will terminate the program!" << endl
			<< "Are you sure? (Y)es/(N)o: ";

		do
		{
			cin >> selection;
			cin.ignore(1000, '\n');
			char up = toupper(selection);
			if (up != 'Y' && up != 'N')
			{
				cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
			}
			else

				break;

		} while (true);

		bool check = false;

		if (toupper(selection) == 'Y')
		{
			check = true;
		}
		else if (toupper(selection) == 'N')
		{
			check = false;
		}
		return check;
	}




	int Parking::run()
	{
		if (this->filePath != nullptr)
		{

			int select = -1;
			do
			{
				this->parkingStatus();
				parkingMenu.display();

				cin >> select;
				cin.ignore(1000, '\n');
				if (select == 1)
				{
					//vehicleMenu.display();
					this->parkVehicle();
					cout << "Press <ENTER> to continue....";
					cin.ignore(1000, '\n');

					//cout << endl;
				}
				else if (select == 2)
				{
					this->returnVehicle();

				}
				else if (select == 3)
				{
					this->listParkedVehicles();

				}
				else if (select == 4)
				{
					this->findVehicle();

				}
				else if (select == 5)
				{
					if (this->closeParking())
					{
						break;
					}
					else
					{
						select = -1;
					}
				}
				else if (select == 6)
				{
					if (this->exitParking())
					{
						cout << "Exiting program!" << endl;
						break;
					}
					else
					{
						select = -1;
					}
				}
			} while (true);

			return 0;
		}
		return 1;
	}


	void Parking::changeToUpper(char* value)
	{
		for (int i = 0; i < (int)strlen(value); i++)
		{
			value[i] = toupper(value[i]);
		}
	}

}