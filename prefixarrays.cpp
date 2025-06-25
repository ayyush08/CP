#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q; cin >> n >> q;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> prefix(n+1,0);

    int cumulative_sum = 0;
    for(int i = 0; i < n; i++) {
        prefix[i] = cumulative_sum;
        cumulative_sum+=v[i];
    }
    prefix[n] = cumulative_sum;
    

    while(q--){
        int a,b; cin >> a >> b;
        cout << prefix[b]-prefix[a-1] << '\n'; //remove everything before starting point (gotta take the starting point too for range based query)
    }

    return 0;
}