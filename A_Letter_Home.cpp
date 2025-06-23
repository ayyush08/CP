// https://codeforces.com/contest/2121/problem/A
//find diff between both extremes, then rightextreme-leftextreme+(min)

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;cin>>tc;
    while(tc--){
        int n,s;
        cin >> n >> s;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int left = 0, right = n - 1;
        int delta1 = abs(a[left]-a[s]);
        int delta2 = abs(a[right]-a[s]);
        int delta = min(delta1, delta2);
        cout << (a[right] - a[left] + delta) << endl;
    }

return 0;
}