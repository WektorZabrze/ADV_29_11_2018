/**
 * Przykład obrazujący działanie fold expressions. 
 * Tutaj pokazane jest działanie unary fold w momencie, gdy mamy 
 * pusty parameter pack - tylko 3 operatory są wtedy dozwolone: 
 * &&, || oraz ,. 
 */

#include <iostream>

//#define ERROR_1
//#define ERROR_2

/// operator dozwolony w unary fold dla pustego 
/// parameter packa
template <typename ... Args>
auto andTest(Args ... args) {
	return ( args && ... ); // uwaga - bez () sie nie skompiluje
}


/// operator dozwolony w unary fold dla pustego
/// parameter packa
template <typename ... Args>
auto orTest(Args ... args) {
	return (args || ... );
}


/// operator niedozwolony w unary fold dla pustego
/// parameter packa
template <typename ... Args>
auto multiply (Args ... args) {
	return (args * ...); 
}

/// dla kontrastu - w binary fold juz dziala, zwraca
/// poprostu poczatkowa wartosc
template <typename ... Args>
auto multiplyBinary(Args ... args) {
	return (args * ... * 1);
}


/// podobnie jak wyzej - niedozwolone dla pustego 
/// parameter packa
template <typename ... Args>
auto add (Args ... args) {
	return (args + ...);
}

/// i znow dla kontrastu - dziala, gdy mamy binary 
/// fold
template <typename ... Args>
auto addBinary (Args ... args) {
	return (args + ... + 0);
}

int main() {

	auto value = andTest();
	std::cout << std::boolalpha << value << std::endl; 
	// zgodnie ze standardem - oczekiwana wartosc dla fold po 0 elementach

	auto value2 = orTest();
	std::cout << std::boolalpha << value2 << std::endl; 
	// rowniez zgodnie ze standardem

	#ifdef ERROR_1
		multiply(); // blad kompilacji "fold of empty expansion over operator*"
	#endif

	auto value3 = multiplyBinary();
	std::cout << value3 << std::endl;

	#ifdef ERROR_2
		add();
	#endif

	auto value4 = addBinary();
	std::cout << value4 << std::endl;

	return 0;
}