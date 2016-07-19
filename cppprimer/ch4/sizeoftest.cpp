#include <iostream>
#include <string>
class testc{
public:
    char pwc;
    void update(){}
private:
    char wc;
};
int main(){
    int a=44;
    int ar[5];
    std::string str("heheda!");
    std::cout<<"int : "<<sizeof(a)<<" "<<sizeof(int)<<std::endl;
    std::cout<<"int [5]: "<<sizeof(ar)<<" "<<sizeof(int [5])<<std::endl;
    std::cout<<"string :"<<sizeof(str)<<" "<<sizeof(std::string)<<std::endl;
    std::cout<<"class member(char): "<<sizeof(testc::pwc)<<std::endl;
    return 0;
}
