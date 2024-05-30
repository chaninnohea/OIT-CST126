#include <iostream>
#include <cctype>
#include <cstring>
#include <random>
using std::cout;
using std::cin;
using std::endl;

//Protoypes
void display_options();
float convert(float input, float output, float amount);
void run_conversion(char again);
void currency_menu();
void guessing_game(char again);

//Loop to run the conversion while the user wants to
void run_conversion(char again)
{
	while (toupper(again) != 'N')
	{
		float input_choice = 0;
		float output_choice = 0;
		float conversion = 0.0;
		float amount = 0.0;

		cout << "Choose your input currency: ";
		currency_menu();
		cin >> input_choice;
		cin.ignore(100, '\n');
		cout << "\nchoose your output currency: ";
		cin >> output_choice;
		cin.ignore(100, '\n');
		cout << "\nWhat is the amount you would like to convert: ";
		cin >> amount;
		cin.ignore(100, '\n');
		conversion = convert(input_choice, output_choice, amount);
		cout << "In the new currency, that amount is " << conversion << std::endl;
		cout << "\nDo you want to use the conversion tool again? (Y/N): ";
		cin >> again;
		cin.ignore(100, '\n');
		if (toupper(again) != 'Y')
		{
			cout << "Thank you for using the currency conversion tool! \n\n";
		}
	}
}

//Conversion Calculator
float convert(float input, float output, float amount)
{
	float converted_amount = 0.0;
	struct currencies
	{
		const float GBP = 0.80;
		const float Euro = 0.94;
		const float Yen = 152.22;
		const float AUD = 1.55;
		const float USD = 1;
	};

	currencies currency;

	if (input == output)
	{
		return amount;
	}
	if (input == 1)
	{
		input = currency.GBP;
	}
	else if (input == 2)
	{
		input = currency.Euro;
	}
	else if (input == 3)
	{
		input = currency.Yen;
	}
	else if (input == 4)
	{
		input = currency.AUD;
	}
	else if (input == 5)
	{
		input = currency.USD;
	}

	if (output == 1)
	{
		output = currency.GBP;
	}
	else if (output == 2)
	{
		output = currency.Euro;
	}
	else if (output == 3)
	{
		output = currency.Yen;
	}
	else if (output == 4)
	{
		output = currency.AUD;
	}
	else if (output == 5)
	{
		output = currency.USD;
	}

	converted_amount = output / input * amount;
	return converted_amount;
}

//Menu display
void currency_menu()
{
	cout << "\n\n1. GBP\n";
	cout << "2. Euro\n";
	cout << "3. Yen\n";
	cout << "4. AUD\n";
	cout << "5. USD\n\n";
}

//guessing game function
void guessing_game(char again)
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 10000);

	int random_number = dist6(rng);
	int user_guess = 0;
	int guess_counter = 1;

	cout << "Welcome to the Guessing Game!" << endl;
	cout << "I have selected a number between 1 and 10000, you have 20 tries to guess it!" << endl;
	cout << "" << endl;

	cout << "hint: " << random_number << endl;
	cout << "Enter your guess: ";
	cin >> user_guess;
	cin.ignore(100, '\n');

	while (user_guess != random_number && guess_counter != 20)
	{
		if (user_guess > random_number)
		{
			cout << "Lower!";
			cout << "Tries left: " << (20 - guess_counter);
		}
		else
		{
			cout << "Higher!";
			cout << "Tries left: " << (20 - guess_counter);
		}
		guess_counter++;
		cout << "Enter your guess: ";
		cin >> user_guess;
		cin.ignore(100, '\n');
	}

	cout << "You got it!\n" << endl;
}
