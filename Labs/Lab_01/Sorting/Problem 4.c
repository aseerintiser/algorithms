#include <stdio.h>

void print_polynomial(int i, int n)
{
    if(i < n)
    {
        if(i == 0)
            printf("1");
        else
        {
            printf(" + x");
            if(i > 1)
                printf("^%d", i);
        }
        print_polynomial(i+1, n);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    print_polynomial(0, n);
    return 0;
}

