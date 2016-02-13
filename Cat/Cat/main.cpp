/**
 * Project 2
 * COP3331
 * Spring 2016
 * 
 * Reads cat names, dates of birth, and weight from text file, then sorts and prints them.
 *
 * @author Christopher Luna
 *
**/#include "Cat.h"
#include "Cat.cpp"
#include <fstream>
#include <vector>

const string filename = "cats.txt";

using namespace std;

void swapCats(Cat& c1, Cat& c2)
{
	Cat temp = c1;
	c1 = c2;
	c2 = temp;
}

// Returns -1 if error, otherwise success.
int getCats(vector<Cat>* cats_array) {
	ifstream infile;
	string name;
	int day, month, year;
	double weight;
	infile.open("cats.txt");

	if (!infile.is_open()) {
		cout << "Failed to open file\n";
		return -1; //Error
	}

	int count = 0;
	while (infile.good())
	{
		/*Assuming constant input format of
		STRING
		INT INT INT
		DOUBLE
		*/

		infile >> name;
		infile >> day;
		infile >> month;
		infile >> year;
		infile >> weight;

		if (!infile.good()) {
			break;
		}

		Cat c(name, { day,month,year }, weight);

		cats_array->push_back(c);
	}

	if (infile.eof()) {
		cout << endl << "End of file." << endl;
	}
	else
	{
		cout << endl << "Error reading file." << endl;
		count = -1;
	}

	infile.close();
	return count;
}

void sortCats(vector<Cat>* cats_array) {
	bool swap_done = false;
	do
	{
		swap_done = false;
		for (int i = 0; i < cats_array->size()-1; ++i) {
			Cat& c1 = cats_array->at(i);
			Cat& c2 = cats_array->at(i+1);
			if (c1 > c2)
			{
				swapCats(c1,c2);
				swap_done = true;
			}
		}
	} while (swap_done);
}



int main() {
	cout << "This is program Sort_Cats" << endl;
	//Project requirements do not indicate maxmimum number of possible cats.
	vector<Cat> cats;
	vector<Cat> *pcats = &cats;
	cats.reserve(25);

	//Get the cats and print them
	getCats(pcats);

	cout << cats.size() << " cats read" << endl;
	for (int i = 0; i < cats.size(); i++) {
		cout << cats[i] << endl;
	}

	//Now sort the cats and print them
	sortCats(pcats);
	cout << endl; //spacing

	cout << "Sorted Cats:" << endl;
	for (int i = 0; i < cats.size(); i++) {
		cout << cats[i] << endl;
	}
	cout << endl; //spacing
	cout << "Normal termination";
	cin.get();
}