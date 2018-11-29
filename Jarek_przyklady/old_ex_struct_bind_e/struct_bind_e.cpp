#include <iostream>
#include <tuple>

class loud{
public:
	loud(){std::cout<<"loud()"<<std::endl;}
	loud(const loud& cpy){std::cout<<"loud() cpy"<<std::endl;}
	~loud(){std::cout<<"~loud()"<<std::endl;}
};

class louds2{
public:
	louds2(){std::cout<<"louds2()"<<std::endl;}
	louds2(const louds2& cpy){std::cout<<"louds2() cpy"<<std::endl;}
	~louds2(){std::cout<<"~louds2()"<<std::endl;}
	loud loud1;
	loud loud2;
};


int main(){
	std::cout<<"---------------tab def"<<std::endl;
	loud tab[2] {loud(), loud()};
	std::cout<<"---------------class def"<<std::endl;
	louds2 louds;
	std::cout<<"---------------tab binding"<<std::endl;
	auto[a,b] = tab;
	std::cout<<"---------------class binding"<<std::endl;
	auto[c,d] = louds;
	std::cout<<"---------------destr"<<std::endl;
}