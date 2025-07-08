#include <bits/stdc++.h>
using namespace std;
#define int long long

bool canEat(vector<int> &candies, int k, int q)
{
    int cnt = 0;
    for (int candy : candies)
    {
        cnt += min(candy, k);
    }
    return cnt >= (k * q);
}

signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        int tot=0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            tot += a[i];
        }

        int l = 0, r = tot/n;
        int ans = -1;
        while (q--)
        {
            int quantity; cin >> quantity;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (canEat(a, mid, quantity))
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            
            cout << ans << '\n';
        }
    }
    return 0;
}