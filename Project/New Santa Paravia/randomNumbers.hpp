#ifndef RANDOMNUMBERS_HPP
#define RANDOMNUMBERS_HPP
#include<random>

	int randomInt(int i) {
		std::uniform_int_distribution<int> distribution(0, i);
		std::random_device device;
		std::mt19937 generator(device());
		return distribution(generator);
	}
	
	double randomDouble(double d) {
		std::uniform_real_distribution<double> distribution(0, d);
		std::random_device device;
		std::mt19937 generator(device());
		return distribution(generator);
	}
#endif