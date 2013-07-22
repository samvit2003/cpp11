#include "my_type.h"
#include <vector>

typedef my_type_t<int>    my_int_t;

my_int_t operator "" _mi(unsigned long long i){
	return my_int_t{static_cast<int>(i)};
}


//Version-0
bool is_prime_0(my_int_t i){
        for(my_int_t p=2_mi;  p*p <= i ; p++){
                if(i%p == 0_mi)
                        return false;
        }
        return true;
}

//Version-1
bool is_prime_rec(my_int_t i, my_int_t factor=2_mi){
    if(factor*factor <= i){
        if(i % factor == 0_mi){
            return false;
        }else{
            return is_prime_rec(i,factor+1_mi);
        }
    }else{
        return true;
    }
}

bool is_prime_1(my_int_t i){
        return is_prime_rec(i);
}

//Version-2
bool is_prime_rec_2(my_int_t i, int n, std::vector<my_int_t>& inprimes){
    my_int_t factor = my_int_t{inprimes[n]};
    if (factor*factor > i){
        return true;
    }else if(i % factor == 0_mi){
        return false;
    }else{
           return is_prime_rec_2(i,n+1,inprimes);
    }
}

bool is_prime_2(my_int_t i){
        static std::vector<my_int_t> primes = { 2_mi };
        bool result = is_prime_rec_2(i,0,primes);
        if(result == true){
                primes.push_back(i);
        }
        return result;
}

//Helper class to run the algorithms
struct check_prime_t{
        public:
                typedef bool (*prime_func_t) (my_int_t);

                check_prime_t(const char* _tag, int _max, prime_func_t _func) : tag(_tag), max(_max), func(_func), numprimes(0){
                        my_int_t::reset_stats();

                        std::cout << "Exec(" << tag << "),";
                        for(int i = 2; i <= max; i++){
                                if(func(my_int_t{i})){
                                        std::cout << i << ",";
					numprimes++;
				}
                        }
                        std::cout << "\n";
                }

                ~check_prime_t(){
                        my_int_t::dump_stats(tag);
                }


                check_prime_t() = delete;
                check_prime_t(const check_prime_t&) = delete;
                check_prime_t& operator = (const check_prime_t&) = delete;
        private:
                const char*        tag;
                const int          max;
                const prime_func_t func;
		int                numprimes;
};



int main ()
{

    my_int_t::stats_header();

    constexpr size_t maxnum = 10000;
    check_prime_t("isprime",       maxnum, is_prime_0);
    check_prime_t("isprimerec",    maxnum, is_prime_1);
    check_prime_t("isprimerecmod", maxnum, is_prime_2);
}
