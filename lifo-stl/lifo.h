#ifndef LIFO_H
#define LIFO_H

#include <iostream>
#include "komplex.h"
#include <stdexcept>
using namespace std;

template <typename T>
class lifo
{
public:
typedef T value_type;
typedef const value_type * const_iter;

private:
    int cap;
    int siz;
    value_type *store;

public:
    lifo() = delete;
    lifo(int c) : cap(c), siz(0), store(new value_type[cap]) {}

    // copy  constructor for lifos
    lifo(const lifo &x) : cap(x.cap), siz(x.siz), store(new value_type[cap])
    {
        int i = 0;
        while (i < siz)
        {
            store[i] = x.store[i];
            i++;
        }
    }
    // assignment of lifo
    lifo &operator=(const lifo &x)
    {
        if (cap != x.cap)
        {
            delete[] store;
            cap = x.cap;
            store = new value_type[cap];
        }
        siz = x.siz;
        int i = 0;
        while (i < siz)
        {
            store[i] = x.store[i];
            i++;
        }
        return *this;
    }
    ~lifo()
    {
        delete[] store;
    }
    void push(const value_type &x)
    {
        if (full())
            throw overflow_error("lifo is full");
        store[siz] = x;
        siz++;
    }
    const value_type &pop()
    {
        if (empty())
            throw underflow_error("lifo is empty");
        siz--;
        return store[siz];
    }
    bool full() const { return siz == cap; }
    bool empty() const { return siz == 0; }
    int capacity() const { return cap; }
    int size() const { return siz; }
    
    //array access operator
    value_type operator[](int i)const{
        return store[i];
    }
    const_iter begin()const{
        return store;
    }
    const_iter end()const{
        return store+siz;
    }

};

template <typename T>
inline void print_state(const lifo<T> & stack) {

  if (stack.empty()) {
    cout << "Stack is empty.\n";
  }

  if (stack.full()) {
    cout << "Stack is full.\n";
  }

  if (!stack.empty() && !stack.full()) {
    cout << "Stack is neither empty nor full.\n";
  }
}

template <typename T>
inline void fill(lifo<T> & stack, const typename lifo<T>::value_type & z) {

  while (!stack.full()) {
    print_state(stack);
    stack.push(z);
  }

  print_state(stack);
}

template <typename T>
inline ostream & operator <<(ostream &s , const lifo<T> & l){
    for(typename lifo<T>::value_type & ele: l)s<<ele<<" "; //or for(auto & ele: l)s<<ele<<" ";
    return s;
}

#endif