#include "Cat.h"
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void stringToLower(string & inString) {
	transform(inString.begin(), inString.end(), inString.begin(), ::tolower);
}


Cat::Cat()
{
	this->setName("Default");
	this->setDoB({ 1,1,2000 });
	this->setWeight(1.0);
}

Cat::Cat(string name_, Date dob_, double weight_)
{
	this->setName(name_);
	this->setDoB(dob_);
	this->setWeight(weight_);
}

//Returns true if alphabetically comes after parameter
bool Cat::operator>(const Cat & other) const
{
	string thisName = this->getName();
	string otherName = other.getName();

	stringToLower(thisName);
	stringToLower(otherName);

	return  (thisName.compare(otherName)) > 0;
}

//Returns true if alphabetically comes before parameter
bool Cat::operator<(const Cat & other) const
{
	string thisName = this->getName();
	string otherName = other.getName();

	stringToLower(thisName);
	stringToLower(otherName);

	return  (thisName.compare(otherName)) < 0;
}

ostream& operator<<(ostream& os, const Cat& c) {
	os << "Cat " << c.getName() << " DoB: " << c.getDoB() << " Weight: " << c.getWeight();
	return os;
}

Cat::~Cat()
{
}

