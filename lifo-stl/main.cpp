#include <iostream>
#include <stdexcept>
#include "komplex.h"
#include <vector>
using namespace std;
typedef komplex<double> dkomplex;
int main(){
    vector<dkomplex> stack;

   for(int i=0; i<10;i++){
     stack.push_back(dkomplex(i,i));
     cout<<"i= "<<i<<endl;
     cout<<"cap is: "<<stack.capacity()<<endl;
    cout<<"size is: "<<stack.size()<<endl;

    }
    cout<<"cap is: "<<stack.capacity()<<endl;
    cout<<"size is: "<<stack.size()<<endl;

    for(auto & elem :stack){
        cout<<elem.re()<<" , "<<elem.im()<<endl;
    }
    cout<<"cap is: "<<stack.capacity()<<endl;
    cout<<"size is: "<<stack.size()<<endl;
    return 0;
}

