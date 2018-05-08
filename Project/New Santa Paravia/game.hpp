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
		
		void start() {
			introduceGame();
			setDifficulty();
			initializePlayers();
			playGame();
		}
		
		void introduceGame() {
			std::string wantsInstructions;
			std::cout << "Santa Paravia and Fiumaccio\n\n";
			std::cout << "Would you like instructions? (Y/N) ";			
			std::cin >> wantsInstructions;
			switch(wantsInstructions[0]) {
				case('Y'):
				case('y'):
					printInstructions();
					break;
			}
			return;
		}
		
		void setDifficulty() {
			std::cout << "\nWhat will be the difficulty of this game?\n";
			std::cout << "1. Apprentice\n";
			std::cout << "2. Journeyman\n";
			std::cout << "3. Master\n";
			std::cout << "4. Grand Master\n";
			std::cout << "Choice: ";
			while(!(std::cin >> difficultyLevel) || (difficultyLevel < 1) || (difficultyLevel > 4)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					std::cout << "That's not a number between 1 and 4, so try again.\n";
					std::cout << "Choice: ";
			}
			return;
		}
		
		void initializePlayers() {
			int numberOfPlayers = 0;
			std::string gender;
			std::string playerName;
			
			std::cout << "\nHow many people are playing? (1 to 6) ";
			while(!(std::cin >> numberOfPlayers) || (numberOfPlayers < 1) || (numberOfPlayers > 6)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				std::cout << "That's not a number between 1 and 6, so try again.\n";
				std::cout << "How many people are playing? (1 to 6) ";
			}
			
			for(int i = 0; i <numberOfPlayers; i++) {
				std::cout << "\nWho is the ruler of " << cityNames[i] << "? ";
				std::cin >> playerName;
				std::cout << "And what is their gender? (M/F) ";
				while(!(std::cin >> gender) || ((gender[0] != 'm')  && (gender[0] != 'M') && (gender[0] != 'F') && (gender[0] != 'f'))) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					std::cout << "That's not a valid response, so try again.\n";
					std::cout << "What is their gender? (M/F) ";
				}
				switch(gender[0]) {
					case('M'):
					case('m'):
						players.push_back(Player(playerName, Male, cityNames[i]));
						break;
					case('F'):
					case('f'):
						players.push_back(Player(playerName, Female, cityNames[i]));
						break;
				}
			}
			
			return;
		}
		
		void printInstructions() {
			std::cout << "\nYou are the ruler of a 15th century Italian city state.\n";
			std::cout << "If you rule well, you will receive higher titles. The\n";
			std::cout << "first player to become king or queen wins. Life expectancy\n";
			std::cout << "then was brief, so you may not live long enough to win.\n";
			std::cout << "The computer will draw a map of your state. The size\n";
			std::cout << "of the area in the wall grows as you buy more land. The\n";
			std::cout << "size of the guard tower in the upper left corner shows\n";
			std::cout << "the adequacy of your defenses. If it shrinks, equip more\n";
			std::cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
			std::cout << "all your land is in production. Otherwise you need more\n";
			std::cout << "serfs, who will migrate to your state if you distribute\n";
			std::cout << "more grain than the minimum demand. If you distribute less\n";
			std::cout << "grain, some of your people will starve, and you will have\n";
			std::cout << "a high death rate. High taxes raise money, but slow down\n";
			std::cout << "economic growth. (Press ENTER to begin game)\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			return;
		}
		
		void playGame() {
			while(!isOver) {
				for(int i = 0; i < players.size(); i++) {
					if(players[i].isDead() == false) {
						turn(players[i]);
						if(players[i].hasWon()) {
							isOver = true;
						}
					}
				}
				if(allDead()) {
					isOver = true;
				}
			}
			return;
		}
		
		bool allDead() {
			for(int i = 0; i < players.size(); i++) {
				if(players[i].isDead() == false) {
					return false;
				}
			}
			return true;
		}
		
		void turn(Player& player) {
			player.takeTurn();
			//player.checkInvasion();
			//player.adjustTax();
			//player.statePurchases();
			player.checkTitle(difficultyLevel);
			player.advanceYear();
			
			return;
			/*
			GenerateHarvest(Me);
			NewLandAndGrainPrices(Me);
			BuySellGrain(Me);
			ReleaseGrain(Me);
			if(Me->InvadeMe == True)
			{
				for(i = 0; i < HowMany; i++)
					if(i != Me->WhichPlayer)
						if(MyPlayers[i].Soldiers > (Me->Soldiers * 2.4))
						{
							AttackNeighbor(&MyPlayers[i], Me);
							i = 9;
						}
				if(i != 9)
					AttackNeighbor(Baron, Me);
			}
			AdjustTax(Me);
			DrawMap(Me);
			StatePurchases(Me, HowMany, MyPlayers);
			CheckNewTitle(Me);
			
			Me->Year++;
			if(Me->Year == Me->YearOfDeath)
				ImDead(Me);
			if(Me->TitleNum >= 7)
				Me->IWon = True;
			*/
		}
		
	private:
		const std::vector<std::string> cityNames = {"Santa Paravia", "Fiumaccio", "Torricella", "Molinetto", "Fontanile", "Romanga", "Peppone"};
		int difficultyLevel;
		Player Baron = Player("Baron", Male, cityNames[6]);
		std::vector<Player> players;
		bool isOver = false;
		
};

#endif