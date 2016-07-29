#include <iostream>
#include <string>
using namespace std;
class nonPOD{
public:
    nonPOD(const string& s="default"):str(s){cout<<str<<" nonPOD ctor"<<endl;}
    nonPOD(const nonPOD& t):n(t.n),str(t.str+"_copy"){cout<<str<<" copy ctor"<<endl;}
    virtual ~nonPOD(){cout<<str<<" nonPOD dctor"<<endl;}
    int getn(){return n;}
private:
    int n;
    string str;
};
struct POD{
    int i;
    char ch;
};

nonPOD np;
nonPOD np1("hehe");
nonPOD np2(np1);
POD p;
POD p1={1,'c'};
int gzn;    //bss
int gn=4;   //data

POD *pp=new POD;
nonPOD *pnp=new nonPOD;

int main(){
    cout<<"main start"<<endl;
    static int szn;
    static int sn=5;
    cout<<"gzn: "<<gzn<<" gn: "<<gn<<" szn: "<<szn<<" sn: "<<sn<<endl;
    static nonPOD snp;
    static nonPOD snp1("static hehe");
    static POD sp;
    static POD sp1={1,'c'};
    cout<<"np.n: "<<np.getn()<<endl;
    cout<<"np1.n: "<<np1.getn()<<endl;
    cout<<"np2.n: "<<np2.getn()<<endl;
    cout<<"snp.n: "<<snp.getn()<<endl;
    cout<<"snp1.n: "<<snp1.getn()<<endl;
    cout<<"p.i: "<<p.i<<endl;
    cout<<"sp.i: "<<sp.i<<endl;
    cout<<"pnp->n: "<<pnp->getn()<<endl;
    cout<<"pp->i: "<<pp->i<<endl;
    cout<<"main stop"<<endl;
    return 0;
}
