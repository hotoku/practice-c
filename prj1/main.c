// 指定された数だけ、標準入力から値を読む

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    double x[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &x[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%f\n", x[i]);
    }

    return 0;
}
