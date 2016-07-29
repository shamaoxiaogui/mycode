#include <iostream>
#include <string>
using namespace std;
string func(char *s){
    string t("temp");
    t+=" hehe";
    t+=s;
    return t;
}
int main(){
    string && rs=func(" blabla");
    cout<<rs<<endl;
    return 0;
}
