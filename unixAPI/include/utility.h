#ifndef ADRO_UTILITY_H
#define ADRO_UTILITY_H
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include "sys_version.h"
#include "error_functions.h"
#include "get_num.h"

typedef enum{FALSE, TRUE} Boolean;
#define FPERM (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
#define min(m,n) ((m) < (n) ? (m) : (n))
#define max(m,n) ((m) > (n) ? (m) : (n))
void say_hello(FILE * restrict stream);
#endif
