struct SimpleSingleton{

	static auto instance(){
		static SimpleSingleton instance;
		return instance;
	}

private:
	SimpleSingleton(){};
	int value_1;
	int value_2;
};

void noerror(){
	#if 0
		SimpleSingleton();
	#endif
}

void error(){
	if constexpr(false){
		//SimpleSingleton();
	} 
	else{
		SimpleSingleton a = SimpleSingleton::instance();
	}
}


int main(){
	return 0;
}