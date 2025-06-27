#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());

    if(!k){

        if(nums[0] == 1) cout << -1 << '\n';
        else cout << nums[0]-1 << '\n';
        return 0;
    }

    if (k == n)
    {
        cout << nums[n - 1] << '\n';
        return 0;
    }

    if (nums[k] != nums[k - 1])
    {
        cout << nums[k - 1] << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }

    return 0;
}