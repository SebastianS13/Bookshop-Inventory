#include <iostream>
#include <vector>
#include <string>
#include "Book.h"

std::vector<Book> Books;

int main()
{
	bool Running = true;

	while (Running)
	{
		system("cls");
		std::string MenuChoice;

		std::cout << "Bookshop Inventory \n------------------ \n\n" << std::endl;
		std::cout << "1 | See available books \n2 | Add new book \n3 | Remove a book \n4 | Exit\n";
		std::cin >> MenuChoice;

		if (MenuChoice == "1")
		{
			system("cls");
			for (Book ReadBook : Books)
			{
				std::cout << ReadBook.Title << " by " << ReadBook.Author << "\n";
			}

			system("pause");
		}
		else if (MenuChoice == "2")
		{
			system("cls");
			
			std::string BookTitle;
			std::string Author;
			int Pages;

			std::cout << "Book title: ";
			std::cin.ignore();
			std::getline(std::cin, BookTitle);

			std::cout << "Author: ";
			std::cin.ignore();
			std::getline(std::cin, Author);

			std::cout << "Pages: ";
			std::cin >> Pages;

			Book NewBook;
			NewBook.Title = BookTitle;
			NewBook.Author = Author;
			NewBook.Pages = Pages;

			Books.push_back(NewBook);
		}
		else if (MenuChoice == "3")
		{
			system("cls");

			std::string BookTitle;
			std::string Author;

			std::cout << "Book title: ";
			std::cin.ignore();
			std::getline(std::cin, BookTitle);

			std::cout << "Author: ";
			std::cin.ignore();
			std::getline(std::cin, Author);

			std::vector<Book>::iterator it = Books.begin();
			while (it != Books.end())
			{
				if (it->Title == BookTitle && it->Author == Author)
				{
					it = Books.erase(it);
				}
				else
				{
					++it;
				}
			}
		}
		else if (MenuChoice == "4")
		{
			Running = false;
		}
	}
	return 0;
}