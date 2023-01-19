/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Motorcycle : public Vehicle
	{
		bool sidecar;
	public:
		Motorcycle();
		Motorcycle(const char* platenum, const char* mod);

		Motorcycle(const Motorcycle& right);
		Motorcycle& operator=(const Motorcycle& right);

		std::ostream& writeType(std::ostream& os) const;
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os)const;


	};
}

#endif
