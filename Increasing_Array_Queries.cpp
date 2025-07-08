#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];


    while (q--) {
        int l, r;
        cin >> l >> r;
        l--,r--;

        int start = a[l];
        int computations = 0;

        for(int i=l+1;i<=r;i++){
            if(a[i]<start){
                computations += start - a[i];
            } else {
                start = a[i];
            }
        }
        cout << computations << "\n";
    }

    return 0;
}