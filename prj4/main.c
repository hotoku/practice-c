// 構造体の確保と解放の例

#include "vector.h"

#include <stdio.h>

int main()
{
    size_t n = 10;
    vector *v = vector_new(n);
    if (v == NULL)
    {
        fprintf(stderr, "vector_new failed\n");
        return 1;
    }
    for (size_t i = 0; i < v->size; i++)
    {
        v->data[i] = i * 0.1;
    }
    vector_print(v);
    vector_free(v);
}
