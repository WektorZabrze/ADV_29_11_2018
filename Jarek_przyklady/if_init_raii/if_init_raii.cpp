#include <iostream>
#include <mutex>
#include <thread>

std::mutex cout_mutex;

void printThreadId(){
	bool success = true;
	if(std::unique_lock<std::mutex> lck(cout_mutex, std::try_to_lock); lck.owns_lock()){
		std::cout <<"Ten napis nie zostal poszatkowany "<< std::this_thread::get_id()<<std::endl;
	}else{
		success = false;
	}
	if(!success){
		printThreadId();
	}
}

int main(){
	std::thread Threads[10];

	for(int i = 0 ; i < 10 ;++i){
		Threads[i] = std::thread(printThreadId);
	}
	for(int i = 0 ; i < 10 ;++i){
		Threads[i].join();
	}

	return 0;
}

