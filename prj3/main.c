// 関数の中の配列

#include <stdio.h>

static int func(int n)
{
    int x[n];
    return sizeof(x);
}

static int func2(int n, int m)
{
    int x[n][m];
    return sizeof(x);
}

int main()
{
    int ret = func(10);
    printf("%lu %d\n", sizeof(int), ret);

    int ret2 = func2(3, 4);
    printf("%lu %d\n", sizeof(int), ret2);

    return 0;
}
