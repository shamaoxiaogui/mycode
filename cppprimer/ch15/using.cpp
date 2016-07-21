#include <iostream>
class base{
public:
    void func(){std::cout<<"bfunc"<<std::endl;}
    void func(int n){std::cout<<"bfunc2"<<std::endl;}
    int x=0;
};
class d1:public base{
public:
    using base::func;
    void func(){std::cout<<"dfunc"<<std::endl;}
    using base::x;
    int x=1;
};
int main(){
    d1 d;
    d.func();
    d.func(3);
//    std::cout<<"d.x="<<d.x<<std::endl;    //二义性错误
    return 0;
}
