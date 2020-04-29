// This program will keep track of a theater ticket sales.

// PLACE YOUR NAME HERE
#include<iostream>
#include<iomanip>
using namespace std;

// Constants for rows and columns
const int ROWS = 15;
const int COLS = 30;

// Function prototypes
void displayMenu();
int  getChoice();
void displaySeats(const char [][COLS]);
void displayPrices(const double[]);
void displaySales(double);
void purchaseTicket(char [][COLS], const double[], double&);

int main()
{
	char theater[ROWS][COLS];
	double ticketPrice[ROWS] = { 0.0 };
	double totalSales = 0.0;
	int row;
	int seat;
	int choice;

	// Initialize theater with #'s -- all seats available
	for(row = 0; row < ROWS; row++)
		for (seat = 0; seat < COLS; seat++)
			theater[row][seat] = '#';

	// Get seat prices for each of the ROWS rows
	// Rewrite the code below to read the prices from a file.
	for (row = 0; row < ROWS; row++)
	{
		cout << "Please enter ticket price for Row " << setw(2) << row+1
		     << ": ";
		cin  >> ticketPrice[row];
	}

	// Set print formats
	cout << fixed << showpoint << setprecision(2);

	do
	{
		displayMenu();
		choice = getChoice();

		switch(choice)
		{
			case 1: displaySeats(theater);
			break;

			case 2: displayPrices(ticketPrice);
			break;

			case 3: displaySales(totalSales);
			break;

			case 4: purchaseTicket(theater, ticketPrice, totalSales);
			break;

			default: // Do nothing
			break;
		}

	} while (choice != 5);

	return 0;
}

// ********************************************************
// Function displayMenu                                   *
// Displays the menu of program options                   *
// ********************************************************
void displayMenu()
{
   // Display menu of choices
   cout << "\n\n\n\t\tC++ Theatre" << endl << endl;
   cout << "\n\t1.  View Available Seats";
   cout << "\n\t2.  View Seating Prices";
   cout << "\n\t3.  View Ticket Sales";
   cout << "\n\t4.  Purchase a Ticket";
   cout << "\n\t5.  Exit the Program\n\n";
   cout << "\n\tEnter your choice(1-5):  ";
}

// ********************************************************
// Function getChoice                                     *
// This function inputs, validates, and returns the       *
// user's choice                                          *
// ********************************************************
int getChoice()
{
	int choice;
	// Get and validate user's choice
    cout << "Pick your choice: ";
    cin >> choice;
	//Return the choice
    return choice;
}

// ********************************************************
// Function displaySeats                                  *
// Displays a chart showing sold and available seats      *
// ********************************************************
void displaySeats(const char theater[][COLS]) //done
{
	cout << "\n\t\tSeats";
	cout << "\n        123456789012345678901234567890" << endl;

	for(int row = 0; row < ROWS; row++)
	{
		cout << "\nRow " << setw(2) << row+1 << "\t";

		for (int seat = 0; seat < COLS; seat++)
		{
			cout << theater[row][seat];
		}
	}

	cout << "\n\n\n\tLegend:\t*  =  Sold";
	cout << "\n\t\t#  =  Available";
	cout << "\n\n\nPress the Enter key to continue.";
	cin.ignore();
	cin.get();

}

// ********************************************************
// Function displayPrices                                 *
// Displays ticket prices for each row                    *
// ********************************************************
void displayPrices(const double price[]) //done
{
   cout << "\nTicket Prices By Row  " << endl << endl;
   cout << "      Row    Price" << endl;
   cout << "      ---    -----" << endl;

   for (int row = 0; row < ROWS; row++)
   {
      cout << setw(8) << row+1 << setw(10) << price[row] << endl;
   }

   cout << "\n\n\nPress the Enter key to continue.";
   cin.ignore();
   cin.get();
}

// ********************************************************
// Function purchaseTicket                                *
// Handles ticket purchases                               *
// ********************************************************
void purchaseTicket(char theater[][COLS], const double price[],
                    double &totSales) //done
{
	int row;
	int seat;
	char type_ad_ch;//adult_or_child
	int count_ad = 0;
	int count_ch = 0;
	int numTickets = 0;
	double totPrice = 0.0;
	char response;
    do {
	//display ticket purchase header i.e. Your Name Ticket Purchase
        cout << "Choose your row(1-15): "; cin >> row;
        cout << "Choose your seat(1-30): "; cin >> seat;
        cout << "What type of this ticket for? (child: press 'c'/adult: press any character): "; cin >> type_ad_ch;
	//prompt user for option to review available seating before making purchase y/n
        //if y displaySeats
	//add code to prompt user for rows and seats

		if (theater[row-1][seat-1] == '#')  // if the seat is available
		{
			theater[row-1][seat-1] = '*';    // mark the seat is taken
			numTickets++;                    // add to patron's ticket total
			if (type_ad_ch=='c') {
                totPrice += price[row-1]*0.5;
                count_ch++;
			}
            else {
                totPrice += price[row-1];
                count_ad++;
            }
			// add to patron's $ total
			cout << "\nPurchase confirmed\n";
		}
		else  // seat has been sold
		{
			cout << "\nSorry.  That seat has been sold.\n";
		}

		cout << "\nWould you like to purchase another seat (y/n)? ";
		cin >> response;

	} while ((toupper(response) == 'Y')||(toupper(response) == 'y'));

	// Display a purchase summary for the patron
    cout << "Numbers of Adult ticket: " << count_ad << "\n";
    cout << "Numbers of Child ticket: " << count_ch << "\n";

	// Add patron's purchases to theater total purchases
	cout << "Total purchases: " << totPrice < "\n";
}

// ********************************************************
// Function displaySales                                  *
// Displays total sales information                       *
// ********************************************************
void displaySales(double totalSales)
{
    // Display menu of sales
   cout << "\n\n\n\t\tC++ Sales list" << endl << endl;
   cout << "\n\t1.  Thursday Night-8pm 20$";
   cout << "\n\t2.  Friday Night-8pm 40$";
   cout << "\n\t3.  Saturday Night–8pm 40$";
   cout << "\n\t4.  Saturday Matinee-3pm 20$";
   cout << "\n\t5.  Sunday Matinee-3pm 20$";
   //...
   cout << "\n\n\nPress the Enter key to continue.";
   cin.ignore();
   cin.get();
}
