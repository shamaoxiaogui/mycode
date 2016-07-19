#include <iostream>
#include <string>
#include <vector>
class tc{
public:
    tc(){std::cout<<"ct a class! "<<std::endl;}
    tc(const tc &t){std::cout<<"copy a class!"<<std::endl;}
    tc& operator=(tc &t){std::cout<<"= a class!"<<std::endl; return *this;}
};
int main(){
    tc t1;
    std::cout<<"==============="<<std::endl;
    tc t2(t1);
    std::cout<<"==============="<<std::endl;
    tc t3=t1;
    std::cout<<"==============="<<std::endl;
    tc t4{t1};
    std::cout<<"==============="<<std::endl;
    tc t5={t1};
    std::cout<<"==============="<<std::endl;
    std::vector<tc> tcv{t1,t2,t3};
    return 0;
}
