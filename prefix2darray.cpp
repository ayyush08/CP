#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            
            prefix[i][j] = mat[i-1][j-1]+prefix[i][j - 1] + prefix[i - 1][j] - prefix[i - 1][j - 1];
        }
    }

    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
            cout << prefix[i][j] << " ";
        cout << endl;
    }
    return 0;
}