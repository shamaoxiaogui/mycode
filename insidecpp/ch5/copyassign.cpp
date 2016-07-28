#include <iostream>
using namespace std;
struct base{
    base(){}
    base(const base&){cout<<"base copy ctor"<<endl;}
    base& operator=(const base&){cout<<"base copy assign"<<endl;return *this;}
    virtual ~base(){}
};
struct derivied:public base{
    derivied(){}
    derivied(const derivied&){cout<<"derivied copy ctor"<<endl;}
    derivied& operator=(const derivied&){cout<<"derivied copy assign"<<endl;return *this;}
    virtual ~derivied(){}
};
int main(){
    derivied d1,d2;
    d1=d2;
    derivied d3(d1);
    return 0;
}
