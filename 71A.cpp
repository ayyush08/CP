#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string wordset[n];
    for (int i = 0; i < n; i++)
    {
        cin >> wordset[i];
    }
    for (int i = 0; i < n; i++)
    {
        int n = wordset[i].size();
        if (n > 10)
        {
            cout << wordset[i][0] + to_string(n - 2) + wordset[i][n - 1];
        }
        else
        {
            cout << wordset[i];
        }
    }
    return 0;
}