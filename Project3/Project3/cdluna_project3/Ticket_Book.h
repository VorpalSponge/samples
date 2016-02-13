#pragma once
#include "Performance.h"
#include "Ticket.h"

class Ticket_Book
{
private:
	Performance* performance;
	std::vector<Ticket>* tickets;
public:
	Ticket_Book();
	Ticket_Book(Performance* performance_);
	Performance* getPerformance();
	std::vector<Ticket>* getTickets();
	void Display();
	~Ticket_Book();
};

