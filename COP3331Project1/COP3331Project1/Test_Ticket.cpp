#include "Ticket.h"
#include "Ticket.cpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

Ticket* createTicket() {
	string show_name;
	string venue_name;
	When when;
	int day;
	int month;
	int year;
	int hour;
	int minute;

	Seat seat;
	string row_name;
	int seat_number;

	cout << "Please enter parameters for ticket";
	cout << endl;

	//Get show name
	cout << "Show Name: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin,show_name);

	//Get venue name
	cout << "Venue Name: ";
	if (cin.peek() == '\n') cin.ignore();
	getline(cin,venue_name);

	//Program parameters indicate no input checking is required
	//Gather parameters to create a When - order dictated by program requirements
	cout << "Date and Time of Show:";
	cout << endl;
		//Get Day
		cout << "\tDay: ";
		cin >> day;
		//Get Month
		cout << "\tMonth: ";
		cin >> month;
		//Get Year
		cout << "\tYear: ";
		cin >> year;
		//Get Hour
		cout << "\tHour (24 hour format; 0 to 23): ";
		cin >> hour;
		//Get minute
		cout << "\tMinute (0 to 59): ";
		cin >> minute;

	// Create the When of the show the ticket is for
	when = {day, month, year, hour, minute};

	//Gather seat details
	cout << "Seat Details:";
	cout << endl;
		//Get Row Name
		cout <<	"\tRow Name: ";
		if (cin.peek() == '\n') cin.ignore();
		getline(cin,row_name);
		//Get Seat Number
		cout << "\tSeat Number: ";
		cin >> seat_number;

	//Create Seat for ticket.
	seat = { row_name, seat_number };

	return new Ticket(show_name, venue_name, when, seat);
}

int main() {
	Ticket* ticket;

	//User inputs details for new ticket.
	ticket = createTicket();

	//Display ticket using method.
	cout << "Initial Ticket:";
	cout << endl;
	ticket->Display();

	//Display ticket using accessor methods.
	cout << "Using accessor functions:";
	cout << endl;

	//To prevent calling them everytime for constituent attributes
	When when = ticket->getWhen();
	Seat seat = ticket->getSeat();

	cout << "Show_Name = " << ticket->getShowName() << endl;
	cout << "Venue_Name = " << ticket->getVenueName() << endl;
	cout << "Date = " << when.month << "/" << when.day << "/" << when.year << endl;
	cout << "Time = ";
	cout << setw(3) << setfill('0'); //Times are portayed as 01:05 when the hour or minute are less than 10
	cout << when.hour << ":";
	cout << when.minute << "\n";
	cout << "Seat " << seat.row_name << seat.seat_number << endl;
	cout << (ticket->getSold() ? "Sold" : "Not sold");
	cout << endl;

	cout << "Calling Sell for ticket";
	cout << endl;
	ticket->Sell();

	cout << "After ticket sold:";
	cout << endl;
	ticket->Display();

	delete ticket;
	ticket = 0;

	return 0;
}