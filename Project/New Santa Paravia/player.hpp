#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>

#include "city.hpp"
#include "randomNumbers.hpp"


const std::vector<std::string> maleTitles = {"Sir", "Baron", "Count", "Marquis", "Duke", "Grand Duke", "Prince", "King"};
const std::vector<std::string> femaleTitles = {"Lady", "Baroness", "Countess", "Marquise", "Duchess", "Grand Duchess", "Princess", "Queen"};

enum Gender {
	Male,
	Female
};

class Player {
	public:
		Player(std::string n, Gender g, std::string cityName) :name(n), gender(g), city(cityName) {
			if(gender == Male) {
				title = maleTitles[0];
			}
			else {
				title = femaleTitles[0];
			}
			yearOfDeath = city.year + 20 + randomInt(35);
		}
	
		void changeTitle(int i) {
			if(gender == Male) {
				title = maleTitles[i];
			}
			else {
				title = femaleTitles[i];
			}
			return;
		}
		
		void takeTurn() {
			city.generateHarvest();
			city.setNewLandAndGrainPrices();
			buyAndSell();
			city.releaseGrain();
			return;
		}
		
		int maximumOfTen(int num, int den) {
			return(num/den > 10 ? 10 : num/den);
		}
		
		void checkTitle(int difficultyLevel) {
			//Tally up success
			int success = 0;
			std::string oldTitle = title;
			success += maximumOfTen(city.marketplaces, 1);
			success += maximumOfTen(city.palaces, 1);
			success += maximumOfTen(city.cathedrals, 1);
			success += maximumOfTen(city.mills, 1);
			success += maximumOfTen(city.treasury, 5000);
			success += maximumOfTen(city.land, 6000);
			success += maximumOfTen(city.merchants, 50);
			success += maximumOfTen(city.nobles, 5);
			success += maximumOfTen(city.soldiers, 50);
			success += maximumOfTen(city.clergy, 10);
			success += maximumOfTen(city.serfs, 2000);
			success += maximumOfTen(city.publicWorks * 100, 500);
			changeTitle((success / difficultyLevel) - city.justice);
			if(oldTitle != title) {
				std::cout << "Good news! " << name <<" has achieved the rank of " << title << "\n\n";
			}
			if(title == maleTitles[7] || title == femaleTitles[7]) {
				won = true;
			}
			return;
		}
		
		void advanceYear() {
			city.year += 1;
			if(city.year == yearOfDeath) {
				dead = true;
				printDeath();
			}
		}
		
		void printDeath() {
			int why = randomInt(8);			
			std::cout << "\n\nVery sad news. "<< title << " " << name << " has just died\n";			
			if(city.year > 1450) {
				std::cout << "of old age after a long reign.\n";
			}
			else
			{
				switch(why)
				{
					case 0:
					case 1:
					case 2:
					case 3: 
						std::cout << "of pneumonia after a cold winter in a drafty castle.\n";
						break;
					case 4: 
						std::cout << "of typhoid after drinking contaminated water.\n";
						break;
					case 5: 
						std::cout << "in a smallpox epidemic.\n";
						break;
					case 6: 
						std::cout << "after being attacked by robbers while travelling.\n";
						break;
					case 7:
					case 8: 
						std::cout << "of food poisoning.\n";
						break;
				}
			}
			std::cout << "\n(Press ENTER): ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			return;
		}
		
		
		void buyAndSell() {
			printYearlyUpdate();
			bool done = false;
			std::string input;
			while(done == false) {
				printGrainAndLand();
				std::cin >> input;
				switch(input[0]) {
					case 'q':
						done = true;
						break;
					case '1':
						city.buyGrain();
						break;
					case '2':
						city.sellGrain();
						break;
					case '3':
						city.buyLand();
						break;
					case '4':
						city.sellLand();
						break;
					default:
						break;					
				}
			}
			return;
		}
		
		void printYearlyUpdate() {
			std::cout << "\nYear " << city.year << "\n";
			std::cout << "\n" << title << " " << name << "\n\n";
			std::cout << "Rats ate " << city.rats << "% of your grain reserves.\n";
			printHarvestStatus();
			std::cout << "(" << city.ratsAte << " steres)\n\n";
		}
		
		void printGrainAndLand() {
			std::cout << "\nGrain\tGrain\tPrice of\tPrice of\tTreasury\n";
			std::cout << "Reserve\tDemand\tGrain\t\tLand\n";
			std::cout << city.grainReserve << "\t" <<  city.grainDemand << "\t" << city.grainPrice << "\t\t" << city.landPrice << "\t\t" << city.treasury << "\n";
			std::cout << "steres\tsteres\t1000 st.\thectare\t\tgold florins\n";
			std::cout << "\n You have " << city.land << " hectares of land.\n";
			std::cout << "\n1. Buy grain, 2. Sell grain, 3. Buy land,";
			std:: cout << " 4. Sell land\n(Enter q to continue): ";
		}
			
		
		void printHarvestStatus() {
			switch(city.harvest) {
				case 0: 
				case 1: 
					std::cout << "Drought. Famine Threatens. ";
					break;
				case 2: 
					std::cout << "Bad Weather. Poor Harvest. ";
					break;
				case 3:
					std::cout << "Normal Weather. Average Harvest. ";
					break;
				case 4:
					std::cout << "Good Weather. Fine Harvest. ";
					break;
				case 5:
					std::cout << "Excellent Weather. Great Harvest! ";
					break;
			}
			return;
		}
		
		bool isDead() {
			return dead;
		}
		
		bool isBankrupt() {
			return bankrupt;
		}
		
		bool hasWon() {
			return won;
		}
		
		
	private:
		std::string name;
		City city;
		std::string title;
		Gender gender;
		int yearOfDeath;
		bool invadeMe = false;
		bool bankrupt = false;
		bool dead = false;
		bool won = false;
};

#endif