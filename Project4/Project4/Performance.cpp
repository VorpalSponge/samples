#include <iostream>
#include "Performance.h"

using namespace std;

Performance::Performance(const string&     Show_Name,
    const Venue*      Venue_,
    const Date_Time&  When) :

    show_name(Show_Name), venue(Venue_), when(When)
{}


void Performance::Display() const
{
    cout.fill('0');
    cout << "Performance: " << show_name << endl;
    cout << when.Day << "/" << when.Month << "/" << when.Year;
    cout << " at ";
    cout.width(2);
    cout << when.Hour << ":";
    cout.width(2);
    cout << when.Minute << endl;
    venue->Display();
}

