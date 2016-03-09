#include <iostream>
#include "Address.h"
#include "Seat.h"
#include "Seat_Row.h"
#include "Venue.h"
#include "Performance.h"
#include "Ticket.h"
#include "Ticket_Book.h"
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

//Uncomment for circe compile.
//#include "Address.cpp"
//#include "Seat.cpp"
//#include "Seat_Row.cpp"
//#include "Venue.cpp"
//#include "Performance.cpp"
//#include "Ticket.cpp"
//#include "Ticket_Book.cpp"

using namespace std;

void swapVenues(Venue& v1, Venue& v2)
{
	Venue temp = v1;
	v1 = v2;
	v2 = temp;
}

// Create an Address object
Address* Create_Address(const string address_, const string city_, const string state_, const int zip_)
{
	Address* address = new Address(address_,
		city_,
		state_,
		zip_);
	return address;
}

string getNextGoodLine(ifstream& infile) {
	string line = "";
	while (line == "")
	{
		if (!infile.good())
			break;
		getline(infile, line);		
	}
	return line;
}
int getVenues(vector<Venue>* venues_array, const string& filename) {
	ifstream infile;
	string current_line = "";
	string name, address, city, state;
	int zip;
	infile.open(filename.c_str());

	if (!infile.is_open()) {
		cout << "Failed to open file\n";
		return -1; //Error
	}

	int count = 0;
	while (infile.good())
	{
		/*Assuming constant input format of
		STRING (Venue name)
		STRING (address)
		STRING (city)
		STRING (state)
		INT (zip)
		*/

		current_line = getNextGoodLine(infile);

		if (current_line == "") // end of file reached
			break;

		name = current_line;
		current_line = getNextGoodLine(infile);
		address = current_line;
		current_line = getNextGoodLine(infile);
		city = current_line;
		current_line = getNextGoodLine(infile);
		state = current_line;
		current_line = getNextGoodLine(infile);
		zip = atoi(current_line.c_str());

		Address* a = Create_Address(address, city, state, zip);
		Venue v(name,*a);

		venues_array->push_back(v);
		++count;
		if (infile.eof()) {
			break;
		}
	}
	if (!infile.eof())
	{
		cout << endl << "Error reading file." << endl;
		count = -1;
	}

	infile.close();
	return count;
}

void sortVenues(vector<Venue>* venues_array) {
	bool swap_done = false;
	do
	{
		swap_done = false;
		for (size_t i = 0; i < venues_array->size()-1; ++i) {
			Venue& v1 = venues_array->at(i);
			Venue& v2 = venues_array->at(i + 1);
			if (v1 > v2)
			{
				swapVenues(v1, v2);
				swap_done = true;
			}
		}
	} while (swap_done);
}

//// Create a Seat_Row with the specified name and 
//// specified number of seats,
//Seat_Row* Create_Seat_Row(const string seat_row_name,
//                          int number_of_seats)
//{
//    Seat_Row* row = new Seat_Row(seat_row_name);
//    for (int i = 1; i <= number_of_seats; ++i)
//    {
//        Seat* new_seat = new Seat(seat_row_name, i);
//        row->Add_Seat(new_seat);
//    }
//    return row;
//}


// Create a Venue object corresponding to The Little Theater.
//Venue* Create_Venue()
//{
//    Address* adr = Create_Address();
//    Venue* venue = new Venue("The Little Theater", *adr);
//
//    Seat_Row* sr = Create_Seat_Row("A", 4);
//    venue->Add_Seat_Row(sr);
//
//    sr = Create_Seat_Row("B", 4);
//    venue->Add_Seat_Row(sr);
//
//    sr = Create_Seat_Row("C", 4);
//    venue->Add_Seat_Row(sr);
//
//    return venue;
//}


//Performance* Create_Performance(Venue* venue)
//{
//    Date_Time when = { 4, 2, 2016, 20, 0 };
//    Performance* p = new Performance("Billy Elliot", venue, when);
//    return p;
//}


int main()
{
	string filename;
	vector<Venue> venues;
	venues.reserve(100);

    cout << "This is Venue_Sort\n\n";

	cout << "Name for input file? ";
	cin >> filename;

	cout << getVenues(&venues, filename) << " venues read from file" << endl << endl;

	cout << "Venues before sort:" << endl;

	for (size_t i = 0; i < venues.size(); i++) {
		cout << venues[i] << endl;
	}

	cout << endl;

	cout << "Venues after sort:" << endl;

	sortVenues(&venues);

	for (size_t i = 0; i < venues.size(); i++) {
		cout << venues[i] << endl;
	}

	cout << endl << "Program complete." << endl;
    cin.get();   // Hold the window open
    return 0;
}


