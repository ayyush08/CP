#include <bits/stdc++.h>
using namespace std;
//TODO

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, s, x;
        cin >> n >> s >> x;
        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        int low = 0, high = n - 1;
        int pairs = 0;
        while (low < high)
        {
            int mx = INT_MIN;
            int sm = 0;
            for (int i = low; i <= high; i++)
            {
                sm += nums[i];
                if (nums[i] > mx)
                    mx = nums[i];
            }
            if (sm==s && mx==x )
            {
                pairs++;
                low++;
                // high--;
            }
            else if (sm==s || (sm==s && mx < x))
                low++;
            else
                high--;
            }
            cout << pairs << endl;
    }
    return 0;
}