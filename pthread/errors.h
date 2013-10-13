#ifndef ERROR_H_
#define ERROR_H_

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef DEBUG
    #define DPRINTF (arg) printf(arg)
#else
    #define DPRINTF (arg)
#endif

#define err_abort(code,arg)    do { \
    fprintf(stderr,"%s at \" %s \" :%d: %s\n", \
            arg,__FILE__,__LINE__,strerror(code)); \
    exit(EXIT_FAILURE); \
}while(0);
#define errno_abort(arg)    do { \
    fprintf(stderr,"%s at \" %s \" :%d: %s\n", \
            arg,__FILE__,__LINE__,strerror(errno)); \
    exit(EXIT_FAILURE); \
}while(0);

#endif
