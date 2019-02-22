#pragma once
#include <iostream>

template<typename T = double>
struct Difference
{
	template<typename ... Ts>
	void leftToRight(Ts ... args){
		value =  (... - args);
	}

	template<typename ... Ts>
	void leftToRightFromZero(Ts ... args){
		value = (0 - ... - args);
	}

	friend std::ostream& operator<<(std::ostream& os, const Difference& to_print){
		os<<to_print.value;
		return os;
	}

private:
	T value;
};