#pragma once
#include <iostream>
#include <type_traits>

template<typename T>
class Product{
public:
	template<typename ... Args>
	Product(Args... args){
		iloczyn = 1;
		iloczyn *= (... * args);
	}

	template<typename Iter>
	Product(Iter start, Iter stop){
		iloczyn = 1;
		for(auto it = start; it!=stop; ++it){
			iloczyn*=(*it);
		}
	}

	friend std::ostream& operator<<(std::ostream& os, const Product& to_print){
		os<<to_print.iloczyn;
		return os;
	}

private:
	T iloczyn;
};

template<typename ... Args>
Product(Args... args) -> Product<std::common_type_t<Args ...>>;

template<typename Iter>
Product(Iter start, Iter stop) -> Product<typename std::iterator_traits<Iter>::value_type>;