#include <iostream>
#include "bitwisemath.h"

int main()
{
	std::cout << "1 + 3 = " << add(1, 3) << '\n'
		<< "2 - 4 = " << substract(2, 4) << '\n'
		<< "4 * 5 = " << multiply(4, 5) << '\n'
		<< "10 / 3 = " << divide(10, 3) << '\n'
		<< "negation of 5 = " << negate(5) << '\n'
		<< "10 ^ 5 = " << power(10, 5);
	return 0;
}