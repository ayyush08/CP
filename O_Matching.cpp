#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int N = 1 << n;
    vector<int> dp(N, 0);

    dp[0] = 1; // Base case - no men assigned, no womens used

    for (int mask = 0; mask < N; ++mask)
    {
        int i = __builtin_popcount(mask); // number of men assigned
        for (int j = 0; j < n; ++j)
        {
            if ((mask & (1 << j)) == 0 && a[i][j] == 1)
            {
                int newMask = mask | (1 << j);
                dp[newMask] = (dp[newMask] + dp[mask]) % MOD;
            }
        }
    }

    cout << dp[N - 1] << endl;
    return 0;
}