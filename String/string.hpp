//Nicholas Seifert
//
//The majority of this string implementation
//was copied from Andrew Sutton at
//https://gitlab.com/andrew.n.sutton/spring-18-oop/blob/master/war/string.cpp

#ifndef STRING_HPP
#define STRING_HPP

#include <cstring>

class string {
	public:
		string()
		{
		}
		
		string(const char* s)
			: length(std::strlen(s)), s(new char[length])
		{	
		}
		
		string(const string& str)
			: length(str.length), s(new char[length])
		{
			for(int i = 0; i < this->length; i++)
			{
				this->s[i] = str.s[i];
			}
		}
		
		bool operator==(const string& str);
		bool operator<(const string& str);
		
		~string()
		{
			delete[] s;
		}
		
	private:
		int length;
		char* s;
};

#endif