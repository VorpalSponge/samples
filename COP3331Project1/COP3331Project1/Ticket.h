#pragma once
#include <string>
using namespace std;

struct When {
	int day;
	int month;
	int year;
	int hour;
	int minute;
};

struct Seat {
	string row_name;
	int seat_number;
};

class Ticket
{
private:
	string show_name;
	string venue_name;
	When when;
	Seat seat;
	bool sold;
public:
	Ticket(string show_name_, string venue_name_, When when_, Seat seat_);
	string getShowName();
	string getVenueName();
	When getWhen();
	Seat getSeat();
	bool getSold();
	void Sell();
	void Reclaim();
	void Display();
	string toString();
	~Ticket();
};

