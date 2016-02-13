#pragma once
#include "Address.h"
#include "Seat.h"
#include <vector>

namespace VenueNS {
	class Venue
	{
	private:
		std::string name;
		Address* address;
		std::vector<Seat> seats;
	public:
		Venue();
		Venue(std::string name_, Address* address_);
		Venue(std::string name_, Address* address_, int number_of_rows_, int seats_per_row_);
		std::string getName();
		Address* getAddress();
		std::vector<Seat>* getSeats();
		~Venue();
	};
}