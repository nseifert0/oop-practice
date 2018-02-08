#include "string.hpp"

bool string::operator==(const string& str) {
	if(this->length != str.length) {
		return false;
	}
	else {
		for(int i=0; i< this->length; i++) {
			if(this->s[i] != str.s[i]) {
				return false;
			}
		}
	}
	
	return true;
}

bool string::operator<(const string& str) {
	
	if(this->length < str.length) {
		for(int i=0; i< this->length; i++) {
			if(this->s[i] < str.s[i]) {
				return true;
			}
			else if(this->s[i] > str.s[i]) {
				return false;
			}
		}
	}
	
	if(this->length > str.length) {
		for(int i=0; i< str.length; i++) {
			if(this->s[i] < str.s[i]) {
				return true;
			}
			else if(this->s[i] > str.s[i]) {
				return false;
			}
		}
	}
	
	return false;
}
