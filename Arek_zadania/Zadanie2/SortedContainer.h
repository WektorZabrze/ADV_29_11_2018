#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

template<typename T, typename Comp = std::less<T>>
struct SortedContainer{
	SortedContainer() = default;

	template<typename Iter>
	SortedContainer(Iter begin, Iter end, Comp comp = Comp()){
		for(begin; begin!=end; ++begin){
			data.insert(std::upper_bound(data.begin(), data.end(), *begin ,comp), *begin);
		}
	}

	void print(){
		for(auto it = data.begin(); it!=data.end(); ++it){
			std::cout<<(*it)<<" ";
		}
		std::cout<<std::endl;
	}

private:
	std::vector<T> data;
	
};
template<typename Iter, typename Comp = std::less<typename std::iterator_traits<Iter>::value_type>>
SortedContainer(Iter begin, Iter end, Comp = Comp()) -> SortedContainer<typename std::iterator_traits<Iter>::value_type, Comp>;