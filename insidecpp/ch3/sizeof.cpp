#include <iostream>
struct X{};
struct Y:public virtual X{};
struct Z:public virtual X{};
struct A:public Y,public Z{};
int main(){
    std::cout<<"X: "<<sizeof(X)<<std::endl;
    std::cout<<"Y: "<<sizeof(Y)<<std::endl;
    std::cout<<"Z: "<<sizeof(Z)<<std::endl;
    std::cout<<"A: "<<sizeof(A)<<std::endl;
    return 0;
}
