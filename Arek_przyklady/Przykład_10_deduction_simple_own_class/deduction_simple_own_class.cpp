/// Przykład numer 4 do automatycznej dedukcji typów w szablonach klas

/// Żródła:
/// - https://www.youtube.com/watch?v=STJExxBU54M (tak jak wczesniej)

/// Standard: [over.match.class.deduct]

/// Zrobmy sobie przykladowa klase - bedzie ona poprostu opakowywala 4 wartosci:

#include <iostream>
#include <string>
#include <tuple>


template <typename T1, typename T2, typename T3, typename T4>
class Storage
{
public:

    /// Zwykly 4 argumentowy konstruktor przyjmujacy const referencje na wartosci,
    /// ktore bedziemy przechowywac
    Storage(const T1& first, const T2& second, const T3& third, const T4& fourth) :
        m_first(first),
        m_second(second),
        m_third(third),
        m_fourth(fourth)
    {
        std::cout << "L-value constructor" << std::endl;
    }

    /// Konstuktor przyjujacy 4 referencje na r-value
    Storage(T1&& first, T2&& second, T3&& third, T4&& fourth) :
            m_first(first),
            m_second(second),
            m_third(third),
            m_fourth(fourth)
    {
        std::cout << "R-value constructor" << std::endl;
    }


private:
    T1 m_first;
    T2 m_second;
    T3 m_third;
    T4 m_fourth;

};


int main() {

    using namespace std::string_literals;

    /// Chcemy moc stworzyc instancje powyzszej klasy tak:
    Storage s1 {"Student A"s, 273322 , "IS"s, 5.0}; // zalozmy ze ma reprezentowac wpis z ocena studenta
    // Wybiera R-value constructor, bo podajemy mu r-wartosci

    auto studentName = "Student B"s;
    auto studentID = 200000;
    auto fieldOfStudy = "IS"s;
    auto grade = 4.0;
    Storage s2 (studentName, studentID, fieldOfStudy, grade); /// Teraz wybiera ten drugi konstruktor, ale typy
    /// dedukuje te same

    /// Wydedukowane typy: Storage<std::string, int, std::string, double>

    /// Jak widac mechanizm jest w tym przypadku prosty - tak naprawde nie zrobilismy
    /// nic nowego, a dziala. 
}