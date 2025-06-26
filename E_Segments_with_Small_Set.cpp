#include <bits/stdc++.h>
using namespace std;
//REVISIT

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
    unordered_map<int, int> mp;
    int cnt = 0, l = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] == 1)
            cnt++;
        while (cnt > s)
        {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0)
                cnt--;
            l++;
        }
        ans += (i - l + 1);
    }

    cout << ans;

    return 0;
}