#ifndef __MYINT__
#define __MYINT__

#include <iostream>

struct my_int_t {
		my_int_t() {def_const++; }                                              //Default Constructor
		my_int_t(const my_int_t& v) : _val(v._val) {copy_const++;}              //Copy Constructor
		my_int_t(int v) : _val(v) {tfunc++;}                                    //Type Function : int -> my_int_t
		~my_int_t() {destruct++;}                                               //Destructor
		my_int_t& operator = (const my_int_t& rhs){ _val = rhs._val; assign++; return *this; } //Assignment

		bool operator == (const my_int_t& rhs) { equality++; return (_val == rhs._val); }  //Equality
		bool operator != (const my_int_t& rhs) { return !(*this == rhs);    }
		bool operator <  (const my_int_t& rhs) { order++; return (_val < rhs._val);  } //Order
		bool operator >  (const my_int_t& rhs) { return !(*this < rhs) && !(*this == rhs);  }
		bool operator >= (const my_int_t& rhs) { return !(*this < rhs);  }
		bool operator <= (const my_int_t& rhs) { return !(*this > rhs);  }

		//Arithmetic Operations
		my_int_t operator + (const my_int_t& rhs) { plus++;  return my_int_t(_val + rhs._val); }
		my_int_t operator - (const my_int_t& rhs) { minus++; return my_int_t(_val - rhs._val); }
		my_int_t operator * (const my_int_t& rhs) { mul++;   return my_int_t(_val * rhs._val); }
		my_int_t operator / (const my_int_t& rhs) { div++;   return my_int_t(_val / rhs._val); }
		my_int_t operator % (const my_int_t& rhs) { mod++;   return my_int_t(_val % rhs._val); }

		my_int_t& operator ++ (void){ _val++; incr++; return *this;}        //Prefix Increment
		my_int_t& operator ++ (int unused) { _val++; incr++; return *this;} //Postfix Increment


		int    _val;

		//Counters
		static size_t def_const;
		static size_t copy_const;
		static size_t tfunc;
		static size_t destruct;
		static size_t assign;
		static size_t equality;
		static size_t order;
		static size_t incr;
		static size_t plus;
		static size_t minus;
		static size_t mul;
		static size_t div;
		static size_t mod;

		static void dump_stats(const char* tag){
			std::cout 
				<< tag << ", " 
				<< def_const << ", " 
				<< copy_const  << ", "
				<< tfunc  << ", "
				<< destruct  << ", "
				<< assign  << ", "
				<< equality  << ", "
				<< order << ", "
				<< incr  << ","
				<< plus  << ","
				<< minus  << ","
				<< mul  << ","
				<< div  << ","
				<< mod  << ","
				<< std::endl;
		}

		static void stats_header(void){
			std::cout 
				<< "operation" << ", " 
				<< "def_const" << ", " 
				<< "copy_const" << ", "
				<< "tfunc" << ", "
				<< "destruct" << ", "
				<< "assign" << ", "
				<< "equality" << ", "
				<< "order" << ", "
				<< "incr" << ","
				<< "plus"  << ","
				<< "minus"  << ","
				<< "mul"  << ","
				<< "div"  << ","
				<< "mod"  << ","
				<< std::endl;
		}

		static void reset_stats(void){
			def_const  = 0;
			copy_const = 0;
			tfunc      = 0;
			destruct   = 0;
			assign     = 0;
			equality   = 0;
			order      = 0;
			incr       = 0;
			plus       = 0;
			minus      = 0;
			mul        = 0;
			div        = 0;
			mod        = 0;

		}
};

inline
std::ostream&
operator << (std::ostream& os, const my_int_t& rhs) {
	os << rhs._val;
	return os;
}


#endif
