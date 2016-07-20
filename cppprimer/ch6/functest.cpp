#include <iostream>
#include <chrono>
auto func1(int t)->int{
    return ++t;
}
class func2{
public:
    auto operator()(int t)->int{
        return ++t;
    }
};
inline int func3(int t){
    return ++t;
}
static inline int func4(int t){
    return ++t;
}
int main(){
    int n,i=0;
    std::chrono::high_resolution_clock::time_point t1,t2;
    std::cout<<"input: ";
    std::cin>>n;
    std::cout<<std::endl;
    std::cout<<"========================="<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(int j=0;j<n;++j){
        i=func1(j);
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"time: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    std::cout<<"========================="<<std::endl;
    func2 func2i;
    t1=std::chrono::high_resolution_clock::now();
    for(int j=0;j<n;++j){
        i=func2i(j);
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"time: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    std::cout<<"========================="<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(int j=0;j<n;++j){
        i=func3(j);
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"time: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    std::cout<<"========================="<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(int j=0;j<n;++j){
        i=func4(j);
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"time: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
}
