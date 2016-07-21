#include <iostream>
using namespace std;
class base{
public:
    base(){vfunc();}
    virtual void vfunc(){cout<<"base n: "<<n<<endl;}
    virtual ~base(){cout<<"d base ";vfunc();}
private:
    int n=0;
};
class d1:public base{
public:
    d1(){vfunc();}
    void vfunc(){cout<<"d1 x: "<<x<<endl;}
    ~d1(){cout<<"d d1";vfunc();}
private:
    int x=1;
};
int main(){
    // d1 d;
    base *bp=new d1;
    delete bp;
    return 0;
}
