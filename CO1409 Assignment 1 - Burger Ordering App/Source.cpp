// Lewis Davidson 20703319

// Ask user for the balance

// Select size of the burger

// Select multiple toppings

// Add extra credits

// extra : Recent Orders

#include "pch.h"
using namespace std;

const double MINIMUM_BALANCE = 3.00;

const int NUM_TOPPINGS = 6;

struct Topping {
	string name;
	double price;
};


// Function Declarations
int ShowMenu(double &balance);
void AddCredits(double &balance);
void ShowBurgerSizes(double &balance);
void SelectBurgerSize(double &balance);
void ShowToppings();
void SelectToppings(double &balance);
double CalcRequiredCredits(double &balance);


int main()
{
	double balance = 0.00;

	cout << "-------------------------------" << '\n';
	cout << "        UCLan BURGERS" << '\n';
	cout << "-------------------------------" << '\n';
	ShowMenu(balance);
}


// For clearing input buffer after failed inputs
void ClearInputBuffer()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int ShowMenu(double &balance)
{
	cout << "MAIN MENU" << '\n';
	cout << " 1. Add Credits [Current balance: " << fixed << setprecision(2) << balance << "]" << '\n';
	cout << " 2. Order Burger" << '\n';
	cout << " 0. Exit" << '\n';
	cout << "Please enter a number: ";
	int menuChoice;
	while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 3)
	{
		ClearInputBuffer();
		cout << "Sorry, please select a valid option from the menu" << '\n';
		ShowMenu(balance);
	}

	switch (menuChoice)
	{
	case 0:
		return 0;
		break;
	case 1:
		AddCredits(balance);
		break;
	case 2:
		if (balance < MINIMUM_BALANCE)
		{
			cout << "Insufficient credits available." << " " << "You have " << fixed << setprecision(2) << balance << " credits" << '\n';
			ShowMenu(balance);
			break;
		}
		SelectBurgerSize(balance);
		break;
	default:
		break;
	}
}

void AddCredits(double &balance)
{
	system("cls");
	double addCreditAmount;
	cout << "Please enter the amount of credits you'd like to add: " << '\n';
	while (!(cin >> addCreditAmount) && addCreditAmount < 0)
	{
		ClearInputBuffer();
		cout << "Sorry, that's an invalid amount. Try again." << '\n';
	}
	balance += addCreditAmount;
	cout << "Your new balance is " << fixed << setprecision(2) << balance << " credits" << '\n';
	ShowMenu(balance);
}

void ShowBurgerSizes(double &balance)
{
	cout << "ORDER BURGER - Select Size\t [Current balance: " << fixed << setprecision(2) << balance << " credits]" << '\n';
	cout << "Please choose from the following options:" << '\n';
	cout << " 1. Small [3.00 credits]" << '\n';
	cout << " 2. Medium [5.50 credits]" << '\n';
	cout << " 3. Large [7.25 credits]" << '\n';
	cout << " 0. Return to Main Menu" << '\n';
	cout << "........................................" << '\n';
	cout << "Please select a burger size: ";
}

void SelectBurgerSize(double &balance)
{
	system("cls");
	ShowBurgerSizes(balance);
	string burgerSize;
	int choice;
	while (!(cin >> choice) || choice < 1 || choice > 4)
	{
		ClearInputBuffer();
		cout << "Sorry, please select a valid option from the menu" << '\n';
	}
	switch (choice)
	{
	case 0:
		ShowMenu(balance);
		break;
	case 1:
		burgerSize = "Small";
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(balance);
		break;
	case 2:
		burgerSize = "Medium";
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(balance);
		break;
	case 3:
		burgerSize = "Large";
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(balance);
		break;
	default:
		cout << "Invalid selection. Please enter a number listed from the menu" << '\n';
		SelectBurgerSize(balance);
		break;
	}
}

void ShowToppings()
{
	Topping toppings[NUM_TOPPINGS] = {
		{"Cheese", 0.8},
		{"Salad", 0.5},
		{"Bacon", 1.0},
		{"Ketchup", 0.3},
		{"Mayo", 0.3},
		{"Extra patty", 1.5}
	};
	 
	cout << "Select your toppings:" << '\n';

	for (int i = 0; i < NUM_TOPPINGS; i++)
	{

		cout << i + 1 << ". " << toppings[i].name << '\t' << toppings[i].price << ".\n";
	}
}

void SelectToppings(double &balance)
{
	ShowToppings();
}

double CalcRequiredCredits(double &balance)
{
	return 0;
}