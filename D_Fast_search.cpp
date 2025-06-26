#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int q; cin >> q;
    sort(arr,arr+n);
    while(q--){
        int l,r; cin >> l >> r;
        auto lb = lower_bound(arr,arr+n,l);
        auto ub = upper_bound(arr,arr+n,r);


        cout << ub-lb << " ";
    }
    return 0;
}