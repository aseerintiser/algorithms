#include <stdio.h>

int fib(int n)
{
    if(n < 3)
        return 1;
    else
        return fib(n-2) + fib(n-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", fib(n));
    return 0;
}

