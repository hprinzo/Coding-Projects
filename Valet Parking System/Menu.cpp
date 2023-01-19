/*
Name - Prince Abiy
Student ID - 133240218
Section: ZDD
*/

#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

namespace sdds
{
	MenuItem::MenuItem()
	{
		this->setEmpty();
	}

	MenuItem::MenuItem(const char* right)
	{
		if (right == nullptr)
		{
			this->setEmpty();
		}
		else
		{
			strcpy(this->word, right);
		}
	}

	void MenuItem::setEmpty()
	{
		strcpy(this->word, "");
	}

	std::ostream& MenuItem::display(std::ostream& os)const
	{
		if (this->word != nullptr)
			os << word << std::endl;

		return os;
	}

	/************************************************************************************************************************************/

	Menu::Menu()
	{
		this->setEmpty();

	}

	Menu::Menu(const char* right, int ind)
	{
		if (right == nullptr)
		{
			this->setEmpty();
		}
		else
		{
			strcpy(this->title, right);
		}
		this->indent = ind;
		this->track = 0;
	}

	void Menu::setEmpty()
	{
		this->title[0] = '\0';
		this->item[0].word[0] = '\0';
		this->indent = 0;
		this->track = 0;

	}

	Menu::operator bool()const
	{
		if (this->title[0] != '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Menu::isEmpty()const
	{
		if (this->title != nullptr)
		{
			return false;
		}
		else
		{
			return true;
		}

	}

	void Menu::display()const
	{
		if (this->title[0] == '\0')
		{
			cout << "Invalid Menu!" << endl;
		}

		else
		{
			for (int i = 0; i < this->indent; i++)
			{
				cout << "    ";
			}

			cout << this->title << endl;


			if (this->item[0].word[0] != '\0')
			{
				int i;
				for (i = 0; i < this->track; i++)
				{
					for (int i = 0; i < this->indent; i++)
					{
						cout << "    ";
					}


					cout << i + 1 << "- " << item[i].word << endl;
				}

				for (int i = 0; i < this->indent; i++)
				{
					cout << "    ";
				}

				cout << "> ";
			}
			else
			{
				cout << "No Items to display!" << endl;
			}

		}

	}


	Menu& Menu::operator=(const char* c)
	{
		if (c == nullptr)
		{
			this->item[0].word[0] = '\0';
			this->title[0] = '\0';

		}
		else
		{
			if (strlen(c) > 50)
			{
				strncpy(this->title, c, 50);
			}
			else
			{
				strcpy(this->title, c);
			}
		}

		return *this;
	}
	void Menu::add(const char* c)
	{
		if (c != nullptr)
		{
			if (this->track != 10 && (this->item != nullptr || this->title[0] != '\0'))
			{
				if (strlen(c) > 50)
				{
					strncpy(this->item[this->track].word, c, 50);
					this->track++;
				}
				else
				{
					strcpy(this->item[this->track].word, c);
					this->track++;
				}
			}
		}
		else
		{
			this->setEmpty();
		}
	}


	void Menu::clear()
	{

		this->indent = 0;

		for (int i = 0; i < 50; i++)
		{
			this->title[i] = '\0';
		}

		for (int i = 0; i < track; i++)
		{
			this->item->word[i] = '\0';
		}

	}

	Menu& Menu::operator<<(const char* c)
	{
		this->add(c);
		return *this;
	}

	int Menu::run()const
	{
		this->display();
		int select = 0;
		if (this->title[0] != '\0' && this->item[0].word[0] != '\0')
		{


			while ((cin.fail()) || (select < 1 || select > this->track))
			{
				cin >> select;

				if (cin.fail())
				{
					std::cout << "Invalid Integer, try again: ";
					cin.clear();
					cin.ignore(1000, '\n');

				}
				else if (select < 1 || select > track)
				{
					std::cout << "Invalid selection, try again: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else
				{
					cin.ignore(1000, '\n');
					return select;

				}

			}
		}

		return 0;
	}

	Menu::operator int()const
	{
		return this->run();
	}



	/*void Menu::setIndent(int ind)
	{
		 this->indent = ind;
	}*/
	void Menu::setTitle(const char* c)
	{
		strcpy(this->title, c);
	}

}