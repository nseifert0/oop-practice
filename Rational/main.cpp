#include<iostream>
#include<cassert>
#include "Rational.hpp"
 
int main(int argc, char *argv[]){
	Rational r1(5, 6);
	Rational r2(6, 10);
	assert(r1 == r2);
	
	return 0;
}