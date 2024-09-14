// 関数ポインタ

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

typedef int (*operation_t)(int, int);

int main()
{
    operation_t opes[2];
    opes[0] = add;
    opes[1] = sub;
    for (size_t i = 0; i < 10; i++)
    {
        printf("%d\n", opes[i % 2](0, i));
    }
    return 0;
}
