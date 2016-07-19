#include <iostream>
int main(){
    int val;
    while(std::cin>>val){
        std::cout<<val<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"after loop,val= "<<val<<std::endl;
    return 0;
}
