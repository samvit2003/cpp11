#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>

#include "my_type.h"

my_int_t genmi (void)
{
	static std::random_device               rd;
	static std::mt19937                     gen(rd());
	static std::uniform_int_distribution<>	dis(1,1000);

	return my_int_t{dis(gen)};
}




int main()
{
    	my_int_t::stats_header();
        my_int_t::reset_stats();

	std::vector<my_int_t> num(100);

	std::iota(num.begin(), num.end(), 1_mi); 
	num.push_back(1001_mi);
	std::cout << "Exec(iota),";
	std::copy(num.begin(), num.end(), std::ostream_iterator<my_int_t>(std::cout,","));
       	std::cout << "\n";

	std::generate(num.begin(), num.end(), genmi);
	std::cout << "Exec(generate),";
	std::copy(num.begin(), num.end(), std::ostream_iterator<my_int_t>(std::cout,","));
       	std::cout << "\n";

        my_int_t::dump_stats("stlfun");

	return 0;
}
