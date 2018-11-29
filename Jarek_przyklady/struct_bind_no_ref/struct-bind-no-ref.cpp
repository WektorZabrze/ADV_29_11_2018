#include <iostream>
#include <type_traits>
#include <utility>

int main() {
	std::pair<int, int> p1 {1,2};

	auto [a, b] = p1;
	a++;
	std::cout << "Wartość a: " <<a << " Wartość p1.first: " << p1.first << std::endl;

	std::cout << "Czy a jest referencją: " <<std::is_reference<decltype(a)>::value << std::endl;
	std::cout << "Czy a ma typ int: "<<std::is_same<decltype(a), int>::value <<std::endl;

	auto& [c, d] = p1;
	c++;
	std::cout << "Wartośc c: "<< c << " Wartośc p1.first: " << p1.first << std::endl;

	std::cout << "Czy c jest referencją: "<<std::is_reference<decltype(c)>::value << std::endl;
	std::cout << "Czy c ma typ int: " <<std::is_same<decltype(c), int>::value <<std::endl;

	int var1 = 1;
	int var2 = 1;
	std::pair<int&, int&> para = {var1, var2};

	auto [e,f] = para;
	e++;
	std::cout << "Wartośc e: " << e << " Wartośc var1: " << var1 << std::endl;
	std::cout << "Czy e jest referencją: " << std::is_reference<decltype(e)>::value << std::endl;
	std::cout << "Czy e ma typ int: " << std::is_same<decltype(e), int>::value << std::endl;
	return 0;
}