#include <iostream>
#include <stdexcept>
#include "komplex.h"
#include "lifo.h"
using namespace std;
typedef komplex<double> dkomplex;
int main(){
    dkomplex x(1.2, 2.3);
    lifo<dkomplex> stack(3);
    print_state(stack);
    try{
        fill(stack, x);
        print_state(stack);
        stack.push(x);
    }catch(const overflow_error & e){
        cerr<<"overflow error occurred: "<<e.what()<<endl;
    }catch(const underflow_error & e){
        cerr<<"underflow error occurred: "<<e.what()<<endl;
    }
    print_state(stack);
    return 0;
}