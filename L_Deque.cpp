#include<bits/stdc++.h>
using namespace std;
#define int long long

//dp[l][r][i] = score from subarry[l..r] if its ith player's turn
int func(vector<int> &a, int l, int r, vector<vector<vector<int>>> &dp, int turn) {
    if(dp[l][r][turn] != LLONG_MIN) return dp[l][r][turn];
    if(l > r) return 0; 
    if(l == r) return dp[l][r][turn] = turn ? a[l] : -a[l]; 
    if(turn) {
        int taro1 = a[l] + func(a, l + 1, r, dp, 0);
        int taro2 = a[r] + func(a, l, r - 1, dp, 0);
        return dp[l][r][turn] = max(taro1, taro2);
    }
    else{
        int jiro1 = func(a, l + 1, r, dp, 1)- a[l];
        int jiro2 = func(a, l, r - 1, dp, 1)- a[r];
        return dp[l][r][turn] = min(jiro1, jiro2);
    }

    // return dp[l][r][turn];
}


signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++) cin>>a[i];
vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, LLONG_MIN)));

bool turn = true;
cout << func(a, 0, n - 1, dp, 1) << endl;

return 0;
}