// 関数の中の配列

#include <stdio.h>

static int func(int n)
{
    int x[n];
    return sizeof(x);
}

int main()
{
    int ret = func(10);
    printf("%lu %d\n", sizeof(int), ret);

    return 0;
}
