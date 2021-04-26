#include<iostream>
using namespace std;

int noOfWays(int n)
{
    if (n == 1) return 2;
    if (n == 2) return 4;

    return noOfWays(n-1) + noOfWays(n-2);
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        int w; cin >> w;
        cout << noOfWays(w) << endl;
    }
}
