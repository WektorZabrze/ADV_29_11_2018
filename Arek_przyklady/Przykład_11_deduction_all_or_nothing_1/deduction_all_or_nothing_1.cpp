/**
 * Przykład numer 5 do automatycznej dedukcji typów w szablonach klas
 *
 * Dedukcja dla szablonow dziala na zasadzie "all or nothing" - mozemy
 * podac pomiedzy <> wszystkie typy, albo ŻADEN
 *
 * Nie mozna podać np połowy typów - no chyba ze mamy szablon z typami domyslnymi
 * to wtedy te mozna pominac
 */

#include <iostream>
#include <tuple>
#include <string>

int main() {

    using namespace std::string_literals;

    /// Tak jak ponizej jest ok, ale w starym stylu
    std::tuple<std::string, double, int> a ("Student A"s, 2, 4.0);

    std::cout << "Name = " << std::get<0>(a) << "\n" <<
            "Year = " << std::get<1>(a) << "\n" <<
            "Grade = " << std::get<2>(a) << std::endl;

    /// W przykladzie powyzej podajemy wszystkie argumenty

    /// Mozna tez zrobic tak - i tu korzystamy z C++17:
    std::tuple b {"Student B"s, 3, 5.0};

    std::cout << "Name = " << std::get<0>(b) << "\n" <<
              "Year = " << std::get<1>(b) << "\n" <<
              "Grade = " << std::get<2>(b) << std::endl;

    /// Tutaj zaś nie podalismy nic - jest to w zgodzie z zasada "all or nothing"

    /// Ponizszy przyklad natomiast juz nie zadziala:
    ///std::tuple<std::string, int> c {"Student C"s, 3, 2.0};

    /// Podobnie jak ponizszy:
    ///std::tuple<std::string> c {"Student C"s, 3, 2.0};

}