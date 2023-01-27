// Lewis Davidson 20703319

#include "pch.h" // Precompiled header
using namespace std;

const double MINIMUM_BALANCE = 3.00; // Balance required to start an order

const int NUM_TOPPINGS = 6;

struct Topping {
	string name;
	double price;
};

// Array of the struct for toppings
const Topping toppings[NUM_TOPPINGS] = {
	{"Cheese", 0.8},
	{"Salad", 0.5},
	{"Bacon", 1.0},
	{"Ketchup", 0.3},
	{"Mayonnaise", 0.3},
	{"Extra patty", 1.5}
};


// Function Declarations
int ShowMenu(double& balance); // Show the main menu for adding credits, ordering or exiting program
void AddCredits(double& balance); // Input menu for adding credits to their balance.
void ShowBurgerSizes(double& balance); // Menu for outputting the burger size options
void SelectBurgerSize(double& balance); // Input menu for the user to select the burger size
void ShowToppings(); // Menu for outputting the available toppings 

// Input menu for user to select toppings
void SelectToppings(string& burgerSize, double& balance, double& price); 

// Checkout for price deduction from balance and allowing reorders
int Checkout(string& burgerSize, double& balance, double& price, vector<string> selectedToppings); 

// Save each order on their own line to a file "orders.txt"
void SaveOrder(const string& burgerSize, const vector<string> selectedToppings, const int& price); 


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

int ShowMenu(double& balance)
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
		return 0;
		break;
	}
}

void AddCredits(double& balance)
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

void ShowBurgerSizes(double& balance)
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

void SelectBurgerSize(double& balance)
{
	system("cls");
	ShowBurgerSizes(balance);
	string burgerSize;
	double price{};
	int choice;
	while (!(cin >> choice) || choice < 0 || choice > 3) // https://stackoverflow.com/a/62018676
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
		price += 3.0;
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(burgerSize, balance, price);
		break;
	case 2:
		burgerSize = "Medium";
		price += 5.5;
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(burgerSize, balance, price);
		break;
	case 3:
		burgerSize = "Large";
		price += 7.25;
		cout << "You selected a " << burgerSize << " burger." << '\n';
		SelectToppings(burgerSize, balance, price);
		break;
	default:
		cout << "Invalid selection. Please enter a number listed from the menu" << '\n';
		SelectBurgerSize(balance);
		break;
	}
}

void ShowToppings()
{
	cout << "Select your toppings:" << '\n';
	cout << "Topping" << '\t' << "Price" << '\n';
	for (int i = 0; i < NUM_TOPPINGS; i++) // Standard for loop for indexing on menu
	{
		cout << i + 1 << ". " << toppings[i].name << '\t' << toppings[i].price << '\n';
	}
	cout << "7. Checkout" << '\n';
	cout << "Please enter a number: ";
}

void SelectToppings(string& burgerSize, double& balance, double& price)
{
	vector<string> selectedToppings;
	ShowToppings();
	int choice;
	do {
		while (!(cin >> choice) && choice < NUM_TOPPINGS && choice > NUM_TOPPINGS + 1)
		{
			ClearInputBuffer();
			cout << "Sorry, please select an option from the menu\n";
		}
		switch (choice)
		{
		case 1: case 2: case 3: case 4: case 5: case 6:
			selectedToppings.push_back(toppings[choice - 1].name); // Select topping from array using user input - 1 and add to the end of the vector 
			cout << "You've added " << toppings[choice - 1].name << " to your order.\n";
			price += toppings[choice - 1].price;
			cout << "Current total price is: " << price << '\n';
			break;
		case 7:
			Checkout(burgerSize, balance, price, selectedToppings);
			break;
		default:
			cout << "Invalid selection. Please enter a number listed from the menu" << '\n';
			SelectBurgerSize(balance);
			break;
		}
	} while (choice != 7);
}

int Checkout(string& burgerSize, double& balance, double& price, vector<string> selectedToppings)
{
	cout << "-------------------------------\n";
	cout << "Available credits:" << balance << '\n';
	cout << "Burger price:" << price << '\n';
	cout << "-------------------------------\n";

	balance -= price; // deduct price from balance if enough credits
	cout << "New balance: " << balance << '\n';
	SaveOrder(burgerSize, selectedToppings, price);
	cout << "...............................\n";
	cout << "Would you like to purchase another burger?" << '\n';
	char response{};
	while (!(cin >> response) || (tolower(response) != 'y' && tolower(response) != 'n'))
	{
		ClearInputBuffer();
		cout << "Sorry, that input is invalid" << '\n';
	}
	if (tolower(response == 'y'))
	{
		ShowMenu(balance);
	}
	else if (tolower(response == 'n'))
	{
		cout << "Thanks for ordering from UCLan Burgers :)" << '\n';
		return 0;
	}
}

void SaveOrder(const string& burgerSize, const vector<string> selectedToppings, const int& price)
{
	ofstream file("orders.txt", ios::app);
	file << burgerSize << ",";
	for (auto& topping : selectedToppings) // C++ documentation on for range loop
	{
		file << topping << ",";
	}
	file << price << "\n"; // Outputs new line so each order saved is on separate line
	file.close();
}