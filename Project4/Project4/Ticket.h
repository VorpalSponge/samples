#pragma once
#include "Performance.h"
#include "Seat.h"

class Ticket
{
private:
    const Performance* performance;
    const Seat* seat;
    bool sold;

public:
    Ticket(const Performance* perf, const Seat* s);
    void Display() const;
};
