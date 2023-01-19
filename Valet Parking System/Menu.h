/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#ifndef MENU_H_
#define MENU_H_
#include <iostream>


#define MAX_NO_OF_ITEMS 10

namespace sdds
{
	//class Menu;

	class MenuItem
	{
		char word[50];
		MenuItem();
		MenuItem(const char* right);
		void setEmpty();
		std::ostream& display(std::ostream& os)const;

		MenuItem(const MenuItem&) = delete;
		MenuItem& operator=(const MenuItem&) = delete;

		friend class Menu;
	};

	class Menu
	{
		char title[51];
		MenuItem item[MAX_NO_OF_ITEMS];
		int track;
	public:

		int indent;
		Menu();
		Menu(const char* c, int ind = 0);
		Menu(const Menu&) = delete;
		Menu& operator=(const Menu&) = delete;

		operator bool()const;
		void setEmpty();
		bool isEmpty()const;
		void display()const;
		Menu& operator=(const char* c);
		void add(const char* c);
		void clear();
		Menu& operator<<(const char* c);

		int run()const;
		operator int()const;

		//void setIndent(int ind);
		void setTitle(const char* c);

	};


}


#endif

