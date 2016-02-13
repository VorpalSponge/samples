#include "Address.h"

Address::Address()
{
}

Address::Address(std::string street_address_, std::string city_, std::string state_, std::string zip_) : street_address(street_address_), city(city_), state(state_), zip(zip_) {}

std::string Address::getStreetAddress()
{
	return street_address;
}

std::string Address::getCity()
{
	return city;
}

std::string Address::getState()
{
	return state;
}

std::string Address::getZip()
{
	return zip;
}


Address::~Address()
{
}
