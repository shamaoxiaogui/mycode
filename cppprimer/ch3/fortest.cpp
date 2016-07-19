#include <iostream>
#include <chrono>
#include <string>
int main(){
    int n;
    char ch;
    std::cout<<"input n: ";
    std::cin>>n;
    std::cout<<std::endl;
    std::string str(n,'c');
    std::chrono::high_resolution_clock::time_point t1,t2;
    t1=std::chrono::high_resolution_clock::now();
    for(int i=0;i<n;++i){
        ch=str[i];
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"for: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(auto it=str.begin();it!=str.end();++it){
        ch=*it;
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"iterator for: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(auto t:str){
        ch=t;
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"auto for: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(auto &t:str){
        ch=t;
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"auto& for: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    t1=std::chrono::high_resolution_clock::now();
    for(const auto &t:str){
        ch=t;
    }
    t2=std::chrono::high_resolution_clock::now();
    std::cout<<"const auto& for: "<<std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count()<<" microseconds"<<std::endl;
    return 0;
}
