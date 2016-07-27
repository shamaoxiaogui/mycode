#include <iostream>
using namespace std;
struct base{
    virtual base* func(){cout<<"base func"<<endl;return this;}
    virtual const base* func()const{cout<<"const base func"<<endl;return this;}
    virtual ~base(){}
};
struct derived:public base{
    virtual derived* func() override {cout<<"derivied func"<<endl;return this;}
    virtual const derived* func()const override {cout<<"const derivied func"<<endl;return this;}
};
int main(){
    base *bp=new derived;
    bp->func();
    const base *cbp=bp;
    cbp->func();
    delete bp;
    return 0;
}
