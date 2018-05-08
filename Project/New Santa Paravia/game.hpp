#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <limits>

#include "player.hpp"

class Game {
	public:
		Game() {
			
		}
		
		void start();		
		void introduceGame();
		void setDifficulty();
		void initializePlayers();
		void printInstructions();
		void playGame();
		bool allDead();
		void turn(Player& player);
		
	private:
		const std::vector<std::string> cityNames = {"Santa Paravia", "Fiumaccio", "Torricella", "Molinetto", "Fontanile", "Romanga", "Peppone"};
		int difficultyLevel;
		Player Baron = Player("Baron", Male, cityNames[6]);
		std::vector<Player> players;
		bool isOver = false;
		
};

#endif