#include<bits/stdc++.h>
using namespace std;

string str;
int z[2000005];

void calc_z()
{
    int L = 0;
    int R = 0;
    int i = 0;
    z[0] = 0;

    for(int i=1; i<str.size(); i++)
    {
        if(i>R)
        {
            L = i;
            R = i;
            int in = 0;
            while(str[R] == str[R-L] && R<str.size())
            {
                R++;
                in++;
            }
            z[i] = R - L;
            R--;
        }
        else
        {
            int k = i - L;
            if(z[k]< R - i + 1)
                z[i] = z[k];
            else
            {
                L = i;
                int in = 0;
                while(str[R]==str[R-L] && R<str.size())
                {
                    R++;
                    in++;
                }
                z[i] = R - L;
                R--;
            }
        }
    }
}

int main()
{
    int test;
    cin >> test;
    for(int x=1; x<=test; x++)
    {
        int cnt=0;
        cin >> str;

        calc_z();

        for(int i=1; i<str.size(); i++)
        {
            if(z[i] && i+z[i]==str.size()) cnt++;
        }

        cout<<"Case "<< x <<": "<< cnt <<"\n";
        memset(z,0,sizeof(z));
    }

}
