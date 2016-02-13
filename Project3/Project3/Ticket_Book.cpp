#include "Ticket_Book.h"



Ticket_Book::Ticket_Book()
{
}

Ticket_Book::Ticket_Book(Performance * performance_){
	performance = performance_;
	tickets = new std::vector<Ticket>();
	std::vector<Seat>* seats = performance->getVenue()->getSeats();
	tickets->reserve(seats->size());
	std::vector<Seat>::iterator it;
	Seat currentSeat;
	Ticket* currentTicket;
	for (it = seats->begin(); it != seats->end(); ++it) {
		currentSeat = *it;
		currentTicket = new Ticket(performance,currentSeat);
		tickets->push_back(*currentTicket);
	}
}

Performance * Ticket_Book::getPerformance()
{
	return performance;
}

std::vector<Ticket>* Ticket_Book::getTickets()
{
	return tickets;
}

void Ticket_Book::Display()
{
	std::vector<Ticket>::iterator it;
	std::vector<Ticket>* t = this->getTickets();
	for (it = t->begin(); it != t->end(); ++it) {
		it->Display();
	}
}


Ticket_Book::~Ticket_Book()
{
}
