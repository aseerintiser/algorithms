#include<bits/stdc++.h>
using namespace std;

long dp[1000][1000];

long int noOfWays(int need,long coins[],int j)
{
    if(need == 0)  //all needs are paid
        return 1;
    if(need < 0)   //invalid payment
        return 0;
    if(j <= 0)
        return 0;

    if(dp[need][j] != -1)
        return dp[need][j];

    //not choosing j, or choosing j infinitely and minusing from need
    dp[need][j] = noOfWays(need,coins,j-1) + noOfWays(need-(int)coins[j-1],coins,j);
    return dp[need][j];
}

int main()
{
    int need;
    int coin;
    cin >> need >> coin;

    long coins[coin];

    for(int i=0; i<coin; i++)
    {
        cin >> coins[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << noOfWays(need,coins,coin);
}
