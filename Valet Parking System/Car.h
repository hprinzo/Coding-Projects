/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#ifndef CAR_H_
#define CAR_H_
#include <iostream>
#include "Vehicle.h"

namespace sdds
{
	class Car : public Vehicle
	{
		bool carWash;


	public:
		Car();
		Car(const char* platenum, const char* mod);

		Car(const Car& right);
		Car& operator=(const Car& right);


		std::ostream& writeType(std::ostream& os) const;
		std::istream& read(std::istream& in);
		std::ostream& write(std::ostream& os)const;


	};
}

#endif
