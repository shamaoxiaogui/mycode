#include <iostream>
#include <thread>
void hello(){
    std::cout<<"hello concurrent world!!"<<std::endl;
}
int main(){
    std::cout<<"hello world, let's get concurrent!!"<<std::endl;
    std::thread t(hello);
    t.join();
    return 0;
}
