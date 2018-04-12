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
		virtual void print() const = 0;
		virtual ~json() = default;
	private:

};

class Null : Value {
	void print() const override {
		std::cout << "\n";
	}
};

class Bool : Value {
	bool val;
	void print() const override {
		std::cout << val << "\n";
	}
};

class Number : Value {
	double val;
	void print() const override {
		std::cout << val << "\n";
	}
};

class String : Value {
	string val;
	void print() const override {
		std::cout << val << "\n";
	}
};

class Array : Value , vector<value *>{
	void print() const override {
		std::cout << val << "\n";
	}
};

class Object : Value {
	std::unordered_map<string, string> values;
};
#endif
