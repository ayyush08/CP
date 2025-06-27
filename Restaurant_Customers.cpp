#include<bits/stdc++.h>
using namespace std;
int main()
{
int n; cin >> n;

vector<pair<int,int>>v(n);

for(int i=0;i<n;i++) cin >> v[i].first >> v[i].second ;

vector<pair<int,int>>sorted;

for(int i=0;i<n;i++){
    sorted.push_back({v[i].first,1});
    sorted.push_back({v[i].second,-1});
}

sort(sorted.begin(),sorted.end());

int customers = 0;
int sm=0;
for(int i=0;i<sorted.size();i++){
    sm+=sorted[i].second;
    customers = max(sm,customers);
}

cout << customers;

return 0;
}