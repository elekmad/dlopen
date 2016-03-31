#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib1.h"


int main(int argc, char **argv)
{
    void *dlhandle = NULL;
    if(argc > 1)
    {
        char *(*dlop1)(void) = NULL;
        dlhandle = dlopen(argv[1], RTLD_LAZY);
        if(dlhandle == NULL)
            printf("dlopen error : %s\n", dlerror());
        else
        {
            dlop1 = (char *(*)(void))dlsym(dlhandle, "dlop1");
            if(dlop1 == NULL)
                printf("dlopen error : %s\n", dlerror());
            else
                printf ("Result DL  = %s\n", dlop1());
            dlclose(dlhandle);
        }
    }
    printf ("Result Shared = %s\n", op1());
    return EXIT_SUCCESS;
}
