/**
 * Przykład numer 3 do automatycznej dedukcji typów w szablonach klas
 * Info: Ten przykład pokazuje jak robi się teraz.
 * 
 * Źródło: https://www.youtube.com/watch?v=STJExxBU54M (Class Template Argument Deduction in C++17 - Timur Doumler (JetBrains) [ACCU 2018])
 * Ogolnie bardzo fajna prezentacja czlowieka pracujacego w JetBrains - opowiada bardzo dokladnie jak dziala caly mechanizm.
 */


#include <iostream>
#include <utility>
#include <string>

int main()
{
	using namespace std::string_literals;
    std::pair resultE {"Student E"s, 5.0}; /// mozliwe od C++17 !!!
    /// Argumenty szablonu są mozliwe do dedukcji z argumentow konstruktora
    std::cout << resultE.first << " " << resultE.second << std::endl;

    /// Uwaga - nie zadziala z auto:
    /// auto resultF {"Student F"s, 5.0};
    /// Błąd: direct-list-initialization of 'auto' requires exactly one element - czyli nie wie, ze tam ma byc std::pair
}