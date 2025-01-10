#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    size_t _capacity;
    size_t size;
    int *data;
} vecint_t;

void vecint_new(vecint_t *vec, size_t capacity);
void vecint_push(vecint_t *vec, int new_data);
int  vecint_at(vecint_t *vec, size_t index);
void vecint_swap(vecint_t *vec, size_t a, size_t b);
void vecint_print(vecint_t *vec);
void vecint_free(vecint_t *vec);
void vecint_sort(vecint_t *vec);

