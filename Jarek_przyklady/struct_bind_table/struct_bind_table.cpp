#include <iostream>

struct Screamer{
	Screamer(){
		std::cout<<"Screamer();"<<std::endl;
	}
	~Screamer(){
		std::cout<<"~Screamer();"<<std::endl;
	}
	Screamer(const Screamer&){
		std::cout<<"CPY Screamer();"<<std::endl;
	}
	Screamer(Screamer&&){
		std::cout<<"MOVE Screamer();"<<std::endl;
	}
	Screamer& operator=(const Screamer&){
		std::cout<<"Assign operator for Screamer"<<std::endl;
		return *this;
	}
	Screamer& operator=(Screamer&&){
		std::cout<<"Move assign operator for Screamer"<<std::endl;
		return *this;
	}
};

int main(){
	std::cout<<"-------Tablica dwóch obiektów 'Screamer'"<<std::endl;
	Screamer table[2];
	std::cout<<"-------auto [x,y] = table;"<<std::endl;
	auto [x,y] = table;
	std::cout<<"-------auto& [xr,yr] = table;"<<std::endl;	
	auto& [xr,yr] = table;
	std::cout<<"-------Destruktory"<<std::endl;
	//auto[a,b,c] = table; // nie skompiluje sie poniewaz ilosc elementow tablicy jest za mala
}