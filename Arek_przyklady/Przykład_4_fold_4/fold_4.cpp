/**
 * Przyklad obrazujacy dzialanie fold expressions 
 * z operatorem przecinka. Wypisywanie parameter 
 * packa na standardowe wyjscie.
 */

#include <iostream>

// Stary sposob - variadic templates

template <typename T>
void print_parameter_pack_elements (T&& value) {
	std::cout << value << std::endl;
}

template <typename T, typename ... Args>
void print_parameter_pack_elements (T&& value, Args&& ... args) {
	std::cout << value << " ";
	print_parameter_pack_elements(args...);
}


// Nowy sposob - fold expressions

template <typename ... Args>
void print_parameter_pack_elements_fold ( Args&& ... args) {
	( void(std::cout << args << " "), ..., void(std::cout << std::endl )); 
	// uwaga - zewnetrzne nawiasy sa czescia fold, wewnatrzne to cast na void
}


int main(){

	// wywolanie sposobu z variadic templates
	print_parameter_pack_elements(1, 2, 3, 4, 5.5, "koniec");

	// wywolanie sposobu z fold expressions
	print_parameter_pack_elements_fold(1, 2, 3, 4, 5.5, "koniec");

	// rozwija sie to w cos takiego:
	(void (std::cout << 1 << " "), 
	(void (std::cout << 2 << " "),
	(void (std::cout << 3 << " "),
	(void (std::cout << 4 << " "),
	(void (std::cout << 5.5 << " "),
	(void (std::cout << "koniec" << " "), void (std::cout << std::endl) ) ) ) ) ) );

	return 0;
}

/**
 * Wyjasnienie dzialania:
 * 
 * Zacznijmy od tego jak wogole dziala operator przecinka
 * Zalozmy ze mamy dwa wyrazenia: 
 * E1 - wyrazenie pierwsze
 * E2 - wyrazenie drugie
 *
 * Zapisujemy: E1, E2
 * E1 jest wykonywane, rezultat jest ODRZUCANY (ale niekoniecznie od razu 
 * niszczony jesli jest obiektem klasy) i jego skutki uboczne (side effects
 * - zmiany w stanie srodowiska wykonywania - np. modyfikacja obiektu, 
 * wezwanie funkcji IO) sa zakonczone PRZED ROZPOCZECIEM wykonywania E2. 
 * Dosyc czesta operacja jest, ze chcemy wykonac pewna funkcje DLA KAZDEGO
 * ELEMENTU parameter packa. Przykladem jest wypisanie wszystkich wartosci 
 * na standardowe wyjscie.
 *
 *
 */