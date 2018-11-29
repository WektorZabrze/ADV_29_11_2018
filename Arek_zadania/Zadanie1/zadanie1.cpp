/**
 * Autor: Arkadiusz Kasprzak
 * Zadanie 1
 * Zadanie polega na przećwiczeniu dedukcji argumentów dla szablonów klas
 * oraz fold expressions.  
 * Do napisania jest kilka rzeczy:
 * 	- szablon funkcji pushManyElementBack - wstawia dowolną liczbę elementów
 * 		do gotowego vectora. Funkcja nie może zawierać petli i jawnego 
 *		wywołania samej siebie (należy użyć materiału poznanego na prezentacji)
 *	- szablon klasy Product, posiadającej dwa konstruktory - jak widać 
 *		w funkcji main. Konstruktor przyjmujący dowolną liczbę argumentów musi
 *		zawierać wykorzystanie funkcjonalności języka poznanych na prezentacji.
 *	- user defined deduction guides dla klasy Product - dla wyżej wymienionych
 *		konstruktorów. Wskazówka: w celu ustalenia wspólnego typu przekazanych
 * 		argumentów, można użyć std::common_type z nagłówka <type_traits>
 * 	- szablon klasy Difference, posiadajacej dwie metody - liczacej roznice 
 * 		elementow od lewej do prawej roznice od 0
 * Pliku main.cpp nie można zmieniać. Oczekiwane wyjście na dole pliku main.cpp.
 *
 * Zadanie wzorowane jest na przykładzie z książki Jacka Galowicza 
 * "C++17 STL Cookbook". 
 */

#include "Product.h"
#include "Difference.h"
#include "VectorPushMany.h"

#include <iostream>
#include <vector>

int main() 
{
	std::vector<int> a;
	pushManyElementsBack(a, 1, 2, 3, 4, 5, 6);

	std::cout << "-- Zawartosc vectora --" << std::endl;
	for (auto& elem : a)
		std::cout << elem << " ";
	std::cout << std::endl;

	std::cout << "-- Iloczyn elementow parameter-packa --" << std::endl;
	Product product (1, 2, 3, 4, 5, 6);
	std::cout << product << std::endl;

	std::cout << "-- Iloczyn elementow vectora --" << std::endl;
	Product product2 (a.begin(), a.end());
	std::cout << product2 << std::endl;

	std::cout << "-- Trochę inny iloczyn --" << std::endl;
	Product product3 (1, 2, 3.5, -25.5);
	std::cout << product3 << std::endl;

	std::cout << "-- A teraz roznice --" << std::endl;
	Difference diff1;
	diff1.leftToRight(10, 5, 1);
	std::cout << diff1 << std::endl;
	diff1.leftToRightFromZero(10, 5, 1);
	std::cout << diff1 << std::endl;
}

/*
-- Zawartosc vectora --
1 2 3 4 5 6
-- Iloczyn elementow parameter-packa --
720
-- Iloczyn elementow vectora --
720
-- Trochę inny iloczyn --
-178.5
-- A teraz roznice --
4
-16
*/