#include<bits/stdc++.h>
using namespace std;

int dp[5000][5000];
string s;

int lcs(int i, int j)
{
    if(j <= i)
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];

    if(s[i] == s[j])
    {
        dp[i][j] = lcs(i+1,j-1);
    }
    else
    {
        dp[i][j] = 1 + min(lcs(i+1,j),lcs(i,j-1));
    }
    return dp[i][j];
}


int main()
{

    memset(dp,-1,sizeof(dp));
    int n;
    cin >> n >> s;

    cout << lcs(0,n-1);
}

