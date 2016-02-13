#include "Ticket.h"
#include <string>
#include <iostream>
using namespace std;

/**
* Ticket class corresponding to to a physical ticket for stage show.
**/
Ticket::Ticket(string show_name_, string venue_name_, When when_, Seat seat_)
{
	show_name = show_name_;
	venue_name = venue_name_;
	when = when_;
	seat = seat_;
	sold = false;
}

string Ticket::getShowName(){
	return show_name;
}

string Ticket::getVenueName() {
	return venue_name;
}

When Ticket::getWhen() {
	return when;
}

Seat Ticket::getSeat() {
	return seat;
}

bool Ticket::getSold() {
	return sold;
}

/**
* Program parameters indicate user input and testing will be perfect, no need to check for ticket being sold already.
**/
void Ticket::Sell() {
	sold = true;
}

/**
* Similarly to Ticket::Sell(), no need to user-proof.
**/
void Ticket::Reclaim(){
	sold = false;
}

void Ticket::Display() {
	cout << "Show_Name = " << show_name << endl <<
		"Venue_Name = " << venue_name << endl <<
		"Date = " << when.month << "/" << when.day << "/" << when.year << endl <<
		"Time = " << ((when.hour < 10) ? "0" : "") << when.hour << ":" << ((when.minute < 10) ? "0" : "") << when.minute << endl << //Prefix 0 conditional built into string construction
		"Seat " << seat.row_name << "" << seat.seat_number << endl <<
		(sold ? "Sold" : "Not sold");
	cout << endl;
}

Ticket::~Ticket(void)
{
}
