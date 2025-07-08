#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main()
{
int n,x;
cin >> n >> x;
int sm=0,cnt=0;
int arr[n];
for(int i=0;i<n;i++){
    cin >> arr[i];
}

unordered_map<int,int> mp;
for(int i=0;i<n;i++){
    sm += arr[i];
    if(sm==x) cnt++;
    if(mp.find(sm-x) != mp.end()){
        cnt += mp[sm-x];
    }
    mp[sm]++;
}

cout << cnt;


return 0;
}