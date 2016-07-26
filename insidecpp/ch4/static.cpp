#include <iostream>
struct statictest{
    // static void func1(){n=3;}
    // static void func2()const {}
    // void func3(){this=NULL;};
    // void func4()const{this->n=10;};
private:
    int n=0;
    int &x=n;
};
int main(){
     statictest st;
    // st.func4();
    return 0;
}
