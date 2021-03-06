#include "string.hpp"
#include <iostream>

int main() {
	// Default construct
	string s0;

	// Construct and assign from a literal value
	string s1 = "bar";
	s1 = "foo";

	// Copy construct and assign
	string s2 = s1;
	s2 = s1; 
	if(s2 == s1)
	{
		std::cout << "Good\n";
	}
	

	// Move construction and assignment (optional)
//	string s3 = std::move(s2);
//	s3 = std::move(s1);

	// Compare
	s1 == s1;
	if(s1 == s1)
	{
		std::cout << "Good\n";
	}

	// Order
	s1 < s1; // lexicographical comparison

	// Object independence
	s2 = "bar"; // Does not change the value of s1
}
