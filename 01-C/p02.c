#include <stdio.h>
#include "vecint.h"


int main(void)
{
    FILE *file = fopen("input", "r");

    vecint_t left, right;
    vecint_new(&left, 64);
    vecint_new(&right, 64);

    int lv, rv;
    size_t size = 0; 
    while (fscanf(file, "%d   %d ", &lv, &rv) > 0)
    {
        vecint_push(&left, lv);
        vecint_push(&right, rv);
        size++;
    }
    
    int sum = 0;
    int count = 0;
    for (size_t i=0; i < size; i++)
    {
        count = 0;
        
        for (size_t j=0; j < size; j++)
            if (vecint_at(&left, i) == vecint_at(&right, j))
                count++;

        sum += vecint_at(&left, i) * count;
    }

    printf("sum: %d\n", sum);

    fclose(file); 
    vecint_free(&left);
    vecint_free(&right);

    return 0;

}

