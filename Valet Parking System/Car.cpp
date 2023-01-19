/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Car.h"
#include <cstring>
#include <cctype>

using std::cout;
using std::endl;
namespace sdds
{
	Car::Car()
	{
		this->carWash = false;
	}

	Car::Car(const char* platenum, const char* mod) : Vehicle(platenum, mod)
	{
		if (platenum != nullptr && platenum[0] != '\0' && mod != nullptr)
		{
			this->carWash = false;
		}
	}

	Car::Car(const Car& right) : Vehicle(right)
	{
		this->carWash = false;
	}

	Car& Car::operator=(const Car& right)
	{
		if (this != &right)
		{
			(Vehicle&)*this = right;
			this->carWash = right.carWash;
		}
		return *this;

	}

	std::ostream& Car::writeType(std::ostream& os) const
	{
		if (this->isCsv())
		{
			os << "C,";
		}
		else
		{
			os << "Vehicle type: Car" << endl;
		}
		return os;
	}

	std::istream& Car::read(std::istream& in)
	{
		int num = 0;
		char temp[4];

		if (this->isCsv())
		{
			Vehicle::read(in);
			in >> num;
			in.ignore(1000, '\n');

			if (num == 1)
			{
				this->carWash = true;
			}
			else if (num == 0)
			{
				this->carWash = false;
			}
		}
		else
		{
			cout << "\nCar information entry" << endl;
			Vehicle::read(in);
			cout << "Carwash while parked? (Y)es/(N)o: ";

			while (true)
			{
				in >> temp;
				in.ignore(1000, '\n');
				changeToUpper(temp);

				if (strlen(temp) == 1)
				{

					if (temp[0] == 'Y')
					{
						this->carWash = true;
						break;
					}
					else if (temp[0] == 'N')

					{
						this->carWash = false;
						break;
					}
				}
				else
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";


			}

		}

		return in;
	}


	std::ostream& Car::write(std::ostream& os)const
	{

		if (!this->isEmpty())
		{
			os << "Invalid Car Object" << endl;
		}
		else
		{
			Vehicle::write(os);
			if (this->isCsv())
			{
				os << this->carWash << endl;
			}
			else
			{
				if (this->carWash == true)
				{
					os << "With Carwash" << endl;
				}
				else
					os << "Without Carwash" << endl;
			}

		}
		return os;
	}


}