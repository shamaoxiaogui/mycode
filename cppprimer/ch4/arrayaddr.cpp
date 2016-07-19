#include <iostream>
int main(){
    int a[4];
    std::cout<<"int size: "<<sizeof(int)<<std::endl;
    std::cout<<"arr size: "<<sizeof(a)<<std::endl;
    std::cout<<"a[0] addr: "<<&a[0]<<std::endl;
    std::cout<<"a addr: "<<a<<std::endl;
    std::cout<<"&a :"<<&a<<std::endl;
    std::cout<<"&a[0]+1: "<<&a[0]+1<<std::endl;
    std::cout<<"a+1: "<<a+1<<std::endl;
    std::cout<<"&a+1: "<<&a+1<<std::endl;
    return 0;
}
