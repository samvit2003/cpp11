#include <iostream>

bool is_prime(int i){
	for(int p=2;  p*p <= i ; p++){
		if(i%p == 0){
			return false;
		}
	}
	return true;
}


int main ()
{

	for(int i = 1; i <= 100; i++){
		if(is_prime(i))
			std::cout << i << ",";
	}
	std::cout << "\n";
}
