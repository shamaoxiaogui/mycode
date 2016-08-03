#include <iostream>
#include <thread>
#include <vector>
#include <unistd.h>
#include <mutex>
using namespace std;
mutex some_mutex;
void func(const int &i){
    sleep(2);
    lock_guard<mutex> guard(some_mutex);
    cout<<"thread "<<i<<" say hello!\n";
}
int main(){
    cout<<"hardware concurrent: "<<thread::hardware_concurrency()<<endl;
    vector<thread> vt;
    for(int i=0;i<10;++i){
        vt.push_back(thread(func,i));
    }
    for_each(vt.begin(),vt.end(),mem_fn(&thread::join));
    return 0;
}
