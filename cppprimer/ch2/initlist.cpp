#include <iostream>
#include <string>
#include <vector>
class tc{
public:
    tc(const std::string &s="hehe"):str(s){std::cout<<s<<" ct a class! "<<std::endl;}
    tc(const char *s):str(s){std::cout<<s<<" ct a class! "<<std::endl;}
    tc(const tc &t){std::cout<<"copy a class!"<<std::endl;}
    tc(tc &&t){std::cout<<"move a class!"<<std::endl;}
    tc& operator=(const tc &t){std::cout<<"= a class!"<<std::endl; return *this;}
    tc& operator=(tc &&t){std::cout<<"move = a class!"<<std::endl; return *this;}
    std::string str;
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
    std::cout<<"==============="<<std::endl;
    std::vector<tc> tcv2{"t1","t2","t3"};
    std::cout<<"==============="<<std::endl;
    std::vector<tc> tcv3{std::move(t1),std::move(t2),std::move(t3)};
    return 0;
}
