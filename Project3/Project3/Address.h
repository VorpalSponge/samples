#pragma once
#include <string>

class Address
{
private:
	std::string street_address;
	std::string city;
	std::string state;
	std::string zip;
public:
	Address();
	Address(std::string street_address_, std::string city_, std::string state_, std::string zip_);
	std::string getStreetAddress();
	std::string getCity();
	std::string getState();
	std::string getZip();
	~Address();
};

