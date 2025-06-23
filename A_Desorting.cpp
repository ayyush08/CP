#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int mn = INT_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = v[i + 1] - v[i];

                mn = min(mn, diff);
            
        }
        if(mn<0) cout << 0 << endl;
        else cout << (mn / 2) + 1 << endl;
    }
    return 0;
}