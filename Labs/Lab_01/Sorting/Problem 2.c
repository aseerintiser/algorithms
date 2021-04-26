#include <stdio.h>

void print(int start, int size, int *array)
{
    if(start <= size)
    {
        printf("%d %d\n", array[start], array[size]);
        print(start+1, size-1, array);
    }
}

int main()
{
    int start, size, array[100];
    scanf("%d", &size);
    for(start = 0; start < size; start++)
    {
        scanf("%d", &array[start]);
    }
    print(0, size-1, array);
    return 0;
}

