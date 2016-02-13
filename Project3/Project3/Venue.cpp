#include "Venue.h"
using namespace VenueNS;

const char ALPHABET[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

Venue::Venue()
{
}

Venue::Venue(std::string name_, Address* address_) : name(name_), address(address_) {}

Venue::Venue(std::string name_, Address * address_, int number_of_rows_, int seats_per_row_)
{
	name = name_;
	address = address_;
	std::vector<Seat>* seats_ = new std::vector<Seat>();
	seats_->reserve(number_of_rows_ * seats_per_row_);
	char currentRow;
	Seat currentSeat;
	for (int i = 0; i < number_of_rows_; i++) {
		currentRow = ALPHABET[i];
		for (int j = 0; j < seats_per_row_; j++) {
			currentSeat = { std::string(1,currentRow), (j + 1) };
			seats_->push_back(currentSeat);
		}
	}
	this->seats = *seats_;
}

std::string Venue::getName()
{
	return name;
}

Address* Venue::getAddress()
{
	return address;
}

std::vector<Seat>* Venue::getSeats()
{
	return &seats;
}


Venue::~Venue()
{
}
