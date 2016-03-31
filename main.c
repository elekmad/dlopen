#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib1.h"


int main(int argc, char **argv)
{
    void *dlhandle = dlopen("libDLLib1.so", RTLD_LAZY);
    if(dlhandle == NULL)
        printf("dlopen error : %s\n", dlerror());
    char *(*dlop1)(void) = (char *(*)(void))dlsym(dlhandle, "dlop1");
    if(dlop1 == NULL)
        printf("dlopen error : %s\n", dlerror());
    else
        printf ("Result DL  = %s\n", dlop1());
    printf ("Result Shared = %s\n", op1());
    dlclose(dlhandle);
    return EXIT_SUCCESS;
}
