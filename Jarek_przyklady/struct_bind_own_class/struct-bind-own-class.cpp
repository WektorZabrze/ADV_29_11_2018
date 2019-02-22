#include <iostream>
#include <type_traits>
#include <utility>
#include <string>
#include <cstdlib>
#include <tuple>

struct MyBindingStruct{

	MyBindingStruct() = default;

	MyBindingStruct(std::string name, int& value, std::pair<char,char>& short_name):name(name), value(value), short_name(short_name){}


	template <std::size_t N>
	auto& get() &{
		if constexpr (N==0) return name;
		if constexpr (N==1) return value;
		if constexpr (N==2) return short_name;
	}

	template <std::size_t N>
	auto&& get() && {
		if constexpr (N==0) return std::forward<decltype(name)>(name);
		if constexpr (N==1) return std::forward<decltype(value)>(value);
		if constexpr (N==2) return std::forward<decltype(short_name)>(short_name);
	}

	std::string name;
	int& value;
	std::pair<char, char>& short_name;
};

namespace std {
	// template<> struct tuple_size<MyBindingStruct>{ static constexpr std::size_t value = 3; };
	// template<> struct tuple_element<0, MyBindingStruct> { using type = std::string; };
	// template<> struct tuple_element<1, MyBindingStruct> { using type = int&; };
	// template<> struct tuple_element<2, MyBindingStruct> { using type = std::pair<char, char>&; };
	template<std::size_t N>
    struct tuple_element<N, MyBindingStruct> {
        using type = decltype(std::declval<MyBindingStruct>().get<N>());
    };
}

template<typename T>
struct TypeResolver;

int main(){
	std::pair<char, char> para {'a', 'b'};
	int k = 5;
	std::string str = "Test";

	MyBindingStruct test(str, k, para);
	std::tuple<std::string, int&, std::pair<char,char>&> test2(str, k, para);

	auto&[a1,b1,c1] = test;
	auto&[a2,b2,c2] = test2;

	// TypeResolver<decltype(a1)>();
	// TypeResolver<decltype(a2)>();

	// TypeResolver<decltype(b1)>();
	// TypeResolver<decltype(b2)>();

	// TypeResolver<decltype(c2)>();
	// TypeResolver<decltype(c1)>();
}