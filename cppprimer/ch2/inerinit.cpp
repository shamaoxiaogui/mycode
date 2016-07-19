#include <iostream>
class test{
public:
    test():_val(2){/*_val=3;*/}
    int _val=1;
};
int main(){
    test t;
    std::cout<<t._val<<std::endl;
    return 0;
}
