#include "city.hpp"

//--------------------------------------------------------------------------------------------------
//Getters
int City::getCathedrals() {
	return cathedrals;
}

int City::getClergy() {
	return clergy;
}

int City::getCustomsDuty() {
	return customsDuty;
}

int City::getCustomsDutyRevenue() {
	return customsDutyRevenue;
}

int City::getDeadSerfs() {
	return deadSerfs;
}

int City::getFleeingSerfs() {
	return fleeingSerfs;
}

int City::getGrainDemand() {
	return grainDemand;
}

int City::getGrainPrice() {
	return grainPrice;
}

int City::getGrainReserve() {
	return grainReserve;
}

int City::getHarvest() {
	return harvest;
}

int City::getIncomeTax() {
	return incomeTax;
}

int City::getIncomeTaxRevenue() {
	return incomeTaxRevenue;
}

int City::getRatsAte() {
	return ratsAte;
}

int City::getJustice() {
	return justice;
}

int City::getJusticeRevenue() {
	return justiceRevenue;
}

int City::getLand() {
	return land;
}

int City::getMarketplaces() {
	return marketplaces;
}

int City::getMarketRevenue() {
	return marketRevenue;
}

int City::getMerchants() {
	return merchants;
}

int City::getMillRevenue() {
	return millRevenue;
}

int City::getMills() {
	return mills;
}

int City::getNewSerfs() {
	return newSerfs;
}

int City::getNobles() {
	return nobles;
}

int City::getPalaces() {
	return palaces;
}

int City::getRats() {
	return rats;
}

int City::getSalesTax() {
	return salesTax;
}

int City::getSalesTaxRevenue() {
	return salesTaxRevenue;
}

int City::getSerfs() {
	return serfs;
}

int City::getSoldiersPay() {
	return soldiersPay;
}

int City::getSoldiers() {
	return soldiers;
}

int City::getTransplantedSerfs() {
	return transplantedSerfs;
}

int City::getTreasury() {
	return treasury;
}

int City::getYear() {
	return year;
}

double City::getLandPrice() {
	return landPrice;
}

double City::getPublicWorks() {
	return publicWorks;
}
//--------------------------------------------------------------------------------------------------

void City::nextYear() {
	year += 1;
}

void City::generateHarvest() {
	harvest = (randomInt(5) + randomInt(6)) / 2;
	rats = randomInt(50);
	grainReserve = ((grainReserve * 100) - (grainReserve * rats)) / 100;
	return;
}

void City::setNewLandAndGrainPrices() {
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

//--------------------------------------------------------------------------------------------------
//Buying and Selling
void City::buyGrain() {
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

void City::sellGrain() {
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

void City::buyLand() {
	int howMuch;
	std::cout << "How much land do you want to buy? ";
	std::cin >> howMuch;
	land += howMuch;
	treasury -= (int)(((float)howMuch * landPrice));
	return;
}

void City::sellLand() {
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

//--------------------------------------------------------------------------------------------------

int City::releaseGrain() {
	double xp, zp;
	float x, z;
	char string[256];
	int HowMuch, Maximum, Minimum;
	bool IsOK;
	IsOK = false;
	Minimum = grainReserve / 5;
	Maximum = (grainReserve - Minimum);
	while(IsOK == false) {
		std::cout << "\nHow much grain will you release for consumption?\n";
		std::cout << "1 = Minimum(" << Minimum << "), 2 = Maximum(" << Maximum << "), or enter a value: ";
		std::cin >> HowMuch;
		if(HowMuch == 1) {
			HowMuch = Minimum;
		}
		if(HowMuch == 2) {
			HowMuch = Maximum;
		}
		/* Are we being a Scrooge? */
		if(HowMuch < Minimum) {
			std::cout << "You must release at least 20%% of your reserves.\n";
		}
		/* Whoa. Slow down there son. */
		else if(HowMuch > Maximum) {
			std::cout << "You must keep at least 20%.\n";
		}
		else {
			IsOK = true;
		}
	}
	soldiersPay = marketRevenue = newSerfs = deadSerfs = 0;
	transplantedSerfs = fleeingSerfs = 0;
	//invadeMe = False;
	grainReserve -= HowMuch;
	z = (float)HowMuch / (float)grainDemand - 1.0;
	if(z > 0.0) {
		z /= 2.0;
	}
	if(z > 0.25) {
		z = z / 10.0 + 0.25;
	}
	zp = 50.0 - (double)customsDuty - (double)salesTax - (double)incomeTax;
	if(zp < 0.0) {
		zp *= (double)justice;
	}
	zp /= 10.0;
	if(zp > 0.0) {
		zp += (3.0 - (double)justice);
	}
	z += ((float)zp / 10.0);
	if(z > 0.5) {
		z = 0.5;
	}
	if(HowMuch < (grainDemand - 1)) {
		x = ((float)grainDemand - (float)HowMuch) / (float)grainDemand * 100.0 - 9.0;
		xp = (double)x;
		if(x > 65.0) {
			x = 65.0;
		}
		if(x < 0.0) {
			xp = 0.0;
			x = 0.0;
		}
		//SerfsProcreating(Me, 3.0);
		//SerfsDecomposing(Me, xp + 8.0);
	}
	else {
		//SerfsProcreating(Me, 7.0);
		//SerfsDecomposing(Me, 3.0);
		if((customsDuty + salesTax) < 35) {
			merchants += randomInt(4);
		}
		if(incomeTax < randomInt(28)) {
			nobles += randomInt(2);
			clergy += randomInt(3);
		}
		if(HowMuch > (int)((float)grainDemand * 1.3)) {
			zp = (double)serfs / 1000.0;
			z = ((float)HowMuch - (float)(grainDemand)) /
			(float)grainDemand * 10.0;
			z *= ((float)zp * (float)randomInt(25));
			z += (float)randomInt(40);
			transplantedSerfs = (int)z;
			serfs += transplantedSerfs;
			std::cout << transplantedSerfs <<" serfs move to the city\n";
			zp = (double)z;
			//z = ((float)zp * (float)rand()) / (float)RAND_MAX;
			z = randomDouble(100.0);
			if(z > 50.0) {
				z = 50.0;
			}
			merchants += (int)z;
			nobles++;
			clergy += 2;
		}
	}
	if(justice > 2) {
		justiceRevenue = serfs / 100 * (justice - 2) * (justice - 2);
		justiceRevenue = randomInt(justiceRevenue);
		serfs -= justiceRevenue;
		fleeingSerfs = justiceRevenue;
		std::cout << fleeingSerfs << " serfs flee harsh justice\n";
	}
	marketRevenue = marketplaces * 75;
	if(marketRevenue > 0) {
		treasury += marketRevenue;
		std::cout << "Your market earned " << marketRevenue << " florins.\n";
	}
	millRevenue = mills * (55 + randomInt(250));
	if(millRevenue > 0) {
		treasury += millRevenue;
		std::cout << "Your woolen mill earned " <<  millRevenue << " florins.\n";
	}
	soldiersPay = soldiers * 3;
	treasury -= soldiersPay;
	std::cout << "You paid your soldiers " << soldiersPay <<" florins.\n";
	std::cout << "You have " << serfs << " serfs in your city.\n";
	std::cout << "(Press ENTER to advance to next year): ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	if((land / 1000) > soldiers) {
		//invadeMe = True;
		return(3);
	}
	if((land / 500) > soldiers) {
		//invadeMe = True;
		return(3);
	}
	return(0);
}

//--------------------------------------------------------------------------------------------------
//Random Number Generation

int City::randomInt(int i) {
	std::uniform_int_distribution<int> distribution(0, i);
	std::random_device device;
	std::mt19937 generator(device());
	return distribution(generator);
}

double City::randomDouble(double d) {
	std::uniform_real_distribution<double> distribution(0, d);
	std::random_device device;
	std::mt19937 generator(device());
	return distribution(generator);
}
