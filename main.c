#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib1.h"


int main(int argc, char **argv)
{
    void *dlhandle = dlopen("libDLLib1.so", RTLD_LAZY);
    if(dlhandle == NULL)
        printf("dlopen error : %s\n", dlerror());
    int (*dlop1)(int) = (int(*)(int))dlsym(dlhandle, "dlop1");
    if(dlop1 == NULL)
        printf("dlopen error : %s\n", dlerror());
    else
        printf ("Result DL  = %d\n", dlop1(atoi(argv[1])));
    printf ("Result Shared = %d\n", op1(atoi(argv[1])));
    dlclose(dlhandle);
    return EXIT_SUCCESS;
}
