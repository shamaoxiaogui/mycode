#include "utility.h"
#include <fcntl.h>

#define RFLAG (O_RDONLY)
#define WFLAG (O_WRONLY | O_APPEND | O_CREAT | O_TRUNC)
#define BUF_SIZE 4096

int main(int argc, char* argv[]){
    int rfd, wfd;
    char buffer[BUF_SIZE];
    ssize_t count;
    if(argc != 3 || strcmp(argv[1],"-h") == 0 || strcmp(argv[1], "--help") == 0)
        usageErr("%s srcFile dstFile\n",argv[0]);
    if((rfd = open(argv[1], RFLAG))==-1)
        errExit("open %s", argv[1]);
    if((wfd = open(argv[2], WFLAG, FPERM))==-1)
        errExit("open %s", argv[2]);

    while((count=read(rfd, buffer, BUF_SIZE))>0){
        if((write(wfd, buffer, count))!=count)
            errExit("write %s",argv[2]);
    }
    if(count == -1)
        errExit("read %s", argv[1]);

    if(close(rfd)==-1)
        errExit("close %s", argv[1]);
    if(close(wfd)==-1)
        errExit("close %s", argv[2]);

    exit(EXIT_SUCCESS);
        
}
