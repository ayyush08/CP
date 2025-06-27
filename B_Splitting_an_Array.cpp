#include <bits/stdc++.h>
using namespace std;
#define int long long

//RETRY

bool isPossible(int mid, vector<int> &arr, int k)
{
    int cnt = 1, segSum = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>mid) return false;
        if (arr[i] + segSum <= mid)
        {
            segSum += arr[i];
        }
        else
        {
            cnt++;
            segSum = arr[i];
        }
    }
    return cnt <= k;
}

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int l = *max_element(arr.begin(), arr.end());
    int r = accumulate(arr.begin(), arr.end(), 0);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (isPossible(mid, arr, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans;

    return 0;
}

// f(s) - is it possible to divide array at msot k segmenets suchthat maximum sum of any segment <=s