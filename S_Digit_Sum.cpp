#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int D;
vector<vector<vector<int>>> dp;

int fun(int i, int tight_bound, int sum, string &s, vector<vector<vector<int>>> &dp)
{
    if (i == s.size())
    {
        return (sum %D== 0) ? 1 : 0;
    }
    if (dp[i][tight_bound][sum] != -1)
    {
        return dp[i][tight_bound][sum];
    }
    int mx = 9;
    if (tight_bound)
        mx = s[i] - '0';
    int ans = 0;
    for (int j = 0; j <= mx; j++)
    {
        if (j < mx)
        {
            ans = (ans + fun(i + 1, 0, (sum + j) % D, s, dp)) % MOD;
        }
        else
        {
            if (tight_bound)
                ans = (ans + fun(i + 1, 1, (sum + j) % D, s, dp)) % MOD;
            else
                ans = (ans + fun(i + 1, 0, (sum + j) % D, s, dp)) % MOD;
        }
    }
    return dp[i][tight_bound][sum] = ans % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    cin >> D;
    dp.assign(s.size(), vector<vector<int>>(2, vector<int>(D, -1)));
    int ans = fun(0, 1, 0, s, dp);
    cout << (ans-1+MOD) % MOD << endl;
    return 0;
}