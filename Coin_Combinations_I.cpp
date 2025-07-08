#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,x; cin >> n >> x;
vector<int> coins(n);
for(int i=0; i<n; i++) cin >> coins[i];

vector<int>dp(x+1,0);
int mod = 1e9 + 7;
dp[0]=1;

for(int w = 1;w<=x;w++){
for(int coin:coins){
        if(coin<=w){
            dp[w] =(dp[w]+dp[w-coin])%mod;
        }
    }
}

cout << dp[x]%mod;

return 0;
}