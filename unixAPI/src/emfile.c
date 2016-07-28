#include "utility.h"
#include <fcntl.h>

#define FLAG (O_CREAT)

int main(int argc, char* argv[]){
    int fd,i;
    char fname[32];
    int max;
    if(argc!=2)
        usageErr("%s [max open file numbers]\n",argv[0]);
    max=getInt(argv[1],GN_ANY_BASE|GN_NONNEG, "fd numbers");
    for(i=0;i<max;++i){
        snprintf(fname, 32, "%d.out", i);
        fd=open(fname, FLAG, FPERM);
        if(fd<0){
            printf("failed at i=%d \n",i);
            errExit("open %s",fname);
        }
    }
    printf("test success!\n");
    exit(EXIT_SUCCESS);
    
}
