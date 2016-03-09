#include <iostream>
#include "Ticket_Book.h"
#include "Ticket.h"
#include "Venue.h"
using namespace std;

Ticket_Book::Ticket_Book(Performance* p)
{
    const Venue* venue = p->Get_Venue();
    number_of_tickets = venue->Capacity();

    tickets = new Ticket*[number_of_tickets];

    int n = 0;  // index for array tickets 

    // Create a ticket for each seat in the venue.
    int nr_rows = venue->Number_of_Seat_Rows();

    for (int i = 0; i < nr_rows; ++i)
    {
        const Seat_Row* row = venue->Get_Seat_Row(i);
        int nr_seats_in_row = row->Number_of_Seats();
        for (int j = 0; j < nr_seats_in_row; ++j)
        {
            const Seat* seat = row->Get_Seat(j);
            tickets[n++] = new Ticket(p, seat);
        }
    }
}

void Ticket_Book::Print_Tickets() const
{
    for (int i = 0; i < number_of_tickets; ++i)
    {
        tickets[i]->Display();
        cout << "----------------------------\n";
    }
}
