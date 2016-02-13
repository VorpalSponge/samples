/**
 * Project 3
 *
 *
 * @author cdluna
 *
 *
 **/
#include <iostream>
#include "Venue.h"
#include "Performance.h"
#include "Ticket_Book.h"

/* Toggle for Circe compiling. */
#include "Address.cpp"
#include "Performance.cpp"
#include "Seat_Row.cpp"
#include "Ticket.cpp"
#include "Ticket_Book.cpp"
#include "Venue.cpp"

using namespace VenueNS;

std::string VENUE_NAME = "The Little Theater";
std::string STREET_ADDRESS = "19 Foster Street";
std::string CITY = "Littleton";
std::string STATE = "MA";
std::string ZIP = "01460";
int NUMBER_OF_ROWS = 3;
int SEATS_PER_ROW = 4;
std::string PERFORMANCE_NAME = "Billy Elliot";
int DAY = 2;
int MONTH = 4;
int YEAR = 2016;
int HOUR = 20;
int MINUTE = 0;

Venue* Create_Venue() {
	Address* address = new Address(STREET_ADDRESS, CITY, STATE, ZIP);
	Venue* venue = new Venue(VENUE_NAME, address, NUMBER_OF_ROWS, SEATS_PER_ROW);
	return venue;
}
Performance* Create_Performance(Venue* venue) {
	Date date{ DAY,MONTH,YEAR };
	Time time{ HOUR,MINUTE };
	Performance* performance = new Performance(PERFORMANCE_NAME, *venue, date, time);
	return performance;
}

int main()
{
	std::cout << "This is program Ticket_Printer\n\n\n";
	Venue* venue = Create_Venue();
	Performance* performance = Create_Performance(venue);
	Ticket_Book* ticket_book = new Ticket_Book(performance);
	ticket_book->Display();
	std::cin.get();
	return 0;
}


