#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project3/Venue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace VenueNS;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: Your test code here
			std::string VENUE_NAME = "The Little Theater";
			std::string STREET_ADDRESS = "19 Foster Street";
			std::string CITY = "Littleton";
			std::string STATE = "MA";
			std::string ZIP = "01460";
			int NUMBER_OF_ROWS = 3;
			int SEATS_PER_ROW = 4;

			Address* address = new Address(STREET_ADDRESS, CITY, STATE, ZIP);
			Venue* venue = new Venue(VENUE_NAME, address, NUMBER_OF_ROWS, SEATS_PER_ROW);
			std::vector<Seat>* seats = venue->getSeats();

			Assert::AreEqual(12,(int)seats->size(),L"message");
		}

	};
}