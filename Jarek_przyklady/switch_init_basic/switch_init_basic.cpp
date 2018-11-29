#include <iostream>
#include <fstream>
#include <limits>

void move_left(){
	std::cout<<"Ruch w lewo"<<std::endl;
}

void move_right(){
	std::cout<<"Ruch w prawo"<<std::endl;
}

void move_up(){
	std::cout<<"Ruch w gore"<<std::endl;
}

void move_down(){
	std::cout<<"Ruch w dol"<<std::endl;
}

void invalid(){
	std::cout<<"Zly input"<<std::endl;
}

int main(){
	while(true){
		switch(char c(getchar()); c){
			case 'w': move_up(); break;
			case 'a': move_left(); break;
			case 'd': move_right(); break;
			case 's': move_down(); break;
			default: invalid(); return 0;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		std::cin.clear();
	}
}