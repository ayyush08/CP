#include <bits/stdc++.h>
using namespace std;
// Revisit
int main()
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    unordered_map<int, int> mp;

    int mxlen = 0, sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += arr[i];
        if (sm <= s)
        {
            mxlen = max(mxlen, i + 1);
        }
        int rm = s - arr[i];
        if (mp.find(rm) != mp.end())
        {
            mxlen = max(mxlen, i - mp[rm]);
        }

        if (mp.find(sm) == mp.end())
        {
            mp[sm] = i;
        }
    }

    cout << mxlen;
    return 0;
}

// Approach  2:

void func(int n, int arr[], int s)
{
    int l = 0, sm = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sm += arr[i];
        while (sm > s)
        {
            sm -= arr[l];
            l++;
        }
        ans = max(ans, i - l + 1);
    }
}