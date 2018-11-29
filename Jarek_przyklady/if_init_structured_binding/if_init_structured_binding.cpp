#include <iostream>
#include <map>

int main(){
	
	std::map<int, std::string> mapa;
	for(int i = 0; i < 100; ++i){
		if(i%2){
			mapa.insert({i, "ODD"});
		}else{
			mapa.insert({i, "EVEN"});
		}
	}

	for(auto item : mapa){
		if(auto[first, second] = item; second=="EVEN"){
			std::cout<<"Parzysty indeks: "<<first<<std::endl;
		}else{
			std::cout<<"Nieparzysty indeks:"<<first<<std::endl;
		}
	}

	return 0;
}
