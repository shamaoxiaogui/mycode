#include <iostream>
class noaggregate{
    int x;
};
struct aggregate{};
struct noaggregate1{
    noaggregate1(){};
    int n;
};
struct aggregate1{
    aggregate1& operator=(const aggregate&){return *this;}
    ~aggregate1(){}
    double d;
private:
    static int hehe;
};
int main(){
    // noaggregate ng={1}; //err: no matching ctor
    noaggregate ng; //ok
    // noaggregate1 ng1={2};//err: no matching ctor
    noaggregate1 ng1; //ok
    aggregate1 ag1={3.14}; //ok
    return 0;
}
