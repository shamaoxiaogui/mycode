#include <iostream>
#include <thread>
using namespace std;
class X{
public:
    X(int &n):i(n){}
    X(const X& x):i(x.i){cout<<"copy ctor"<<endl;}
    void operator()(){
        cout<<"func...."<<endl;
        for(int j=0;j<3;++j){
            cout<<i++<<endl;
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
private:
    int &i;
};

void test(){
    int n=1;
    X x(n);
    thread t(x);
    t.detach();
}
void func2(){
    int n=99;
    cout<<"func2 "<<n<<endl;
}
int main(){
    // test();
    // func2();
    int n=1;
    thread t(X{n});
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout<<"main end"<<endl;
    cout<<t.joinable()<<endl;
    // t.detach();
    t.join();
    return 0;
}
