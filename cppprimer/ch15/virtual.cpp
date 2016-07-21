#include <iostream>
class base{
public:
    virtual int func(){std::cout<<"base v"<<std::endl;}
};
class d1:public base{
public:
    int func(int n){std::cout<<"d1 func"<<std::endl;}
};
int main(){
    d1 *dp=new d1;
    base *bp=dp;
    bp->func();     //调用的是base的虚函数func
    //dp->dunc();     //编译错误，因为对d1而言，base的虚函数func被d1的func(int)隐藏了
    delete bp;
    return 0;
}
