//Nicholas Seifert

#ifndef JSON_HPP
#define JSON_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>


struct Value {
	public:
		Value()
		{

		}
		virtual void print() const = 0;
		virtual ~Value() = default;
	private:

};

struct Null : Value {
	void print() const override {
		std::cout << "\n";
	}
};

struct Bool : Value {
	Bool(bool b) : val(b) { }
	bool val;
	void print() const override {
		std::cout << val << "\n";
	}
};

struct Number : Value {
	Number(double d) : val(d) { }
	double val;
	void print() const override {
		std::cout << val << "\n";
	}
};

struct String : Value {
	String(std::string s) : val(s) { }
	std::string val;
	void print() const override {
		std::cout << val << "\n";
	}
};

struct Array : Value , std::vector<Value*>{
	void add(Value* v) {
		this->push_back(v);
	}
	void print() const override {
	}
};

struct Object : Value {
	std::map<std::string, Value*> values;
	void add(std::string k, Value* v) {
		values.insert ( std::pair<std::string,Value*>(k,v) );
	}
	void print() const override {
	}
};

Value* parse(const std::string&);
#endif
