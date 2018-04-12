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
		std::cout << "{}";
	}
};

struct Bool : Value {
	Bool(bool b) : val(b) { }
	bool val;
	void print() const override {
		std::cout << val;
	}
};

struct Number : Value {
	Number(double d) : val(d) { }
	double val;
	void print() const override {
		std::cout << val;
	}
};

struct String : Value {
	String(std::string s) : val(s) { }
	std::string val;
	void print() const override {
		std::cout << val;
	}
};

struct Array : Value , std::vector<Value*>{
	void add(Value* v) {
		this->push_back(v);
	}
	void print() const override {
		std::cout << "[";
		for (std::vector<Value*>::const_iterator it=this->begin(); it!=this->end(); ++it) {
			(*it)->print();
			std::cout << ", ";
		}
		std::cout << "]";
	}
};

struct Object : Value {
	std::map<String*, Value*> values;
	void add(String* k, Value* v) {
		values.insert ( std::pair<String*,Value*>(k,v) );
	}
	void print() const override {
		std::cout << "{\n";
		for (std::map<String*, Value*>::const_iterator it=values.begin(); it!=values.end(); ++it) {
			std::cout << "\t";
			it->first->print();
			std::cout << ": ";
			it->second->print();
			std::cout << ",\n";
		}
		std::cout << "}\n";
	}
};

Value* parse(const std::string&);
#endif
