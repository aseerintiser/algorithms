#include <stdio.h>

//Keep multiplying one number a, with i starting from 1
//and whenever, a*i is divisible by the other number b, a*i is the lcm.

int lcm(int a, int b, int i)
{
    if(a*i % b == 0)
        return a*i;
    else
        return lcm(a, b, i+1);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", lcm(a, b, 1));
    return 0;
}

