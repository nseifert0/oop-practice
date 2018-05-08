#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <random>
#include <iostream>

class City {
	public:
		City(std::string name) :cityName(name) {
			
		}		
		
		int getCathedrals();
		int getClergy();
		int getCustomsDuty();
		int getCustomsDutyRevenue();
		int getDeadSerfs();
		int getFleeingSerfs();
		int getGrainDemand();
		int getGrainPrice();
		int getGrainReserve();
		int getHarvest();
		int getIncomeTax();
		int getIncomeTaxRevenue();
		int getRatsAte();
		int getJustice();
		int getJusticeRevenue();
		int getLand();
		int getMarketplaces();
		int getMarketRevenue();
		int getMerchants();
		int getMillRevenue();
		int getMills();
		int getNewSerfs();
		int getNobles();
		int getPalaces();
		int getRats();
		int getSalesTax();
		int getSalesTaxRevenue();
		int getSerfs();
		int getSoldiersPay();
		int getSoldiers();
		int getTransplantedSerfs();
		int getTreasury();
		int getYear();
		double getLandPrice();
		double getPublicWorks();
		
		void nextYear();
		void generateHarvest();
		void setNewLandAndGrainPrices();
		void buyGrain();
		void sellGrain();
		void buyLand();
		void sellLand();
		int releaseGrain();
		int randomInt(int i);
		double randomDouble(double d);
		
	private:
		std::string cityName;
		
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
		
};

#endif