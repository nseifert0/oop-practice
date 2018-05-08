#include "player.hpp"

void Player::changeTitle(int i) {
	if(gender == Male) {
		title = maleTitles[i];
	}
	else {
		title = femaleTitles[i];
	}
	return;
}

void Player::takeTurn() {
	city.generateHarvest();
	city.setNewLandAndGrainPrices();
	buyAndSell();
	city.releaseGrain();
	return;
}

int Player::maximumOfTen(int num, int den) {
	return(num/den > 10 ? 10 : num/den);
}

void Player::checkTitle(int difficultyLevel) {
	//Tally up success
	int success = 0;
	std::string oldTitle = title;
	success += maximumOfTen(city.getMarketplaces(), 1);
	success += maximumOfTen(city.getPalaces(), 1);
	success += maximumOfTen(city.getCathedrals(), 1);
	success += maximumOfTen(city.getMills(), 1);
	success += maximumOfTen(city.getTreasury(), 5000);
	success += maximumOfTen(city.getLand(), 6000);
	success += maximumOfTen(city.getMerchants(), 50);
	success += maximumOfTen(city.getNobles(), 5);
	success += maximumOfTen(city.getSoldiers(), 50);
	success += maximumOfTen(city.getClergy(), 10);
	success += maximumOfTen(city.getSerfs(), 2000);
	success += maximumOfTen(city.getPublicWorks() * 100, 500);
	changeTitle((success / difficultyLevel) - city.getJustice());
	if(oldTitle != title) {
		std::cout << "Good news! " << name <<" has achieved the rank of " << title << "\n\n";
	}
	if(title == maleTitles[7] || title == femaleTitles[7]) {
		won = true;
	}
	return;
}

void Player::advanceYear() {
	city.nextYear();
	if(city.getYear() == yearOfDeath) {
		dead = true;
		printDeath();
	}
}

void Player::printDeath() {
	int why = city.randomInt(8);			
	std::cout << "\n\nVery sad news. "<< title << " " << name << " has just died\n";			
	if(city.getYear() > 1450) {
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


void Player::buyAndSell() {
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

void Player::printYearlyUpdate() {
	std::cout << "\nYear " << city.getYear() << "\n";
	std::cout << "\n" << title << " " << name << "\n\n";
	std::cout << "Rats ate " << city.getRats() << "% of your grain reserves.\n";
	printHarvestStatus();
	std::cout << "(" << city.getRatsAte() << " steres)\n\n";
}

void Player::printGrainAndLand() {
	std::cout << "\nGrain\tGrain\tPrice of\tPrice of\tTreasury\n";
	std::cout << "Reserve\tDemand\tGrain\t\tLand\n";
	std::cout << city.getGrainReserve() << "\t" <<  city.getGrainDemand() << "\t" << city.getGrainPrice() << "\t\t" << city.getLandPrice() << "\t\t" << city.getTreasury() << "\n";
	std::cout << "steres\tsteres\t1000 st.\thectare\t\tgold florins\n";
	std::cout << "\n You have " << city.getLand() << " hectares of land.\n";
	std::cout << "\n1. Buy grain, 2. Sell grain, 3. Buy land,";
	std:: cout << " 4. Sell land\n(Enter q to continue): ";
}
	

void Player::printHarvestStatus() {
	switch(city.getHarvest()) {
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

bool Player::isDead() {
	return dead;
}

bool Player::isBankrupt() {
	return bankrupt;
}

bool Player::hasWon() {
	return won;
}