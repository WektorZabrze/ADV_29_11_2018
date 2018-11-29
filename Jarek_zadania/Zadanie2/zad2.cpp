#include <iostream>
#include <utility>
#include <vector>
#include <array>
#include <cmath>
#include <type_traits>

// Nalezy uzupelnic tak plik zad2.cpp, aby output był zgodny z podanym w komentarzu.
// W tym zadaniu nalezy skorzystac z funkcjonalnosci jezyka jak if init statement, if constexpr oraz structured binding
// Funktor sumIfSame nie powinien mieć specjalizacji, funkcjonalnosc nalezy zaimplementować z uzyciem if constexpr
// Funktor ma sumowac jezeli typy sa takie same, w przeciwnym przypadku wypisuje stosowny komunikat (patrz output)
// w mainie nie powinno definiowac sie zadnych zmiennych poza miejscem, w ktorym jest komentarz "wstaw", aby to osiągnąć należy
// napisać funkcję pomocniczą, której typ zwracany pozwala na wykorzystanie structured binding


/*
tutaj napisz funkcję i funktor
*/


int main(){
	std::vector< std::pair< std::pair<double, double> , std::pair<double,double> > > punkty;

	for(int i = 1; i < 100; ++i){
		std::pair<double,double> first{i,(i+56)%i};
		std::pair<double,double> second{i,i};
		punkty.emplace_back(first,second);
	}

	for(/*wstaw*/: punkty){
		/*
		uzupelnij
		*/
	}

	std::cout<<std::endl<<"sumIfSame"<<std::endl;
	std::cout<<sumIfSame<int,int>()(1,1)<<std::endl<<sumIfSame<double,int>()(2.3,2)<<std::endl;
}

// Oczekiwany output:

// Odległość między punktami większa od 44
// x1: 51 y1: 5
// x2: 51 y2: 51
// Odległość między punktami większa od 44
// x1: 52 y1: 4
// x2: 52 y2: 52
// Odległość między punktami większa od 44
// x1: 53 y1: 3
// x2: 53 y2: 53
// Odległość między punktami większa od 44
// x1: 54 y1: 2
// x2: 54 y2: 54
// Odległość między punktami większa od 44
// x1: 55 y1: 1
// x2: 55 y2: 55
// Odległość między punktami większa od 44
// x1: 56 y1: 0
// x2: 56 y2: 56

// sumIfSame
// 2
// Typy sa rozne