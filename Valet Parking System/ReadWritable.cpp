/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS
#include"ReadWritable.h"
#include <cstring>

namespace sdds
{
	ReadWritable::ReadWritable()
	{
		this->separatedFlag = false;
	}

	ReadWritable::~ReadWritable()
	{

	}
	bool ReadWritable::isCsv()const
	{
		return this->separatedFlag;
	}

	void ReadWritable::setCsv(bool value)
	{
		this->separatedFlag = value;
	}

	/*HELPERS*/
	std::ostream& operator <<(std::ostream& os, const ReadWritable& temp)
	{
		temp.write(os);

		return os;
	}

	std::istream& operator >>(std::istream& in, ReadWritable& temp)
	{
		temp.read(in);

		return in;
	}
}