#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;

    int *ptr = malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    printf("After malloc\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", n * sizeof(int));

    for (int i = 0; i < n; i++)
        ptr[i] = i + 1;

    n = 10;

    int *temp = realloc(ptr, n * sizeof(int));

    if (temp == NULL)
    {
        printf("realloc failed\n");
        free(ptr);
        ptr = NULL;
        return 1;
    }

    ptr = temp;

    printf("\nAfter realloc\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", n * sizeof(int));

    for (int i = 5; i < n; i++)
        ptr[i] = i + 1;

    printf("Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", ptr[i]);

    printf("\n");

    free(ptr);
    ptr = NULL;

    printf("\nAfter free\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: 0 bytes\n");

    return 0;
}