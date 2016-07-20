#include <iostream>
void func(int (&arr)[5]){
    arr[3]=5;
}
int main(){
    int a[5];
    func(a);
    return 0;
}
