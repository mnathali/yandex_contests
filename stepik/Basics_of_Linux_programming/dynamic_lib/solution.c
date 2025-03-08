#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char const *argv[])
{
    int (*f)(int);
    void *hdl = dlopen(argv[1], RTLD_LAZY);
    if (NULL == hdl)
        return 1;
    f = (int (*)(int))dlsym(hdl, argv[2]);
    if (NULL == f)
        return 1;
    int res = f(atoi(argv[3]));
    printf("%d\n", res);
    return 0;
}
