#include <iostream>

#include "bitcard.hpp"

int main() {
	Bitcard bc(Ace, Spades);
	Rank r = bc.getRank();
	Suit s = bc.getSuit();
	std::cout << r << " of " << s << "\n";
	return 0;
}