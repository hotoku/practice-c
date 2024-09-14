#pragma once

#include <stddef.h>

typedef struct
{
    size_t size;
    double *data;
} vector;

vector *vector_new(size_t size);
void vector_free(vector *v);
void vector_print(const vector *v);
