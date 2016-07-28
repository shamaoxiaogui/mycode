#include <iostream>
using namespace std;
class POD{
public:
    int _val;
    char _ch;
};
class nonPOD{
public:
    nonPOD(int n=0,char ch='c'):_nval(n),_nch(ch){}
private:
    int _nval;
    char _nch;
};
struct Someclass{
    Someclass(){cout<<"Someclass ctor"<<endl;}
    int x=0;
};
struct Someclass2{
    Someclass2(int i=0):x(i){cout<<"ctor"<<endl;}
    Someclass2(const Someclass2&){cout<<"copy ctor"<<endl;}
    int x=2;
};

static int sti=0;
static int sti1=1;
static int sti2;
POD pod;
POD pod1={2,'h'};
nonPOD npod;
nonPOD npod1(3,'g');
int x;
// int x;
// int x;
int main(){
    Someclass sc1;
    Someclass2 sc2={3};
    Someclass *scp=new Someclass;
    POD pod3;
    pod1=pod3;
    cout<<"pod1 val ch: "<<pod1._val<<" "<<pod1._ch<<endl;
    cout<<sti<<endl;
    cout<<sti1<<endl;
    cout<<sti2<<endl;
    cout<<&pod<<endl;
    cout<<&pod1<<endl;
    cout<<&npod<<endl;
    cout<<&npod1<<endl;
    delete scp;
    return 0;
}
