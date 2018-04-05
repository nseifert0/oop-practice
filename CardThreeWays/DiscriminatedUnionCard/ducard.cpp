#include "bitcard.hpp"

Rank Bitcard::getRank() const {
	return (Rank)(0b001111 & bits);
}

Suit Bitcard::getSuit() const {
	return (Suit)((0b110000 & bits) >> 4);
}

bool Bitcard::operator==(Bitcard bc) const {
	return bits == bc.bits;
}

bool Bitcard::operator!=(Bitcard bc) const {
	return bits != bc.bits;
}