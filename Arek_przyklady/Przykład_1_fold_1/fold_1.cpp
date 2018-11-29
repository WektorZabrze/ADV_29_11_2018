/**
 * Fold expressions - przykład 1
 * Pokazanie działania fold expressions, porównanie do variadic
 * templates.
 */

#include <iostream>

/**
 * Stary sposób - variadic templates
 */

template <typename T>
auto sumVar (T&& value) {
	return value;
} 

template <typename T, typename ... Args>
auto sumVar (T&& value, Args&& ... args) {
	return value + sumVar(args...);
}


/**
 * Nowosc - fold expressions.
 */
template <typename ... Args>
auto sum (Args&& ... args) {
	return (args + ...);
}

int main() 
{
	std::cout << "-- Variadic templates --" << std::endl;
	auto sumVariadic = sumVar(1,2,3,4,5,6,7.5);
	std::cout << sumVariadic << std::endl;

	std::cout << "-- Fold expressions --" << std::endl;
	auto sum1 = sum(1,2,3,4,5,6,7.5);
	std::cout << sum1 << std::endl;
}