#include <iostream>


int main (){
	int someInt = 256;
	short someShort;
	long someLong;
	float someFloat;
	double someDouble;

	someInt++;	
	someInt *= 2;	

	someShort = static_cast<short>(someInt); 
	someLong = someShort * 10000;
	someFloat = someLong + 0.785f;
	someDouble = static_cast<double>(someFloat) / 100000;

	std::cout << someShort << std::endl;
	std::cout << someDouble << std::endl;

	return 0;
}
