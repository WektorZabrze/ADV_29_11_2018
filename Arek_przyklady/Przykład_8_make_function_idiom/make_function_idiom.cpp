/**
 * Przykład numer 2 do automatycznej dedukcji typów w szablonach klas
 * Dedukcja dla funkcji i make function idiom (przed C++17)
 */

#include <utility>
#include <string>
#include <iostream>

int main()
{
	/// W standardzie C++98 nie bylo wyjscia, trzeba bylo podac argumenty bezposrednio:
    std::pair<const char*, double> resultA ("Student A", 5.0); /// Bez podania argumentow blad kompilacji
    std::cout << resultA.first << " " << resultA.second << std::endl;

    /// Inne wyjscie - uzyc funkcji typu "make" (make functions idiom), np make_pair
    /// Bazujemy tutaj na fakcie, ze kompilator potrafi wydedukowac typ w szablonie funkcjo:
    std::pair<const char*, double> resultB = std::make_pair("Student B", 4.5);
    std::cout << resultB.first << " " << resultB.second << std::endl;

    /// A uzywajac slowa kluczowego auto (od C++11) mozemy krocej:
    auto resultC = std::make_pair("Student C", 3.5); // wydedukuje std::pair<const char*, double>
    std::cout << resultC.first << " " << resultC.second << std::endl;

    /// Jak chcielibysmy std::string zamiast const char* to mozemy dodac s po literale
    using namespace std::string_literals;
    auto resultD = std::make_pair("Student D"s, 4.0); // wydedukuje std::pair<std::string, double>
    /// Jest to (string_literals) rozwiazanie znane z C++14 i wymaga uzycia odpowiedniej przestrzeni nazw
    std::cout << resultD.first << " " << resultD.second << std::endl;
}