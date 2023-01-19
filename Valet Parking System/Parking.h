/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/


#ifndef PARKING_H_
#define PARKING_H_
#include <iostream>
#include "Menu.h"
#include "Vehicle.h"
#include "Motorcycle.h"
#include "Car.h"

namespace sdds
{
	const int maxSpotNo = 100;
	class Parking
	{
		char* filePath{};
		Menu parkingMenu{};
		Menu vehicleMenu{};
		int noOfSpot{};
		Vehicle* parkingSpot[maxSpotNo]{};
		int noParkedVehicles{};


		bool isEmpty()const;
		void parkingStatus()const;
		void parkVehicle();
		void returnVehicle();
		void listParkedVehicles()const;
		void findVehicle()const;
		bool closeParking();
		bool exitParking()const;
		bool loadDataFile();
		void saveDataFile();
	public:
		void setEmpty();


		Parking();
		Parking(const char* c, int num);
		~Parking();
		Parking(const Parking&) = delete;
		Parking& operator=(const Parking&) = delete;
		void changeToUpper(char* value);

		int run();



	};
}





#endif