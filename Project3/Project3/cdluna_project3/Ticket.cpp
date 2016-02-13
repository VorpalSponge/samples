#include "Ticket.h"
#include "Seat.h"
#include <iostream>

/**
* Ticket class corresponding to to a physical ticket for stage show.
**/
Ticket::Ticket(Performance* performance_, Seat seat_)
{
	performance=performance_;
	seat = seat_;
	sold = false;
}

Performance * Ticket::getPerformance()
{
	return performance;
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
void Ticket::Reclaim() {
	sold = false;
}

void Ticket::Display() {
	Performance* p = this->getPerformance();
	std::cout << "------------------------------" << std::endl;
	std::cout << "Performance: " << p->getShowName() << std::endl;
	Date d = p->getDate();
	std::cout << d.month << '/' << d.day << '/' << d.year << " at ";
	Time t = p->getTime();
	std::cout << ((t.hour < 10) ? "0" : "") << t.hour << ":" << ((t.minute < 10) ? "0" : "") << t.minute << std::endl;
	VenueNS::Venue* v = p->getVenue();
	Address* a = v->getAddress();
	std::cout << v->getName() << std::endl;
	std::cout << a->getStreetAddress() << std::endl;
	std::cout << a->getCity() << ", " << a->getState() << " " << a->getZip() << std::endl;
	Seat s = this->getSeat();
	std::cout << "Row " << s.row_name << " Seat " << s.seat_number << std::endl;

}

Ticket::~Ticket(void)
{
}
