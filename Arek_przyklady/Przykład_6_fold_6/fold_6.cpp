/**
 * Fold expressions - przykład 6
 * Kolejny przykład na operator przecinka - pokazuje,
 * co się dzieje, jak parameter pack będzie pusty.
 */

#include <iostream>

//#define ERROR

template <typename ... Args>
int last(Args ... args) {
	return (args, ...);
}


int main() {

	auto a = last(1, 2, 3, 4, 5);
	std::cout << a << std::endl;

	#ifdef ERROR
		auto b = last(); //void value not ignored as it ought to be
		// pokazac co sie stanie jak zmienimy int na auto w type
		// zwracanym funkcji
	#endif


	return 0;
}