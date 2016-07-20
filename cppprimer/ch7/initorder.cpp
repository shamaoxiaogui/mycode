#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
class member{
public:
    member(int n):m(n){cout<<"member "<<m<<" ctor"<<endl;}
    ~member(){cout<<"member "<<m<<" dctor"<<endl;}
private:
    int m; 
};
class grandpa{
public:
    grandpa(const string& n="G"):name(n){cout<<"grand "<<name<<" ctor"<<endl;}
    ~grandpa(){cout<<"grand "<<name<<" dctor"<<endl;}
private:
    string name;
};
class father:public grandpa{
public:
    father(const string& n="F"):name(n){cout<<"father "<<name<<" ctor"<<endl;}
    ~father(){cout<<"father "<<name<<" dctor"<<endl;}
private:
    string name;
};
class child:public father{
public:
    child(const string& n="C"):m1(1),m2(2),m3(3),name(n){cout<<"child "<<name<<" ctor"<<endl;}
    ~child(){cout<<"child "<<name<<" dctor"<<endl;}
private:
    string name;
    static member m4;
    member m1,m2,m3;
};
member child::m4(4);
member m5(5);
int main(){
    child ch;
    return 0;
}
