#include<bits/stdc++.h>
using namespace std;

int n;
int priority[20][20];
int dp[1<<15+2][20]; // 1<<15 --> 2^15 bits


int turnOn(int x, int pos)
{
    //makes x's pos bit 1, returns new x
    return x | (1<<pos);
}

bool isOn(int N, int pos)
{
    //N's pos bit zero or one?
    return (bool) (N & (1<<pos));
}

int bitmask(int mask, int groom)
{
    if(groom >= n)
        return 0;

    if(dp[mask][groom] != -1)
        return dp[mask][groom];

    int mx = 0;
    for(int i=0; i<n; i++)
    {
        //if this element not married before (task not assigned)
        if(isOn(mask,i) == 0)
        {
            //turn on 1, go next groom
            mx = max(mx, priority[groom][i] + bitmask(turnOn(mask,i), groom+1));
        }
    }
    return dp[mask][groom] = mx;
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int tc=1; tc<=test; tc++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&priority[i][j]);
            }
        }
        printf("Case %d: %d\n",tc,bitmask(0,0));
    }
    return 0;
}
