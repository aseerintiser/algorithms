#include<bits/stdc++.h>
using namespace std;
int mixtures[1000];
long long dp[1000][1000];
long long sum(int s, int e)
{
    long long ans = 0;
    for(int i=s; i<=e; i++)
    {
        ans += mixtures[i];
        ans %= 100;
    }
    return ans;
}
long long solveMixtures(int i, int j)
{
    //smoke generated for a single element is 0 or start>end is 0
    if(i >= j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    //We have to break our expression at every possible k
    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++)
    {
        dp[i][j] = min(dp[i][j], solveMixtures(i,k) + solveMixtures(k+1,j) + sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
}
int main()
{
    int n;

    while(cin >> n)
    {
        for(int i=0; i<n; i++)
        {
            cin >> mixtures[i];
        }

        memset(dp,-1,sizeof(dp));

        cout << solveMixtures(0,n-1) << endl;
    }
}
