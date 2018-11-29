#include <iostream>
#include <map>

int main(){
	std::map<int, char> map;
	map[1] = 'a';
	map[2] = 'b';

	if(auto ret = map.insert({1,'c'}); ret.second){
		std::cout<<"Added "<< ret.first->second <<" with index "<< ret.first->first << std::endl;
	}else{
		std::cout<<"index "<< ret.first->first <<" already exists value: " << ret.first->second << std::endl;
	}

	if(auto ret = map.insert({3,'c'}); ret.second){
		std::cout<<"Added "<< ret.first->second <<" with index "<< ret.first->first << std::endl;
	}else{
		std::cout<<"index "<< ret.first->first <<" already exists value: " << ret.first->second << std::endl;
	}

	return 0;
}