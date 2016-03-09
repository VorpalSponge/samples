#include "Ticket.h"
#include "Performance.h"
#include "Seat.h"

Ticket::Ticket(const Performance* perf, const Seat* s) :
    performance(perf), seat(s), sold(false)
{}

void Ticket::Display() const
{
    performance->Display();
    seat->Display();
}
