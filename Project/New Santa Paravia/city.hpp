#ifndef CITY_HPP
#define CITY_HPP
#include <string>

class City {
	public:
		City(std::string name) :cityName(name) {
			
		}
	

		int cathedrals = 0;
		int clergy = 5;
		int customsDuty = 25;
		int grainPrice = 25;
		int grainReserve = 5000;
		int incomeTax = 5;
		int justice = 2;
		int land = 10000;
		double landPrice = 10.0;
		int marketplaces = 0;
		int merchants = 25;
		int mills = 0;
		int nobles = 4;
		int palaces = 0;
		double publicWorks = 1.0;		
		int salesTax = 10;
		int serfs = 2000;
		int soldiers = 25;
		int treasury = 1000;
		
	private:
		std::string cityName;
};

#endif