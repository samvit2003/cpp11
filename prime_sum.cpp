#include <iostream>
#include <algorithm>
#include <vector>


inline
bool is_prime(int x){
	for(int i=2; i*i <= x; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

inline
std::ostream&
operator << (std::ostream& os, const std::pair<int,int>& p){
	os << p.first+p.second << "(" << p.first << "+" << p.second << ")";
	return os;
}

int
main()
{
	try{

		constexpr int N = 20;
		std::vector<int> numbers(N);
		std::iota(numbers.begin(), numbers.end(), 1);
		std::cout << "Input numbers: 1 ... " << N << "\n";
		//DEBUG: std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout,",")); std::cout << "\n";

		//Map-Reduce Pattern..C++ STL Style (accumulate + for_each)
		typedef std::vector<std::pair<int,int>> result_type;
		result_type result;
		std::accumulate(numbers.begin(), numbers.end(), std::ref(result), 
				 [] (result_type& list, int i) -> result_type& 
				     {
				 	std::vector<int>  temp(i-1);
					std::iota(temp.begin(), temp.end(), 1);
					std::for_each (temp.begin(), temp.end(), 
						  [i,&list] (int j) -> void {
						  	if(is_prime(i+j)){
						  		list.push_back(std::make_pair(j,i));
							}
						  }
						);
					return list;
				 });

		//PRINT RESULT (Check why this doesn't work with std::copy)
		std::cout << "\nResult:\n";
		for(auto i=result.begin(); i != result.end(); i++){
			std::cout << *i << ", ";
		}
		std::cout << "\n";

		return 0;
	}catch(std::exception& e){
		std::cout << e.what() << std::endl;
		return 1;
	}
}
