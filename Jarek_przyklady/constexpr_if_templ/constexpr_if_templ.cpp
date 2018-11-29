#include <iostream>
#include <string>
#include <array>
#include <type_traits>

template<unsigned N>
int fibonacci(){
	if constexpr(N<2) return N;
	else{
		return fibonacci<N-1>() + fibonacci<N-2>();
	}
}

struct MyClass{

	MyClass(int value = 5, char letter = 'c', std::string name = "MyClass"):value(value),letter(letter),name(name){};

	int value;
	char letter;
	std::string name;
};

template<unsigned I>
auto& get(MyClass& c){
	if constexpr(I == 0)
		return c.value;
	else if constexpr(I==1)
		return c.letter;
	else
		return c.name;
}

template <typename T>
auto get_pure_value(T val){
	if constexpr(std::is_pointer_v<T>){
		std::cout<<"Jest wskaznikiem"<<std::endl;
		return *val;
	}
	else if constexpr(std::is_reference_v<T>){
		std::cout<<"Jest referencją"<<std::endl;
		return val;
	}
	else {
		std::cout<<"Jest wartością"<<std::endl;
		return val;
	}
}

int main(){
	std::cout<<"fibonacci<5>(): "<<fibonacci<5>()<<std::endl;

	MyClass a;

	std::cout<<"get<0>(a): "<<get<0>(a)<<std::endl;
	std::cout<<"get<1>(a): "<<get<1>(a)<<std::endl;
	std::cout<<"get<2>(a): "<<get<2>(a)<<std::endl;

	int val = 4;
	int& ref = val;
	int* ptr = &val;

	get_pure_value(val);
	get_pure_value<int&>(ref);
	get_pure_value(ptr);
}