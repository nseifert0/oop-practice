#include "string.hpp"

bool string::operator==(const string& str) {
	if(this->length == str.length)
		return true;
	else
		return false;
}

bool string::operator<(const string& str) {
	if(this->length < str.length)
		return true;
	else
		return false;
}
