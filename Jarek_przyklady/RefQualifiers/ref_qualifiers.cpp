#include <ctype.h>
#include <iostream>
#include <string>

struct EvenToUpper{
	
	EvenToUpper(std::string toConvert = "Even to upper"):toConvert(toConvert){_convert();}

	std::string convert() &{
		std::cout<<"Convert dla lref"<<std::endl;
		return toConvert;
	}

	std::string convert() &&{
		std::cout<<"Convert dla rref"<<std::endl;
		return std::move(toConvert);
	} 

private:

	void _convert(){
		int i = 0;
		while(toConvert[i]){
			toConvert[i] = toupper(toConvert[i]);
			i+=2;
		}
	}

	std::string toConvert;
};

int main(){
	EvenToUpper a;
	std::cout<<a.convert()<<std::endl;
	std::cout<<EvenToUpper("Tutaj nastapilo wywolanie dla rref").convert()<<std::endl;
}