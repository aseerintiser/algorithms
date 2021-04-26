#include<bits/stdc++.h>
using namespace std;

vector<int> createLPS(string pattern)
{
    vector<int> lps(pattern.size());
    int index = 0;

    for(int i=1; i<pattern.size(); i++)
    {
        if(pattern[index] == pattern[i])
        {
            lps[i] = index + 1;
            ++index;
            ++i;
        }
        else
        {
            if(index != 0)
            {
                index = lps[index-1];
            }
            else
            {
                lps[i] = index;
                ++i;
            }
        }
    }
    return lps;
}

int kmp(string text, string pattern)
{
    int res = 0;
    bool found = false;

    vector<int> lps = createLPS(pattern);

    int i=0,j=0; //i -> text , j -> pattern

    while(i < text.size())
    {
        if(text[i] == pattern[j])
        {
            ++i;
            ++j;
        }
        else
        {
            if(j != 0)
                j = lps[j-1];
            else
                ++i;
        }

        if(j == pattern.size())
        {
            ++res;
            found = true;
        }
    }
    return res;
}

int main()
{
    int test = 0;
    cin >> test;

    for(int i=1; i<=test; i++)
    {
        string text, pattern;
        cin >> text >> pattern;

        int res = kmp(text,pattern);
        cout << "Case " << i << ": " << res << endl;
    }

}
