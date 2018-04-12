//Nicholas Seifert

#ifndef JSON_HPP
#define JSON_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>


class Value {
	public:
		Value()
		{

		}
		virtual ~json() = default;
	private:

};

class Null : Value {
	
};

class Bool : Value {
	bool val;
};

class Number : Value {
	double val;
};

class String : Value {
	string val;
};

class Array : Value , vector<value *>{
	
};

class Object : Value {
	std::unordered_map<string, string> values;
};
#endif
