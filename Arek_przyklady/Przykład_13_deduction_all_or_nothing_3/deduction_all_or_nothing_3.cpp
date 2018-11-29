/**
 * Przykład do CTAD
 * Przykład obrazuje działanie zasady "all or nothing" gdy
 * mamy domyślne wartości parametrów szablonu
 */

#include <iostream>
#include <string>

using namespace std::string_literals;

template <typename T, typename U, typename Z = double >
class Triad
{
public:

	Triad(T&& first, U&& second, Z&& third) 
		: m_first(first), m_second(second), m_third(third) {}

	void print() const {
		std::cout << m_first << std::endl;
		std::cout << m_second << std::endl;
		std::cout << m_third << std::endl;
	} 

private:
	T m_first;
	U m_second;
	Z m_third;
};


int main()
{
	Triad <int, int, int> test1 {1, 2, 3};
	test1.print();

	Triad test2 {"Jakiś"s, "randomowy"s, "napis"s};
	test2.print();

	/// Działa, pomimo ze nie podalismy wszystkich, bo domyslne
	Triad <int, std::string> test3 (5, "Pięć", 5.0);
	test3.print();

	return 0;
}