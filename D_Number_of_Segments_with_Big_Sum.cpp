#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int l = 0, sm = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sm += arr[i];
        while(sm>=s){
            sm-=arr[l];
            ans +=(n-i);
            l++;
        }
        // ans++;
    }

    cout << ans; 
    return 0;
}