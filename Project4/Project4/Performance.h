#pragma once
#include <string>
#include "Venue.h"

struct Date_Time
{
    int Day;
    int Month;
    int Year;

    int Hour;
    int Minute;
};


class Performance
{
private:
    const string show_name;
    const Venue* venue;
    const Date_Time when;

public:
    Performance(const string&     Show_Name,
        const Venue*      Venue_,
        const Date_Time&  When);

    const Venue* Get_Venue() const { return venue; };

    void Display() const;
};
