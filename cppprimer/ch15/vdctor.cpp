#include <iostream>
class father{
public:
    virtual ~father(){std::cout<<"father vdctor"<<std::endl;}
private:
    int i=0;
};
class son:public father{
public:
    ~son(){std::cout<<"son vdctor"<<std::endl;}
private:
    int n=1;
};
class grandson:public son{
public:
    ~grandson(){std::cout<<"grandson vdctor"<<std::endl;}
private:
    int x=1;
};
int main(){
    son* fp=new grandson();
    delete fp;
    return 0;
}
