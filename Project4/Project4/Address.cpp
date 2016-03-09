#include "Address.h"



#include <iostream>
#include "Address.h"

Address::Address(string Street_Address,
    string City,
    string State,
    int Zip_Code) :
    street_address(Street_Address),
    city(City),
    state(State),
    zip_code(Zip_Code)
{}


void Address::Display() const
{
    cout.fill('0');
    cout << street_address << endl;
    cout << city << ", " << state << " ";
    cout.width(5);
    cout << zip_code << endl;
}

bool Address::operator>(const Address& other) const
{
	return zip_code > other.zip_code;
}

bool Address::operator==(const Address& other) const
{
	return zip_code == other.zip_code;
}

Address& Address::operator=(const Address& other)
{
	return *(new Address(other.street_address, other.city, other.state, other.zip_code));
}





