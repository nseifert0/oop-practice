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
		int customsDutyRevenue;
		int deadSerfs;
		int fleeingSerfs;
		int grainDemand;
		int grainPrice = 25;
		int grainReserve = 5000;
		int harvest;
		int incomeTax = 5;
		int incomeTaxRevenue;
		int ratsAte;
		int justice = 2;
		int justiceRevenue;
		int land = 10000;
		int marketplaces = 0;
		int marketRevenue;
		int merchants = 25;
		int millRevenue;
		int mills = 0;
		int newSerfs;
		int nobles = 4;
		int palaces = 0;
		int rats;
		int salesTax = 10;
		int salesTaxRevenue;
		int serfs = 2000;
		int soldiersPay;
		int soldiers = 25;
		int transplantedSerfs;
		int treasury = 1000;
		int year = 1400;
		double landPrice = 10.0;
		double publicWorks = 1.0;
		
		void generateHarvest(int harvestSeed1, int harvestSeed2, int ratsSeed) {
			harvest = (harvestSeed1 + harvestSeed2) / 2;
			rats = ratsSeed;
			grainReserve = ((grainReserve * 100) - (grainReserve * rats)) / 100;
			return;
		}

	private:
		std::string cityName;
		
};

#endif