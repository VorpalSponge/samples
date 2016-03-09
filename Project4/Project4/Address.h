#pragma once
#include <string>

using namespace std;

class Address
{
private:
    string street_address;
    string city;
    string state;
    int zip_code;

public:
    Address(string Street_Address,
        string City,
        string State,
        int Zip_Code);

    void Display() const;
	bool operator>(const Address& other) const;
	bool operator==(const Address& other) const;
	Address & operator=(const Address & other);
};


