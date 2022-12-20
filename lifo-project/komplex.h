#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
struct komplex
{
    typedef T value_type;
    value_type re;
    value_type im;
    komplex()
    {
        re = 0.0;
        im = 0.0;
    }
    komplex(const value_type &x, const value_type &y)
    {
        re = x;
        im = y;
    }
    komplex(const komplex &x)
    { // copy constructor
        re = x.re;
        im = x.im;
    }

    komplex &operator=(const komplex &x)
    {// assignment operator
        re = x.re;
        im = x.im;
        return *this;
    }
    value_type abs()const 
    {
        return sqrt(re * re + im * im);
    }
};


template <typename T>
inline ostream & operator <<(ostream & s, const komplex<T> & x){
    return s<<x.re<<"  ,  "<<x.im;
}
template <typename T>
inline void print(const komplex<T> & x){
    cout<<x<<endl;
}
#endif