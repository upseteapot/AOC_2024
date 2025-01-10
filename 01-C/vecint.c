#include "vecint.h"

// Algorithms
void quicksort(vecint_t *vec, int low, int high)
{
    if (low < 0 || low >= high)
        return;
   
    int pivot = vecint_at(vec, (low + high) / 2);

    int lt = low;
    int eq = low;
    int gt = high; 

    int elem; 
    while (eq <= gt)
    {
        elem = vecint_at(vec, eq);

        if (elem < pivot)
        {
            vecint_swap(vec, eq, lt);
            eq++;
            lt++;
        } else if (elem > pivot)
        {
            vecint_swap(vec, eq, gt);
            gt--; 
        } else 
        {
           eq++; 
        }
    }

    quicksort(vec, low, lt - 1);
    quicksort(vec, gt + 1, high); 
}


// Create new vecint_t object.
void vecint_new(vecint_t *vec, size_t capacity)
{
    vec->_capacity = capacity;
    vec->size = 0;
    vec->data = (int *)malloc(sizeof(int) * vec->_capacity);
}

// Push new element to vector.
void vecint_push(vecint_t *vec, int new_data)
{
    if (vec->size >= vec->_capacity)
    {
        vec->_capacity *= 2;
        vec->data = (int *)realloc(vec->data, sizeof(int) * vec->_capacity); 
    }

    vec->data[vec->size] = new_data;
    vec->size++;
}

// Get element from vector.
int vecint_at(vecint_t *vec, size_t index)
{
    if (index >= vec->size)
    {
        printf("[AT] Index out of bounds. (size=%zu, index=%zu)\n", vec->size, index);
        return 0;
    }

    return vec->data[index];
}

// Swap two elements.
void vecint_swap(vecint_t *vec, size_t a, size_t b)
{
    if (a >= vec->size || b >= vec->size)
    {
        printf("[SWAP] Index out of bounds. (size=%zu, a=%zu, b=%zu)\n", vec->size, a, b);
        return;
    }

    int temp_a = vec->data[a];
    vec->data[a] = vec->data[b];
    vec->data[b] = temp_a;
}

// Print values.
void vecint_print(vecint_t *vec)
{
    printf("capacity=%zu,size=%zu\n[ ", vec->_capacity, vec->size);
    for (size_t i = 0; i < vec->size; i++)
        printf("%d ", vec->data[i]);
    printf("]\n");
}

// Free vector data.
void vecint_free(vecint_t *vec)
{
    free(vec->data);
}

// Sort vector.
void vecint_sort(vecint_t *vec)
{
    quicksort(vec, 0, vec->size - 1);
}

