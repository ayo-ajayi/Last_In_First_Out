#ifndef KOMPLEX_H
#define KOMPLEX_H
#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

template <typename T>
struct komplex
{
    
    typedef T value_type;
    pair<value_type, value_type> kplx;

  komplex() : kplx{0, 0} {}
  komplex( value_type r) : kplx{r, 0} {  }
  komplex(value_type r, value_type i) : kplx{r, i} {  }

  // copy constructor
  komplex(const komplex & x) : kplx{x.kplx} {  }

  ~komplex() {  }

  // assignment operator
  komplex & operator =( const komplex & b) {
    kplx = b.kplx;
    return *this;
  }

  value_type & re() {
    return kplx.first;
  }
  value_type & im() {
    return kplx.second;
  }
  value_type abs() const {
    return sqrt(kplx.first*kplx.first+kplx.second*kplx.second);
  }
};


template <typename T>
inline ostream & operator <<(ostream & s, const komplex<T> & x){
    return s<<x.kplx.first<<"  ,  "<<x.kplx.second;
}
template <typename T>
inline void print(const komplex<T> & x){
    cout<<x<<endl;
}
#endif
