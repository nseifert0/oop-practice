#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

enum Title {
	Sir,
	Count
};

class Player {
	public:
		Player(std::string n, Title t)
			:name(n), title(t)
		{
		}
		
	private:
		std::string name;
		Title title;
};

#endif