#include <alloca.h>
#include <stdio.h>
#include <stddef.h>

void printArray(size_t size)
{
    int* arr = alloca(size * sizeof(int));
    for(int i = 0; i < size; i++)
    {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    puts("\n");
}

int main(void)
{
    printArray(100);
}