#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    // dp_prefix[i] = longest increasing subarray ending at index i
    // dp_suffix[i] = longest increasing subarray starting at index i
    vector<int> dp_prefix(n, 0);
    vector<int> dp_suffix(n, 0);
    int ans = 1;
    dp_prefix[0] = 1;
    dp_suffix[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
            dp_prefix[i] = dp_prefix[i - 1] + 1;
        else
            dp_prefix[i] = 1;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
            dp_suffix[i] = dp_suffix[i + 1] + 1;
        else
            dp_suffix[i] = 1;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i - 1] < a[i + 1] )
        {
            ans = max(ans, dp_prefix[i - 1] + dp_suffix[i + 1]);
        }
    }
    for(int i=1;i<=n;i++){
        ans = max(ans,dp_prefix[i-1]);
    }
    cout << ans << endl;
    return 0;
}