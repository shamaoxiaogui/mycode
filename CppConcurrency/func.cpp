#include <iostream>
#include <thread>
#include <unistd.h>
void hello(){
    std::cout<<"hello concurrent world!!"<<std::endl;
}
class FakeFunc{
public:
    void operator()() const{
        std::cout<<"hello from a class!"<<std::endl;
    }
};
int main(){
    std::cout<<"hello world, let's get concurrent!!"<<std::endl;
    FakeFunc ff;
    std::thread t(ff); //函数对象会复制到新线程的存储空间当中
    //std::thread my_thread(FakeFunc()); //会引起语法解析问题，临时对象被当成函数调用
    //std::thread my_thread((FakeFunc()); //正确用法1
    //std::thread my_thread{FakeFunc()}; //正确用法2
    t.join();
    // {
    //     std::thread t2([](){std::cout<<"hello from lambda!!"<<std::endl;sleep(60);});
    // }
    std::thread t2([](){std::cout<<"hello from lambda!!"<<std::endl;});
    // t2.join();
    // while(true);
    sleep(5);
    t2.detach();
    //std::thread的析构函数会调用std::terminate()，会导致整个程序结束停止整个进程
    //必须在std::thread对象销毁之前做出决定——在你加入或分离线程之前它可能就已经结束了。如果分离它，线程可能会在std::thread对象销毁之后继续运行下去。（好难翻译，先这样，看到后面再说吧）
    return 0;
}
