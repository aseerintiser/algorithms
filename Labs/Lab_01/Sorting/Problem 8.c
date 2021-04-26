#include <stdio.h>
#include <math.h>

//we will keep dividing upto sqrt(n) and if none succeeds, the number is a prime, else not
int isPrime(int i, int root, int num)
{
    if(num < 2)
        return 0;
    if(i > root)
        return 1;
    if(num % i == 0)
        return 0;
    else
        return isPrime(i+1, root, num);
}

int main()
{
    int num;
    while(scanf("%d", &num) == 1)
    {
        if(isPrime(2, (int)sqrt(num), num) == 1)
            printf("prime\n");
        else
            printf("not prime\n");
    }
    return 0;
}

