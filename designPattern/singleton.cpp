//simple way
#include <iostream>
using namespace std;
class singleton{
public:
    static singleton& instance(){
        static singleton _instance;
        return _instance;
    }
private:
    singleton(){cout<<"ctor!"<<endl;}
    singleton(const singleton&);
    void operator=(const singleton&);
    ~singleton(){cout<<"dctor!"<<endl;}  //关于析构函数是否应该是private的。如果析构是private的，那么就可以防止用户写出如下的代码：
    //singleton st=singleton::instance();
    //delete &st;
    //虽然单文件写出这种代码的可能性不大，但是多文件复杂接口时确实有可能。所以要不把析构函数定义为private，要不就重载取地址运算。
};
template<typename T>
class singleton2{
public:
    static T& instance(){
        static T _instance;     //but we can only use default ctor of T, or specific one, how about others? --we need c++11!!!
        return _instance;
    }
protected:
    singleton2(){cout<<"singleton2 ctor!"<<endl;}
    ~singleton2(){cout<<"singleton2 dctor!"<<endl;}  

private:
    singleton2(const singleton2&);
    singleton2& operator=(const singleton2&);
};
class stim:public singleton2<stim>{
    friend class singleton2<stim>;
public:
private:
    stim(int n=0):x(n){cout<<"stmi ctor!!"<<endl;} //tricks!! still need to be private!!!!
    int x;
};
template<typename T>
class singleton3{
public:
    template<typename... Args>
    static T& instance(Args... args){
        static T _instance(std::forward<Args>(args)...);  
        return _instance;
    }
protected:
    singleton3(){cout<<"singleton3 ctor!"<<endl;}
    ~singleton3(){cout<<"singleton3 dctor!"<<endl;}  

private:
    singleton3(const singleton3&);
    singleton3& operator=(const singleton3&);
};
class stim3:public singleton3<stim3>{
    friend class singleton3<stim3>;
private:
    int x;
    char ch;
    stim3(int n=0,char c='o'):x(n),ch(c){cout<<"stim3 ctor"<<endl;}
};
int main(){
    cout<<"main start!"<<endl;
    singleton &t=singleton::instance();
    // delete &t;
    cout<<"====================="<<endl;
    stim &st=stim::instance();
    // stim stt; //err: call a private ctor!
    cout<<"====================="<<endl;
    // stim3 hehe;
    stim3 &st3=stim3::instance();
    stim3 &st32=stim3::instance(4);
    stim3 &st33=stim3::instance(3,'h');
    cout<<"main stop!"<<endl;
    return 0;
}
