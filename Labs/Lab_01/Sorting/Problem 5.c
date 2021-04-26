#include <stdio.h>
#include <math.h>

int polynomial_sum(int i, int x, int n)
{
    if(n == 0)
        return 1;
    if(i < n)
        return (int)pow(x,i) + polynomial_sum(i+1, x, n);
    else
        return 0;
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", polynomial_sum(0, x, n));
    return 0;
}
