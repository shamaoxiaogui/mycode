#include <iostream>
#include <initializer_list>
class tc{
public:
    tc(){std::cout<<"tc ctor"<<std::endl;}
    tc(const tc&){std::cout<<"tc copy"<<std::endl;}
};
void testfunc(const std::initializer_list<const tc> tl){
    std::cout<<"list has "<<tl.size()<<" tc"<<std::endl;
}
int main(){
    tc t1,t2,t3;
    testfunc({t1,t2,t3});
    return 0;
}
