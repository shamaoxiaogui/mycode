#include <iostream>
int main(){
    const int i=1;
    int *j=const_cast<int*>(&i);
    *j=2;
    std::cout<<"i addr "<<&i<<" val "<<i<<std::endl;
    std::cout<<"j addr "<<j<<" val "<<*j<<std::endl;
    return 0;
}
