#include <iostream>
struct abase{
    virtual ~abase()=0;     //Oops, pure virtual dctor must be defined, or there would be a link error
    virtual void func()=0;
    virtual void func1()=0;
protected:
    abase(char c=0):_ch(c){}
    char _ch;
};
abase::~abase(){std::cout<<"abase dctor"<<std::endl;}
struct derivied:public abase{
    void func(){}
    void func1(){}
    void func3(){}
};
int main(){
    derivied d;
    return 0;
}
