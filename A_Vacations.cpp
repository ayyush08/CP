#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> vasya(n);
    for (int i = 0; i < n; i++)
        cin >> vasya[i];

    vector<vector<int>> dp(n + 1, vector<int>(3, INT_MAX));
    // rest=0,gym=1,contest=2
    dp[0][0] = dp[0][1] = dp[0][2] = 0; // Base case: day0, all rested
    for (int i = 1; i <= n; i++)
    {
        // Rest today
        dp[i][0] = 1 + min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]));

        // Gym today (only if gym is open and we didn't gym yesterday)
        if (vasya[i-1] == 2 || vasya[i-1] == 3)
        {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }

        // Contest today (only if contest is held and we didn't contest yesterday)
        if (vasya[i-1] == 1 || vasya[i-1] == 3)
        {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }

    int result = min(dp[n][0], min(dp[n][1], dp[n][2]));
    cout << result << endl;

    return 0;
}