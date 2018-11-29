/**
 * Przykład numer 1 do automatycznej dedukcji typów w szablonach klas
 * Info: Ten przykład pokazuje jak robiło się wczesniej
 * 
 * Źródło: https://www.youtube.com/watch?v=STJExxBU54M (Class Template Argument Deduction in C++17 - Timur Doumler (JetBrains) [ACCU 2018])
 * Ogolnie bardzo fajna prezentacja czlowieka pracujacego w JetBrains - opowiada bardzo dokladnie jak dziala caly mechanizm.
 */


#include <iostream>


/// Szablon funkcji min
template <typename T>
const T& min( const T& a, const T& b) {
    return a < b ? a : b;
}

int main()
{
    /// Automatyczne dedukcja dzialala dla szablonow funkcji - tzn:
    /// mozna bylo napisac tak:
    int smaller = min<int> (5, 3);
    std::cout << "Smaller value = " << smaller << std::endl;

    /// Ale mozna bylo tez prosciej - tak:
    smaller = min (6, 7); // tu wydedukuje, ze chodzi o min<int>
    std::cout << "Smaller value = " << smaller << std::endl;

    double smallerD = min(6.3, 6.2); // tu wydedukuje, ze chodzi o min<double>
    std::cout << "Smaller value = " << smallerD << std::endl;

    /// Problem jak damy dwa rozne typy, np:
    //auto smallerErr = min(2, 2.5);
    /// template argument deduction/substitution failed

    /// Wtedy trzeba bylo podac typ bezposrednio:
    auto smallerNoErr = min<double>(2, 2.5); /// min<double> - nie ma domniemania, podane bezposrednio
    std::cout << "Smaller value = " << smallerNoErr << std::endl;
}
