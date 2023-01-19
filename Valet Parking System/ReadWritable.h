/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/


#ifndef READWRITEABLE_H_
#define READWRITEABLE_H_
#include <iostream>

namespace sdds
{
	class ReadWritable
	{
		bool separatedFlag;

	public:
		ReadWritable();
		virtual ~ReadWritable() = 0;

		bool isCsv()const;
		void setCsv(bool value);

		virtual	std::ostream& write(std::ostream& os)const = 0;
		virtual std::istream& read(std::istream& in) = 0;

		/*HELPERS*/
		friend std::ostream& operator <<(std::ostream& os, const ReadWritable& temp);
		friend std::istream& operator >>(std::istream& in, ReadWritable& temp);
	};

}
#endif