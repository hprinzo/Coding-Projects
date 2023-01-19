/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include"ReadWritable.h"
#include "Vehicle.h"
#include <cstring>
#include <cctype>

using std::cout;
using std::endl;

namespace sdds
{
	Vehicle::Vehicle()
	{
		this->plno[0] = '\0';
		this->model = nullptr;
		this->pkgSpot = 0;
	}
	Vehicle::Vehicle(const char* platenum, const char* mod)
	{
		if (platenum != nullptr && platenum[0] != '\0' && mod != nullptr && strlen(mod) >= 2)
		{
			this->model = new char[strlen(mod) + 1];
			strcpy(this->model, mod);

			if (strlen(platenum) >= 1 && strlen(platenum) <= 8)
			{
				strcpy(this->plno, platenum);
			}
			this->pkgSpot = 0;
		}
		else
		{
			this->plno[0] = '\0';
			this->model = nullptr;
			this->pkgSpot = 0;
		}
	}

	Vehicle::Vehicle(const Vehicle& right)
	{
		if (right.model != nullptr)
		{
			strcpy(this->plno, right.plno);
			this->model = new char[strlen(right.model) + 1]{};
			strcpy(this->model, right.model);
			this->pkgSpot = right.pkgSpot;

		}
		else
		{
			this->plno[0] = '\0';
			this->model = nullptr;
			this->pkgSpot = 0;
		}
	}
	Vehicle& Vehicle::operator=(const Vehicle& right)
	{
		if (this != &right)
		{
			strcpy(this->plno, right.plno);
			this->pkgSpot = right.pkgSpot;
			this->setCsv(right.isCsv());
			delete[] this->model;

			if (right.model != nullptr)
			{
				this->model = new char[strlen(right.model) + 1]{};
				strcpy(this->model, right.model);
			}
		}
		return *this;
	}

	Vehicle::~Vehicle()
	{
		delete[] this->model;
	}

	void Vehicle::setEmpty()
	{
		this->plno[0] = '\0';
		this->model = nullptr;
		this->pkgSpot = 0;
	}

	bool Vehicle::isEmpty()const
	{
		if (this->plno[0] == '\0' || this->model == nullptr)
		{
			return false;
		}
		else return true;

	}

	const char* Vehicle::getLicensePlate()const
	{
		return this->plno;
	}

	const char* Vehicle::getMakeModel()const
	{
		return this->model;
	}

	void Vehicle::setMakeModel(const char* value)
	{

		if (value != nullptr)
		{
			delete[] this->model;
			this->model = new char[strlen(value + 1)];
			strcpy(this->model, value);
		}
		else
		{
			delete[] this->model;
			this->setEmpty();
		}




	}

	const int Vehicle::getParkingSpot()const
	{
		return this->pkgSpot;
	}

	void Vehicle::setParkingSpot(int value)
	{
		if (value > 0 && value != 0)
		{
			this->pkgSpot = value;
		}
		else
		{
			delete[] this->model;
			this->setEmpty();
		}

	}

	bool Vehicle::operator==(const char* value)
	{
		char temp[8]{};
		char valuetemp[8]{};
		strcpy(temp, this->plno);
		strcpy(valuetemp, value);

		changeToUpper(temp);
		changeToUpper(valuetemp);

		if (strcmp(temp, valuetemp) == 0)
		{
			return true;
		}
		return false;
	}

	bool Vehicle::operator==(const Vehicle& right)
	{
		char temp[8]{};
		char valuetemp[8]{};
		strcpy(temp, this->plno);
		strcpy(valuetemp, right.plno);

		changeToUpper(temp);
		changeToUpper(valuetemp);

		if (strcmp(temp, valuetemp) == 0)
		{
			return true;
		}
		return false;
	}

	std::istream& Vehicle::read(std::istream& in)
	{
		delete[] this->model;
		this->setEmpty();
		char templno[60]{};
		char modeltemp[60]{};
		if (in)
		{

			if (this->isCsv())
			{
				in >> this->pkgSpot;
				in.ignore(60, ',');
				in.getline(this->plno, 8, ',');
				changeToUpper(this->plno);
				in.getline(modeltemp, 60, ',');

				this->model = new char[strlen(modeltemp) + 1];
				strcpy(model, modeltemp);
			}
			else
			{
				cout << "Enter License Plate Number: ";
				while (true)
				{
					in.getline(templno, 60, '\n');
					if (strlen(templno) > 8)
					{
						cout << "Invalid License Plate, try again: ";
					}
					else
					{
						changeToUpper(templno);
						strcpy(this->plno, templno);
						break;
					}
				}
				char temp[60];
				cout << "Enter Make and Model: ";
				/**/
				while (true)
				{
					in.getline(temp, 60, '\n');
					if (strlen(temp) < 2 || strlen(temp) > 60)
					{
						cout << "Invalid Make and model, try again: ";
						//in.ignore(1000, '\n');
					}
					else
					{
						this->model = new char[strlen(temp) + 1]{};
						strcpy(this->model, temp);
						break;
					}

				}

			}

		}
		else
		{
			delete[] this->model;
			this->setEmpty();
		}


		return in;
	}

	std::ostream& Vehicle::write(std::ostream& os)const
	{
		if (!this->isEmpty())
		{
			os << "Invalid Vehicle Object" << endl;
		}
		else
		{
			this->writeType(os);
			if (isCsv())
			{
				os << this->pkgSpot << "," << this->plno << "," << this->model << ",";
			}
			else
			{
				os << "Parking Spot Number: ";
				if (this->pkgSpot == 0)
				{
					os << "N/A" << endl;
				}
				else
					os << this->pkgSpot << endl;

				os << "License Plate: ";
				os << this->plno << endl;

				os << "Make and Model: ";
				os << this->model << endl;
			}

		}
		return os;
	}


	void Vehicle::changeToUpper(char* value)
	{
		for (int i = 0; i < (int)strlen(value); i++)
		{
			value[i] = toupper(value[i]);
		}
	}




}