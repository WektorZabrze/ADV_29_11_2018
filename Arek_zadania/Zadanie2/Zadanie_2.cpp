/**
 * Autor: Arkadiusz Kasprzak
 * Zadanie 2
 * Proszę napisać prostą klasę przechowującą posortowaną kolekcję. Proszę 
 * nie używać do tego std::set. Implementacja powinna być jak najprostsza
 * (proszę zaimplementować tylko metody widoczne w main). Stworzona klasa
 * powinna posiadać conajmniej jedno user defined deduction guide. 
 * Proszę również napisać klasę point i szablony dwóch funkcji widocznych w main. 
 * W obu szablonach należy wykorzystać fold expressions. Funkcja print nie 
 * może wykorzystywać operatora przecinka. 
 * Pliku main.cpp nie można zmieniać. 
 * Wyjście powinno być takie jak na dole pliku main.cpp.
 */


#include <vector>

#include "SortedContainer.h"
#include "Point.h"


int main() 
{
	std::cout << "--EMPTY CONTAINER--" << std::endl;
	SortedContainer<int> a;
	a.print();

	std::cout << "--COPIED CONTAINER--" << std::endl;
	std::vector original {1, 2, 3, 5, 4, 6};
	SortedContainer copy (original.begin(), original.end());
	copy.print();

	std::cout << "--REVERSED CONTAINER--" << std::endl;
	SortedContainer changedOrder (original.begin(), original.end(), 
		[](const int& lhs, const int& rhs) { return rhs < lhs; });
	changedOrder.print();

	std::cout << "--POINT OPERATIONS--" << std::endl;
	Point p_a (1, 1);
	Point p_b (30, 15);
	Point p_c (11, 2);

	print (p_a, p_b, p_c);
	move( 5, 6, p_a, p_b, p_c);
	print (p_a, p_b, p_c);

	return 0;
}

/*
--EMPTY CONTAINER--

--COPIED CONTAINER--
1 2 3 4 5 6
--REVERSED CONTAINER--
6 5 4 3 2 1
--POINT OPERATIONS--
1, 1
30, 15
11, 2

6, 7
35, 21
16, 8
*/