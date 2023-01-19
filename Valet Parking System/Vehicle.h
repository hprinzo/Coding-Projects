/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#ifndef VEHICLE_H_
#define VEHICLE_H_
#include <iostream>
#include "ReadWritable.h"
namespace sdds
{
	class Vehicle : public ReadWritable
	{
		char plno[8]{};
		char* model;
		int pkgSpot;


	protected:
		
		void setEmpty();
		bool isEmpty()const;
		const char* getLicensePlate()const;
		const char* getMakeModel()const;
		void setMakeModel(const char* value);

	public:
		Vehicle();
		Vehicle(const char* platenum, const char* mod);

		Vehicle(const Vehicle& right);
		Vehicle& operator=(const Vehicle& right);
		~Vehicle();

		void setParkingSpot(int value);
		const int getParkingSpot()const;

		bool operator==(const char* value);
		bool operator==(const Vehicle& right);

		std::istream& read(std::istream& in);
		virtual std::ostream& writeType(std::ostream& os) const = 0; // return os;
		std::ostream& write(std::ostream& os)const;
		void changeToUpper(char* value);

	};
}
#endif