/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Motorcycle.h"
#include <cstring>
#include <cctype>

using std::cout;
using std::endl;
namespace sdds
{
	Motorcycle::Motorcycle()
	{
		this->sidecar = false;
	}

	Motorcycle::Motorcycle(const char* platenum, const char* mod) : Vehicle(platenum, mod)
	{
		if (platenum != nullptr && platenum[0] != '\0' && mod != nullptr)
		{
			this->sidecar = false;
		}
	}


	Motorcycle::Motorcycle(const Motorcycle& right) : Vehicle(right)
	{
		this->sidecar = false;
	}

	Motorcycle& Motorcycle::operator=(const Motorcycle& right)
	{
		if (this != &right)
		{
			(Vehicle&)*this = right;
			this->sidecar = right.sidecar;
		}
		return *this;

	}




	std::ostream& Motorcycle::writeType(std::ostream& os) const
	{
		if (this->isCsv())
		{
			os << "M,";
		}
		else
		{
			os << "Vehicle type: Motorcycle" << endl;
		}
		return os;
	}

	std::istream& Motorcycle::read(std::istream& in)
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
				this->sidecar = true;
			}
			else if (num == 0)
			{
				this->sidecar = false;
			}
		}
		else
		{
			cout << "\nMotorcycle information entry" << endl;
			Vehicle::read(in);
			cout << "Does the Motorcycle have a side car? (Y)es/(N)o: ";

			while (true)
			{
				in >> temp;
				in.ignore(1000, '\n');
				changeToUpper(temp);

				if (strlen(temp) == 1)
				{

					if (temp[0] == 'Y')
					{
						this->sidecar = true;
						break;
					}
					else if (temp[0] == 'N')

					{
						this->sidecar = false;
						break;
					}
					else
						cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";
				}
				else
					cout << "Invalid response, only (Y)es or (N)o are acceptable, retry: ";


			}

		}

		return in;
	}


	std::ostream& Motorcycle::write(std::ostream& os)const
	{
		if (!this->isEmpty())
		{
			os << "Invalid Motorcycle Object" << endl;
		}
		else
		{
			Vehicle::write(os);
			if (this->isCsv())
			{
				os << this->sidecar << endl;
			}
			else
			{
				if (this->sidecar == true)
				{
					os << "With Sidecar" << endl;
				}

			}
		}
		return os;

	}

}











