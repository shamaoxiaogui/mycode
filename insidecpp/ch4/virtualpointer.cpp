#include <iostream>
using namespace std;
struct base{
    virtual void func(){cout<<"base func"<<endl;}
    virtual ~base()=default;
};
struct derived:public base{
    void func(){cout<<"drived func"<<endl;}
};
int main(){
    void (base::*bpf)()=&base::func;
    base *bp=new derived;
    (bp->*bpf)();
    delete bp;
    return 0;
}
