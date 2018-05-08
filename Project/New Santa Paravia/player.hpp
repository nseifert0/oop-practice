#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <vector>
#include <string>

#include "city.hpp"


const std::vector<std::string> maleTitles = {"Sir", "Baron", "Count", "Marquis", "Duke", "Grand Duke", "Prince", "King"};
const std::vector<std::string> femaleTitles = {"Lady", "Baroness", "Countess", "Marquise", "Duchess", "Grand Duchess", "Princess", "Queen"};

enum Gender {
	Male,
	Female
};

class Player {
	public:
		Player(std::string n, Gender g, std::string cityName, int randomSeed) :name(n), gender(g), city(cityName) {
			if(gender == Male) {
				title = maleTitles[0];
			}
			else {
				title = femaleTitles[0];
			}
			yearOfDeath = city.year + 20 + randomSeed;
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
		
		void takeTurn(int harvestSeed1, int harvestSeed2, int ratsSeed) {
			city.generateHarvest(harvestSeed1, harvestSeed2, ratsSeed);
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