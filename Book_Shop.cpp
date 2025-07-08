#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int price[n];
    int pages[n];
    for (int i = 0; i < n; i++)
        cin >> price[i];
    for (int i = 0; i < n; i++)
        cin >> pages[i];

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= k; w++)
        {
            if (price[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], pages[i - 1] + dp[i - 1][w - price[i - 1]]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int result = dp[n][k];
    cout << result;
}