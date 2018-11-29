/// Przykład numer 5 do automatycznej dedukcji typów w szablonach klas

/// Ciekawym faktem jest to, ze zasada "all or nothing" nie istniala przy szablonach
/// funkcji

#include <iostream>
#include <tuple>

template <typename T1, typename T2, typename T3>
void printType(const T1& val1, const T2& val2, const T3& val3)
{
    std::cout << typeid(val1).name() << " \n" << typeid(val2).name() << " \n" << typeid(val3).name() << std::endl;
}

int main() {

    using namespace std::string_literals;

    printType(3, "Jakis napis"s, "Jakis napis");

    printType<double>(3.4, "Jakis napis 2"s, 2); // Tu mozemy podac tylko czesc i nie potrzeba nam
    // argumentow domyslnych

    /// Co za tym idzie, mozna bylo tak robic w funkcjach typu make_pair czy make_tuple

    auto t1 = std::make_tuple<std::string>("T1"s, 5.5);

}