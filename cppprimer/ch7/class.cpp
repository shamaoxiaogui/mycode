#include <iostream>
class child1;
class father{
friend void pfm(child1 *c);
public:
protected:
    int fpm=1;
private:
    int fm=0;
};
class child1:public father{
// friend void pfm(child1 *c);
public:
    void ppfm(){std::cout<<fpm<<std::endl;}
private:
    void pfm(){std::cout<<fpm<<std::endl;}
    int cm=1;
};
class child2:private father{
public:
    void pfm(){std::cout<<fpm<<std::endl;}
private:
    int cm2=2;
};
void pfm(child1 *c){
    std::cout<<c->fpm<<std::endl;
}
int main(){
    father f;
    child1 ch1;
    child2 ch2;
    pfm(&ch1);
    return 0;
}
