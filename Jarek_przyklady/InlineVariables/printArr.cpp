#include <iostream>
#include "include1.h"

void printArr(){
	std::cout<<"Wypisanie z printArr.h: ";
    for(int i = 0; i < arr.size(); ++i){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}