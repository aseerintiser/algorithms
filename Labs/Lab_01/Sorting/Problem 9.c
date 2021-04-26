#include <stdio.h>

//We will keep dividing a by b.
//The value a%b will be the b for the next step and current b will be the a for the next step.

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b, a%b);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a,b));
    return 0;
}

