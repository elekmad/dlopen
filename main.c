#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "lib1.h"


int main(int argc, char **argv)
{
    printf ("Result = %d\n", op1(atoi(argv[1])));
    return EXIT_SUCCESS;
}
