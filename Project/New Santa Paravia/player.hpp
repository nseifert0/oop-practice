#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>
#include "resources.hpp"

enum Title {
	Sir,
	Baron,
	Count,
	Marquis,
	Duke,
	Grand_Duke,
	Prince,
	King,
	Lady,
	Baroness,
	Countess,
	Marquise,
	Duchess,
	Grand_Duchess,
	Queen
};

enum Gender {
	Male,
	Female
};

class Player {
	public:
		Player(std::string n, Gender g)
			:name(n), gender(g)
		{
			if(gender == Male)
				title = Sir;
			else
				title = Lady;
		}
	
	Gender getGender() {
		return gender;
	}
	
	private:
		std::string name;
		Title title;
		Gender gender;
		bool isBankrupt;
		bool isDead;
		bool hasWon;
		Resources resources;
};

#endif