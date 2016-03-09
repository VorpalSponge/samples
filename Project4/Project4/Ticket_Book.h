#pragma once
#include "Performance.h"
#include "Ticket.h"

class Ticket_Book
{
private:
    Ticket** tickets;   // A dynamically allocated array of
                        // pointers to Tickets
    int number_of_tickets;

public:
    Ticket_Book(Performance* p);

    void Print_Tickets() const;
};



