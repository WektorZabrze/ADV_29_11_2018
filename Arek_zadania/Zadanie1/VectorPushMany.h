#pragma once

#include <vector>

template<typename ... Ts>
auto pushManyElementsBack(std::vector<int>& vct, Ts ... args){
	(vct.push_back(args), ...);
	return vct;
}