#include <iostream>
#include <thread>
using namespace std;
void func(){cout<<"from thread!"<<endl;}

int main(){
    thread t(func);
    t.join();
    t.join();   //error terminate!!
    cout<<"double join"<<endl;
    return 0;
}
