#include <iostream>
int main(){
    char *str="heheda!";
    std::cout<<"before m: "<<str<<std::endl;
    str[3]='a';
    std::cout<<"after m: "<<str<<std::endl;
    return 0;
}
