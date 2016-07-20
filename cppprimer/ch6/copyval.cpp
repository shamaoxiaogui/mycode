#include <iostream>
class tc{
public:
    tc(){std::cout<<"ctor"<<std::endl;}
    tc(const tc&){std::cout<<"copy"<<std::endl;}
};
tc func1(tc t){
    std::cout<<"in func1"<<std::endl;
    return t;
}
tc& func2(tc& t){
    std::cout<<"in func2"<<std::endl;
    return t;
}
tc func3(tc& t){
    std::cout<<"in func3"<<std::endl;
    return t;
}
int main(){
    tc t1,t2;
    std::cout<<"=========================="<<std::endl;
    t2=func1(t1);
    std::cout<<"=========================="<<std::endl;
    t2=func2(t1);
    std::cout<<"=========================="<<std::endl;
    t2=func3(t1);
}
