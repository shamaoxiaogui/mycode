#include <iostream>
using namespace std;
class father{
public:
    father(){cout<<"father ctor"<<endl;}
    father(int x){cout<<"father ctor2"<<endl;}
};
class son:public father{
public:
    int n;
};
class son2:public father{
public:
    son2(int x):father(2){n=x;cout<<"son2 ctor"<<endl;}
    int n;
};
int main(){
    son s;
    cout<<"===================="<<endl;
    // son2 s2; //error
    cout<<"===================="<<endl;
    son2 s3(3);
    return 0;
}
