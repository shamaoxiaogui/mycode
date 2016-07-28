#include <getopt.h>
#include <fcntl.h>
#include "utility.h"
#define BUF_SIZE 4096

int main(int argc, char* argv[]){
    int fd, ch, i;
    off_t bs=0;
    size_t br=0,bR=0;
    char *bw=NULL;
    ssize_t num;
    char buf[BUF_SIZE];
    static struct option longopts[]={
        {"seek",     required_argument,    NULL,   's'},
        {"read",    required_argument,  NULL,   'r'},
        {"READ",    required_argument,  NULL,   'R'},
        {"write",   required_argument,  NULL,   'w'},
        {NULL,      0,                  NULL,   0}
    };
    while((ch=getopt_long(argc, argv, "s:r:R:w:", longopts, NULL))!=-1){
        switch(ch){
            case 's': 
                bs=getLong(optarg, GN_ANY_BASE, optarg);
                break;
            case 'r':
                br=getLong(optarg, GN_ANY_BASE, optarg);
                break;
            case 'R':
                bR=getLong(optarg, GN_ANY_BASE, optarg);
                break;
            case 'w':
                bw=optarg;
                break;
            default:
                usageErr("%s file {r<length>|R<length>|s<length>|w<length>...}\n",argv[0]);
        }
    }
    argc -= optind;
    argv += optind;
    if(argc==0)
        usageErr("%s file {r<length>|R<length>|s<length>|w<length>...}\n",argv[0]);
    if((fd=open(argv[0],O_WRONLY|O_CREAT,FPERM))==-1)
        errExit("open %s",argv[0]);
    if(bs!=0){
        if((bs=lseek(fd,bs,SEEK_SET))==-1)
            errExit("lseek");
        fprintf(stdout,"lseek to 0x%x OK\n",bs);
    }
    if(br!=0){
        num=(br>BUF_SIZE-1)?BUF_SIZE:br;
        while((num=read(fd,buf,num))>0){
            buf[num]='\0';
            fprintf(stdout, "%s",buf);
            br-=num;
            num=(br>BUF_SIZE-1)?BUF_SIZE:br;
        }
        if(num==-1)
            errExit("read %s", argv[0]);
        fprintf(stdout,"\n");
    }else if(bR!=0){
        num=(bR>BUF_SIZE-1)?BUF_SIZE:bR;
        while((num=read(fd,buf,num))>0){
            for(i=0;i<num;++i)
                fprintf(stdout, "%x ",buf[i]);
            bR-=num;
            num=(bR>BUF_SIZE-1)?BUF_SIZE:bR;
        }
        if(num==-1)
            errExit("Read %s", argv[0]);
        fprintf(stdout,"\n");
    }
    if(bw!=NULL){
        if((num=write(fd,bw,strlen(bw)))==-1)
            errExit("write %s to %s",bw,argv[0]);
    }
    exit(EXIT_SUCCESS);
}
