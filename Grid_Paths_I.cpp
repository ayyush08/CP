#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    if (grid[0][0] == '.') dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;
            if (i > 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
        }
    }

    cout << dp[n-1][n-1] << endl;
    return 0;
}
