#include "Performance.h"



Performance::Performance()
{
}

Performance::Performance(std::string show_name_, Venue venue_, Date date_, Time time_) : show_name(show_name_), venue(venue_), date(date_), time(time_) {}

std::string Performance::getShowName()
{
	return show_name;
}

Venue * Performance::getVenue()
{
	return &venue;
}

Date Performance::getDate()
{
	return date;
}

Time Performance::getTime()
{
	return time;
}


Performance::~Performance()
{
}
