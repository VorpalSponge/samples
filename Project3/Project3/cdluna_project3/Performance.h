#pragma once
#include "Seat.h"
#include "Venue.h"
#include <string>
using namespace VenueNS;

class Performance
{
private:
	std::string show_name;
	Venue venue;
	Date date;
	Time time;

public:
	Performance();
	Performance(std::string show_name_, Venue venue_, Date date_, Time time_);
	std::string getShowName();
	Venue* getVenue();
	Date getDate();
	Time getTime();
	~Performance();
};

