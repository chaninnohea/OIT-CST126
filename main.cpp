// Name: Chanin Timbal
// Class: CST 126
// Date: 04/08/2024
// Assignment: Homework 1

#include "header.h"

//Main to run the program 
int main()
{
	int option = 0;
	char again = 'Y';
	cout << "Welcome! Please choose an option: \n";
	display_options();
	cin >> option;
	cin.ignore(100, '\n');

	while (option != 0)
	{
		if (option == 1)
		{
			run_conversion(again);
		}

		else if (option == 2)
		{
			guessing_game(again);
		}

		else if (option == 3)
		{

		}
		else
		{
			cout << "That is not one of the options!";
			display_options();
			cin >> option;
			cin.ignore(100, '\n');
		}

		display_options();
		cin >> option;
		cin.ignore(100, '\n');
	}

	return 0;
}

//menu options
void display_options()
{
	cout << "1. Currency Converter\n";
	cout << "2. Guessing Game\n";
	cout << "3. Temperature Logger\n";
	cout << "0. Quit\n\n";
}
