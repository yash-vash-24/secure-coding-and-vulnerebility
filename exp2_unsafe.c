#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/wait.h>

void null_dereference()
{
    size_t size = SIZE_MAX;
    int *ptr = malloc(size);

    printf("\nNULL pointer test\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", size);

    /* malloc() return value is not checked */
    ptr[0] = 10;
}

void use_after_free()
{
    int n = 5;

    int *ptr = malloc(n * sizeof(int));

    printf("\nAfter malloc\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", n * sizeof(int));

    for (int i = 0; i < n; i++)
        ptr[i] = i + 1;

    n = 10;

    ptr = realloc(ptr, n * sizeof(int));

    printf("\nAfter realloc\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: %zu bytes\n", n * sizeof(int));

    for (int i = 5; i < n; i++)
        ptr[i] = i + 1;

    int *dangling_ptr = ptr;

    free(ptr);

    printf("\nAfter free\n");
    printf("Pointer: %p\n", (void *)ptr);
    printf("Allocated size: 0 bytes\n");

    /* Use-after-free */
    printf("\nAccessing freed memory: %d\n", dangling_ptr[0]);
}

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        null_dereference();
        exit(0);
    }

    if (pid > 0)
    {
        wait(NULL);
        use_after_free();
    }

    return 0;
}