#ifdef ADRO_OS_LINUX
#include <gnu/libc-version.h>
#endif
#include "utility.h"

void say_hello(FILE * restrict stream){
    fprintf(stream,"Hay there! I'm Adro Tan!\n");
    fprintf(stream, "this program was complied on %s, %s\n", 
            __DATE__, __TIME__);
#ifdef ADRO_OS_LINUX
    fprintf(stream, "with glibc %d.%d\n", __GLIBC__,__GLIBC__MINOR__);
    fprintf(stream, "and you are run with %s\n",gnu_get_libc_version());
#elif defined(ADRO_OS_MAC)
    fprintf(stream, "whit Clang %s\n", __VERSION__);
#endif
}
