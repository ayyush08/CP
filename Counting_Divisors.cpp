#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e6 + 1;
int divisors[MAX];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    // unordered_map<int, int> savedDivisors; // As code was failing for 10k test cases with same number repeated those many number of times, but in question 512mb space was given so can be utilised to store in kinda caching manner
    // while (tc--)
    // {
    //     int n;
    //     cin >> n;
    //     if(savedDivisors.count(n))
    //     {
    //         cout << savedDivisors[n] << '\n';
    //         continue;
    //     }
    //     int divisors = 0;
    //     for (int i = 1; i * i <= n; i++)
    //     {

    //         if (n % i == 0)
    //         {
    //             divisors++;
    //             if (i != n / i)
    //                 divisors++;
    //         }
    //     }
    //     savedDivisors[n] = divisors;
    //     cout << divisors << '\n';
    // } //still fails for 10^6 test cases each different, so 10^6 computations took more than 1 second (given time limit is 1 second)

    // Best solution is to precompute the number of divisors for all numbers from 1 to 10^6

    for (int i = 1; i <MAX; i++)
    {   
        for (int j = i; j < MAX; j += i)
        {
            divisors[j]++;
        }
    }
    while (tc--)
    {
        int n;
        cin >> n;
        cout << divisors[n] << '\n';
    }

    return 0;
}