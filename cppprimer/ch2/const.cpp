#include <iostream>
#include <string>
void func(std::string &s){
    std::cout<<s<<std::endl;
}
void func2(const std::string &s){
    std::cout<<s<<std::endl;
}
int main(){
    // func("hehe!");  //error
    func2("hehe!");
    return 0;
}
