#include <iostream>
using namespace std;
class Someclass{
public:
    static void sfunc(){cout<<"static func"<<endl;}
    static int smember;
    void nsfunc(){cout<<"nonstatic func"<<endl;};
    int nsmember;
};
int Someclass::smember=1;
int main(){
    void (*sfp)();
    int *smp;
    void (Someclass::*nsfp)();
    int Someclass::*nsmp;
    sfp=&Someclass::sfunc;
    smp=&Someclass::smember;
    nsfp=&Someclass::nsfunc;
    nsmp=&Someclass::nsmember;
    printf("p sfp: %p\n",sfp);
    printf("p smp: %p\n",smp);
    printf("p nsfp: %p\n",nsfp);
    printf("p nsmp: %p\n",nsmp);
    return 0;
}
