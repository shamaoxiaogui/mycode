#include <iostream>
using namespace std;
class c1{
public:
    c1(){cout<<"c1 ctor"<<endl;}
    c1(const c1&){cout<<"c1 copy ctor"<<endl;}
};
class c2{
public:
    c2(){cout<<"c2 ctor"<<endl;}
    c2(const c2&){cout<<"c2 copy ctor"<<endl;}
    virtual ~c2(){}
};
class c3{
public:
    c2 cc2;
    c1 cc1;
    char *str;
};
class c4{
public:
    c4(){cout<<"c4 ctor"<<endl;n=1;}
    c4(const c4&){cout<<"c4 copy ctor"<<endl;}
    c2 cc2;
    c1 cc1;
    int n;
};
int main(){
    c3 cc3;
    cout<<"==========================="<<endl;
    c4 cc4;
    cout<<"==========================="<<endl;
    c4 cc5(cc4);
    cout<<"sizeof c1 "<<sizeof(c1)<<endl;
    cout<<"sizeof c2 "<<sizeof(c2)<<endl;
    return 0;
}
