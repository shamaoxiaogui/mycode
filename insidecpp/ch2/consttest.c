#include <stdio.h>
#include <stdlib.h>
int main(){
    const int i=0;
    int *j=(int*)&i;
    *j=1;
    printf("i addr %x val %d\n",&i,i);
    printf("i addr %x val %d\n",j,*j);
    exit(EXIT_SUCCESS);
}
