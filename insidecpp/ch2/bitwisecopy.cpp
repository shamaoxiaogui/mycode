#include <iostream>
using namespace std;
struct bitwise{
    int n;
    char *hehe;
};
struct goodcopy{
    goodcopy(){}
    goodcopy(const goodcopy&){cout<<"good copy!!"<<endl;}
};
struct nonbitwise{
    goodcopy gc;
};
struct nonbitwise2:public goodcopy{

};
struct nonbitwise3{
    nonbitwise3(){}
    nonbitwise3(const nonbitwise3&){}
    goodcopy gc;
};
int main(){
    bitwise bw1;
    char * str="blabla!";
    bw1.hehe=str;
    bw1.n=1;
    bitwise bw2(bw1);
    cout<<"bw1 n "<<bw1.n<<" hehe "<<bw1.hehe<<endl;
    cout<<"bw2 n "<<bw2.n<<" hehe "<<bw2.hehe<<endl;
    cout<<"============================="<<endl;
    nonbitwise nbw1;
    nonbitwise nbw12(nbw1);
    cout<<"============================="<<endl;
    nonbitwise2 nbw2;
    nonbitwise2 nbw22(nbw2);
    cout<<"============================="<<endl;
    nonbitwise3 nbw3;
    nonbitwise3 nbw32(nbw3);
    return 0;
}
