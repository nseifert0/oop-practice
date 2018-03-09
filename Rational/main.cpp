#include<iostream>
#include<cassert>
#include "Rational.hpp"
 
int main(int argc, char *argv[]){
	Rational r1(1, 2);
	Rational r2(2, 4);
	assert(r1 == r2);
	
	return 0;
}