#include <iostream>
#include <string>
#include <vector>
#include "pretty_print.h"

struct employee{
	uint m_id;
	std::string m_name;
	std::string m_position;
	double m_salary;
};


int main(){
	std::vector employees {employee{1,"Jacek", "Kierowca", 2900.0}, employee{2,"Wojtek", "Spawacz", 3250.0}, employee{3,"Arian", "Kierownik", 4250.0}};

	for(auto[id,name,position,salary] : employees){
		pretty_print(id,name,position,salary);
	}

	std::cout<<std::endl;

	for(auto item : employees){
		pretty_print(item.m_id, item.m_name, item.m_position, item.m_salary);
	}
	
	std::cout<<std::endl;

	//-----------------------------------------------

	auto [first, second] = std::pair{std::pair{"1st1st", "1st2nd"}, "2nd"};
	auto [first1, first2] = first;


	std::cout<<"first.first:"<<first.first<<" |first.second:"<<first.second<<" |second:"<<second<<std::endl;
	std::cout<<first1<<" "<<first2<<std::endl;
}
