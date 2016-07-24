#include <iostream>
#include <cstdio>
struct sc{
    virtual void func(){}
    char ch;
    int x;
};
int main(){
    sc scc;
    printf("&scc.ch %p\n",&scc.ch);
    printf("&scc.x %p\n",&scc.x);
    printf("sc::ch %p\n",&sc::ch);
    printf("sc::x %p\n",&sc::x);
    return 0;
}
