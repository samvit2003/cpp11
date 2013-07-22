#ifndef __MYTYPE_H__
#define __MYTYPE_H__

#include <iostream>

template<typename T>
struct my_type_t {

        //Constructors, Destructor
        my_type_t() {def_const++; }
        my_type_t(const my_type_t& v) : _val(v._val) {copy_const++;}
        explicit my_type_t(T v) : _val(v) {tfunc++;}
        ~my_type_t() {destruct++;}

        //Assignment
        my_type_t& operator = (const my_type_t& rhs){ _val = rhs._val; assign++; return *this; }

        //Equality
        bool operator == (const my_type_t& rhs) const { equality++; return (_val == rhs._val); }
        bool operator != (const my_type_t& rhs) const { return !(*this == rhs); }

        //Order
        bool operator <  (const my_type_t& rhs) const { order++; return (_val < rhs._val);  }
        bool operator <= (const my_type_t& rhs) const { return (*this < rhs) || (*this == rhs);  }
        bool operator >  (const my_type_t& rhs) const { return !(*this <= rhs); }
        bool operator >= (const my_type_t& rhs) const { return !(*this < rhs);  }

        //Arithmetic Operations
        my_type_t operator + (const my_type_t& rhs) const { plus++;  return my_type_t(_val + rhs._val); }
        my_type_t operator - (const my_type_t& rhs) const { minus++; return my_type_t(_val - rhs._val); }
        my_type_t operator * (const my_type_t& rhs) const { mul++;   return my_type_t(_val * rhs._val); }
        my_type_t operator / (const my_type_t& rhs) const { div++;   return my_type_t(_val / rhs._val); }
        my_type_t operator % (const my_type_t& rhs) const { mod++;   return my_type_t(_val % rhs._val); }

        //Increment, Decrement
        my_type_t& operator ++ (void){ _val++; incr++; return *this;}
        my_type_t& operator ++ (T unused) { _val++; incr++; return *this;}
        my_type_t& operator -- (void){ _val--; decr++; return *this;}
        my_type_t& operator -- (T unused) { _val--; decr++; return *this;}


        T    _val;

        //Counters
        static size_t def_const;
        static size_t copy_const;
        static size_t tfunc;
        static size_t destruct;
        static size_t assign;
        static size_t equality;
        static size_t order;
        static size_t incr;
        static size_t decr;
        static size_t plus;
        static size_t minus;
        static size_t mul;
        static size_t div;
        static size_t mod;

        static void dump_stats(const char* tag){
            std::cout 
                << tag << "," 
                << def_const << "," 
                << copy_const  << ","
                << tfunc  << ","
                << destruct  << ","
                << assign  << ","
                << equality  << ","
                << order << ","
                << incr  << ","
                << decr  << ","
                << plus  << ","
                << minus  << ","
                << mul  << ","
                << div  << ","
                << mod  << ","
                << (def_const + copy_const + tfunc) - destruct  << ","
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
                << "decr" << ","
                << "plus"  << ","
                << "minus"  << ","
                << "mul"  << ","
                << "div"  << ","
                << "mod"  << ","
                << "check"  << ","
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
            decr       = 0;
            plus       = 0;
            minus      = 0;
            mul        = 0;
            div        = 0;
            mod        = 0;

        }
};

template<typename T> size_t my_type_t<T>::def_const;
template<typename T> size_t my_type_t<T>::copy_const;
template<typename T> size_t my_type_t<T>::tfunc;
template<typename T> size_t my_type_t<T>::destruct;
template<typename T> size_t my_type_t<T>::assign;
template<typename T> size_t my_type_t<T>::equality;
template<typename T> size_t my_type_t<T>::order;
template<typename T> size_t my_type_t<T>::incr;
template<typename T> size_t my_type_t<T>::decr;
template<typename T> size_t my_type_t<T>::plus;
template<typename T> size_t my_type_t<T>::minus;
template<typename T> size_t my_type_t<T>::mul;
template<typename T> size_t my_type_t<T>::div;
template<typename T> size_t my_type_t<T>::mod;

template<typename T>
std::ostream&
operator << (std::ostream& os, const my_type_t<T>& rhs) {
    os << rhs._val;
    return os;
}

#endif
