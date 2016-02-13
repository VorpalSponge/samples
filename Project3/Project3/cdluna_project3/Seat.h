#pragma once
#include <string>

struct Date {
	int day;
	int month;
	int year;
};

struct Time {
	int hour;
	int minute;
};

struct Seat {
	std::string row_name;
	int seat_number;
};