// Lewis Davidson 20703319

#include <iostream>
#include <iomanip>
#include <ranges>
#include <string>
using namespace std;


const double MINIMUM_BALANCE = 3.00;

int CalcRequiredCredits(double balance)
{
	return 0;
}

void ShowMenu(double& balance)
{
	cout << "MAIN MENU\n";
	cout << " 1. Add Credits (current balance: " << fixed << setprecision(2) << balance << ")\n";
	cout << " 2. Order Burger\n";
	cout << " 0. Exit\n";
	cout << "Please enter a number: ";
}

double AddCredits(double& balance)
{
	system("cls");
	return balance;
}

int SelectBurgerSize(double& balance)
{
	system("cls");
	string burgerSize;
	cout << "ORDER BURGER - Select Size\t [Current balance = " << balance << " credits]\n\n";
	cout << "Please choose from the following options:\n\n";
	cout << " 1. Small [3.00 credits]\n";
	cout << " 2. Medium [5.50 credits]\n";
	cout << " 3. Large [7.25 credits]\n";
	cout << " 0. Return to Main Menu\n";
	cout << "........................................\n";
	cout << "Please select a burger size: ";
	int choice;
	while (!(cin >> choice) || choice < 1 || choice > 4)
	{

	}
	switch (choice)
	{
	case 0:
		ShowMenu(balance);
		break;
	case 1:
		cout << "You selected a small burger.";
		break;
	case 2:
		cout << "You selected a medium burger.";
		break;
	case 3:
		cout << "You selected a large burger.";
		break;
	default:
		cout << "Invalid selection. Please enter a number listed from the menu" << '\n';
	}
}

void SelectToppings(double& balance)
{

}

int main()
{

	double balance = 0.00;
	int menuChoice;

	cout << "-------------------------------\n"
		"        UCLan BURGERS\n"
		"-------------------------------\n";
	ShowMenu(balance);

	while (!(cin >> menuChoice) || menuChoice < 0 || menuChoice > 3)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Sorry, please select a valid option from the menu\n";
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
			cout << "Insufficient credits available." << " " << "You have " << fixed << setprecision(2) << balance << "credits" << "\n";
			system("pause");
			ShowMenu(balance);
		}
		break;
	default:
		break;
	}

	// Ask user for the balance

	// Select size of the burger

	// Select multiple toppings



	// Add extra credits

	// extra : Recent Orders

}