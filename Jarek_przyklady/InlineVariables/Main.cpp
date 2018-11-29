#include <iostream>
#include "printArr.h"
#include "include2.h"

void mainPrintArr(){
	std::cout<<"Wypisanie z main: ";
	for(int i = 0; i < arr.size(); ++i){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}

class CountPoint{
public:
	CountPoint(int x=0, int y=0):x(x),y(y){
		instances++;
	}

	~CountPoint(){
		instances--;
	}

	int getInstancesNumber(){
		return instances;
	}

private:
	static inline int instances = 0;
	int x,y;
};

int main(){
	mainPrintArr();
	printArr();

	CountPoint a,b,c;
	std::cout<<c.getInstancesNumber()<<std::endl;
}