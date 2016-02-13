#pragma once
#include "Performance.h"

class Ticket
{
private:
	Performance* performance;
	Seat seat;
	bool sold;
public:
	Ticket(Performance* performance_, Seat seat_);
	Performance* getPerformance();
	Seat getSeat();
	bool getSold();
	void Sell();
	void Reclaim();
	void Display();
	~Ticket();
};

