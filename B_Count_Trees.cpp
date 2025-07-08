#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<char>> forest(n, vector<char>(n, '.'));
    vector<vector<int>> queries(q, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> forest[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> queries[i][j];
        }
    }

    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] = (forest[i - 1][j - 1] == '*') + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }

    for (int i = 0; i < q; i++)
    {
        int y1 = queries[i][0];
        int x1 = queries[i][1];
        int y2 = queries[i][2];
        int x2 = queries[i][3];

        int ans = prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1];

        cout << ans << '\n';
    }

    return 0;
}