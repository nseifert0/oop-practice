//Nicholas Seifert

#ifndef JSON_HPP
#define JSON_HPP

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>


class json {
	public:
		json()
		{

		}
		virtual ~json() = default;
	private:

};

class nullValue : json {
	
};

class boolValue : json {
	bool val;
};

class numValue : json {
	double val;
};

class stringValue : json {
	string val;
};

class arrayValue : json , vector<json *>{
	
};

class objectValue : json {
	std::unordered_map<string, string> values;
};
#endif
