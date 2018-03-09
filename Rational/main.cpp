#include<iostream>
#include<cassert>
#include "Rational.hpp"
 
int main(int argc, char *argv[]){
	Rational r1(1, 4);
	Rational r2(2, 6);
	assert(r1 < r2);
	
	return 0;
}