#include <iostream>
struct statictest{
    // static void func1(){n=3;}
    // static void func2()const {}
    // virtual void func(){}
    // void func3(){this=NULL;};
    // void func4()const{this->n=10;};
    // virtual ~statictest(){}
    // static void hehe()const{std::cout<<"static func"<<std::endl;}
    // static void hehe()volatile{std::cout<<"static func"<<std::endl;}
    // static virtual void hehe(){std::cout<<"static func"<<std::endl;}
    static void hehe(){std::cout<<"static func"<<std::endl;}
    statictest& func(){std::cout<<"func run"<<std::endl;return *this;}
private:
    int n;
    // int &x=n;
};
int main(){
    statictest st;
    st.func().hehe();
    // st.func4();
    return 0;
}
