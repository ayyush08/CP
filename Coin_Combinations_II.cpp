#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    int mod = 1e9+7;
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
    dp[0][0]=1;
    for(int i=1;i<=x;i++) dp[i][0] = 0;
    for(int i =1;i<=n;i++){
        for(int j=0;j<=x;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=coins[i-1]){
                dp[i][j]=(dp[i][j]+dp[i-1][j-coins[i-1]])%mod;
            }
        }
    }

    cout << dp[n][x]%mod << endl;
    return 0;
}