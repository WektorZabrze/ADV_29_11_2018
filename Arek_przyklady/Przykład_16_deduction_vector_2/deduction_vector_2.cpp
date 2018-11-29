/**
 * Przykład działania deduction guideow dla vectora
 */

#include <iostream>
#include <vector>

/// Funkcja typu demangle - zrodlo:
// https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
	#include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>

template <class T>
std::string type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own (
		#ifndef _MSC_VER
        	abi::__cxa_demangle(typeid(TR).name(), nullptr, nullptr, nullptr),
		#else
            nullptr,
		#endif
            std::free);
    	std::string r = own != nullptr ? own.get() : typeid(TR).name();
    	if (std::is_const<TR>::value)
    	    r += " const";
    	if (std::is_volatile<TR>::value)
    	    r += " volatile";
    	if (std::is_lvalue_reference<T>::value)
    	    r += "&";
    	else if (std::is_rvalue_reference<T>::value)
    	    r += "&&";
    return r;
}

///

int main() {

	std::vector a { 1, 2, 3, 4, 5, 6, 7};
	std::vector b ( a.begin(), a.end() );
	std::vector c { a.begin(), a.end() }; 
	// lista inicjalizacyjna ma pierwszenstwo przed konstruktorem

	std::cout << type_name< decltype(a) >() << std::endl;
	std::cout << type_name< decltype(b) >() << std::endl;
	std::cout << type_name< decltype(c) >() << std::endl; // vector iteratorow
}