#include <stdio.h>

void print_reverse(int start, int size, int *array)
{
    if(start < size)
    {
        print_reverse(start + 1, size, array);
        printf("%d ", array[start]);
    }
}

int main()
{
    int start, size, array[10];
    scanf("%d", &size);
    for(start = 0; start < size; start++)
    {
        scanf("%d", &array[start]);
    }
    print_reverse(0, size, array);
    return 0;
}

