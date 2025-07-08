#include<bits/stdc++.h>
using namespace std;


int func(vector<int> &dp,int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int m = n;
    int ans = INT32_MAX;
    while(m>0){
        int dk = m%10;
        m/=10;
        if(dk==0) continue;
        ans = min(ans,1+func(dp,n-dk));
    }
    return dp[n]=ans;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;cin>> n;
vector<int>dp(n+1,-1);

cout << func(dp,n);




return 0;
}