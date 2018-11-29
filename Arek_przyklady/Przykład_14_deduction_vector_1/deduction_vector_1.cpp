/**
 * Kolejny przykład do automatycznej dedukcji argumentow
 * szablonowych dla klas. Przyklad obrazuje "dziwne" zachowanie
 * jednego z konstruktorow std::vector - ma zobrazowac obecnosc
 * dodatkowego mechanizmu dedukcji.
 */

#include <vector>
#include <iostream>

int main() 
{
	std::vector a {1, 2, 3, 4, 5, 6};
	std::vector b (a.begin(), a.end()); /// !!!!!!!!
	for (auto& elem : b)
		std::cout << elem << std::endl;
}
