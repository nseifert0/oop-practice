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
		Player(std::string n, Gender g, std::string cityName) :name(n), gender(g), city(cityName) {
			if(gender == Male) {
				title = maleTitles[0];
			}
			else {
				title = femaleTitles[0];
			}
			yearOfDeath = city.getYear() + 20 + city.randomInt(35);
		}
	
		void changeTitle(int i);
		void takeTurn();
		int maximumOfTen(int num, int den);
		void checkTitle(int difficultyLevel);
		void advanceYear();
		void printDeath();
		void buyAndSell();
		void printYearlyUpdate();
		void printGrainAndLand();
		void printHarvestStatus();		
		bool isDead();
		bool isBankrupt();
		bool hasWon();
		
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