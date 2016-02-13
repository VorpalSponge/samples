#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

struct Date {
	int day;
	int month;
	int year;

	friend ostream& operator<<(ostream& os, const Date& d) {
		os << d.month << "/" << d.day << "/" << d.year;
		return os;
	};
};

void stringToLower(string & inString);

class Cat
{
private:
	string name;
	Date dob;
	double weight;

public:
	Cat();
	Cat(string name_, Date dob_, double weight);
	
	string getName() const { return this->name; };
	Date getDoB() const { return this->dob; };
	double getWeight() const { return this->weight; };

	void setName(string name_) { name = name_; };
	void setDoB(Date dob_) { dob = dob_; };
	void setWeight(double weight_) { weight = weight_; };

	bool operator>(const Cat& other) const;
	bool operator<(const Cat& other) const;
	friend ostream& operator<<(ostream& os, const Cat& c);

	~Cat();
};

