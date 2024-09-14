// const * と * const の違いを確認するプログラム

#include <stdlib.h>

int main()
{
    const int *a = malloc(sizeof(int));
    // *a = 10; これはダメ

    int *const b = malloc(sizeof(int));
    *b = 10; // これはOK
    // b = a; // これはダメ

    // freeのシグネチャはfree(void *)なので、
    // const なポインタをfreeするときはキャストしないとwarningが出る
    free((void *)a);
    free(b);
    return 0;
}
