#ifndef CITY_HPP
#define CITY_HPP

#include <string>

#include "randomNumbers.hpp"

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
		
		void generateHarvest() {
			harvest = (randomInt(5) + randomInt(6)) / 2;
			rats = randomInt(50);
			grainReserve = ((grainReserve * 100) - (grainReserve * rats)) / 100;
			return;
		}
		
		void setNewLandAndGrainPrices() {
			double x;
			double y;
			int h;
			x = (float)land;
			y = (((float)serfs - (float)mills) * 100.0) * 5.0;
			if(y < 0.0) {
				y = 0.0;
			}
			if(y < x) {
				x = y;
			}
			y = (float)grainReserve * 2.0;
			if(y < x) {
				x = y;
			}
			y = (float)harvest + (randomDouble(1.0) - 0.5);
			h = (int)(x * y);
			grainReserve += h;
			grainDemand = (nobles * 100) + (cathedrals * 40) + (merchants * 30) + (soldiers * 10) + (serfs * 5);
			landPrice = (3.0 * (float)harvest + (float)randomInt(6) + 10.0) / 10.0;
			if(h < 0) {
				h *= -1;
			}
			if(h < 1) {
				y = 2.0;
			}
			else {
				y = (float)((float)grainDemand / (float)h);
				if(y > 2.0)
				y = 2.0;
			}
			if(y < 0.8) {
				y = 0.8;
			}
			landPrice *= y;
			if(landPrice < 1.0) {
				landPrice = 1.0;
			}
			grainPrice = (int)(((6.0 - (float)harvest) * 3.0 + (float)randomInt(5) + (float)randomInt(5)) * 4.0 * y);
			ratsAte = h; 
			return;
		}
		
		void buyGrain() {
			int howMuch;
			std::cout << "How much grain do you want to buy (0 to specify a total)? ";
			std::cin >> howMuch;
			if(howMuch == 0) {
				std::cout <<"What total amount of grain do you want to have? ";
				std::cin >> howMuch;
				howMuch -= grainReserve;
				if(howMuch < 0) {
					std::cout << "Invalid total amount.\n\n";
					return;
				}
			}
			treasury -= (howMuch * grainPrice / 1000);
			grainReserve += howMuch;
			return;
		}
		
		void sellGrain() {
			int howMuch;
			printf("How much grain do you want to sell? ");
			std::cin >> howMuch;
			if(howMuch > grainReserve) {
				std::cout << "You don't have it.\n";
				return;
			}   
			treasury += (howMuch * grainPrice / 1000);
			grainReserve -= howMuch;
			return;
		}

		void buyLand() {
			int howMuch;
			std::cout << "How much land do you want to buy? ";
			std::cin >> howMuch;
			land += howMuch;
			treasury -= (int)(((float)howMuch * landPrice));
			return;
		}
		
		void sellLand() {
			int howMuch;
			std::cout << "How much land do you want to sell? ";
			std::cin >> howMuch;
			if(howMuch > (land - 5000)) {
				std::cout << "You can't sell that much\n";
				return; 
			}
			land -= howMuch;
			treasury += (int)(((float)howMuch * landPrice));
			return;
		}
		
	private:
		std::string cityName;
		
};

#endif