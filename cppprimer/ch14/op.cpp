#include <iostream>
class tc{
public:
    int _val;
};
tc& operator=(tc& lhs,tc& rhs){
    lhs._val=rhs._val;
    return lhs;
}
int main(){
    tc test;
    return 0;
}
