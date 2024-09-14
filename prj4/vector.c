#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

vector *vector_new(size_t size)
{
    vector *v = malloc(sizeof(vector));
    if (v == NULL)
    {
        return NULL;
    }
    v->size = size;
    v->data = malloc(sizeof(double) * size);
    if (v->data == NULL)
    {
        free(v);
        return NULL;
    }
    return v;
}

void vector_free(vector *v)
{
    free(v->data);
    free(v);
}

void vector_print(const vector *v)
{
    for (size_t i = 0; i < v->size; i++)
    {
        printf("data[%zu]=%f\n", i, v->data[i]);
    }
}
