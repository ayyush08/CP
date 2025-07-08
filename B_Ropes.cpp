#include <bits/stdc++.h>
using namespace std;

bool canCut(const vector<int> &ropes, int k, double len)
{
    int count = 0;
    for (int rope : ropes)
    {
        count += int(rope / len);
    }
    return count >= k;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> ropes(n);
    double mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> ropes[i];
        if (ropes[i] > mx)
            mx = ropes[i];
    }

    double low = 0.0, high = mx;

    while (high - low > 1e-7)
    {
        double mid = (low + high) / 2.0;
        if (canCut(ropes, k, mid))
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    cout << fixed << setprecision(1) << low << endl;

    return 0;
}

// If we can maka atleast K pieces of length l then f(l)=1;