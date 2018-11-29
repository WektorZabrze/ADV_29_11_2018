//Celem zadania jest zaimplementowanie klasy BindableArray, 
//która pozwala na przechowywanie elementów, które są takiego typu, 
//jak typ podany w argumencie szablonu oraz w takiej ilosci jak podane w argumencie szablonu.
//Nalezy zadbac o zabezpieczenie przed dodaniem większej ilości.
//Klasa BindableArray powinna mieć podstawowe wsparcie dla structured binding tak, 
//aby output programu był zgodny z podanym w mainie

// Podpowiedź:

// Jako, że BindableArray jest klasą szablonową możemy w prostu sposób określić typ w strukturze tuple element jako:
// typedef T type;

#include "bindableArray.h"

int main(){
	std::cout<<"BindableArray<int,4> :"<<std::endl;
	BindableArray<int, 4> arr;
	arr.insert(1).insert(2).insert(3).insert(4).insert(5);
	auto[a,b,c,d] = arr;
	arr.print();
	std::cout<<a<<" "<<b<<" "<<c<<" "<<d<<std::endl;

	std::cout<<"BindableArray<std::string,4> :"<<std::endl;
	BindableArray<std::string, 4> arr2;
	arr2.insert("Witam").insert("jak").insert("tam").insert("zycie");
	auto[a2,b2,c2,d2] = arr2;
	arr2.print();
	std::cout<<a2<<" "<<b2<<" "<<c2<<" "<<d2<<std::endl;

	std::cout<<"BindableArray<double,2> :"<<std::endl;
	BindableArray<double,2> arr3;
	arr3.insert(2.3).insert(3.4);
	auto&[c3,d3] = arr3;
	arr3.print();
	c3++;
	std::cout<<c3<<" "<<d3<<std::endl;
	arr3.print();
}

// Oczekiwany output:

// BindableArray<int,4> :
// 1 2 3 4
// 1 2 3 4
// BindableArray<std::string,4> :
// Witam jak tam zycie
// Witam jak tam zycie
// BindableArray<double,2> :
// 2.3 3.4
// 3.3 3.4
// 3.3 3.4