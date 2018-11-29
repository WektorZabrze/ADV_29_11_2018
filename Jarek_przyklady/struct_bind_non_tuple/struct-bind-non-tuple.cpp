#include <iostream>
#include <type_traits>

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

	void print(){
		std::cout<<"I am a Screamer!!!"<<std::endl;
	}
};

struct ScreamerArr3{
	ScreamerArr3(){
		std::cout<<"ScreamerArr3();"<<std::endl;
	}
	~ScreamerArr3(){
		std::cout<<"~ScreamerArr3();"<<std::endl;
	}
	ScreamerArr3(const ScreamerArr3& to_cpy):first(to_cpy.first),second(to_cpy.second),third(to_cpy.third){
		std::cout<<"CPY ScreamerArr3();"<<std::endl;
	}

	Screamer first;
	Screamer second;
	Screamer third;
};

int main(){
	std::cout<<"------Utworzenie obiektu typu ScreamerArr3"<<std::endl;
	ScreamerArr3 arr;
	std::cout<<std::endl<<"------auto[a,b,c] = ScreamerArr3"<<std::endl;
	auto[a,b,c] = arr;
	std::cout<<std::endl<<"------auto&[d,e,f] = ScreamerArr3"<<std::endl;
	auto&[d,e,f] = arr;
	std::cout<<"Czy typ d to Screamer: "<<std::is_same<decltype(d), Screamer>::value<<std::endl;
	std::cout<<std::endl<<"------Print dla a,b,c"<<std::endl;
	a.print();
	b.print();
	c.print();
	std::cout<<std::endl<<"------Destruktory"<<std::endl;
}