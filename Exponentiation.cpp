// Modular Exponentiation
//(Also called: Binary Exponentiation / Fast Exponentiation / binpow)

// Modular Exponentiation (Binary Exponentiation / Fast Exponentiation / binpow)
// ============================================================================

// 🎯 Why it's important:
// Computing a^n % m efficiently, where n can be as large as 10^18 or more.
// Brute-force O(n) methods will TLE. Binary Exponentiation reduces time to O(log n).

// 🔍 Main Idea (Exponentiation by Squaring):
// When calculating a^n mod m:
//
// If n is even:
//    a^n = (a^(n/2))^2
//
// If n is odd:
//    a^n = a * a^(n-1)
//
// This reduces the problem size by half each time, making it efficient
// for recursion or iteration.

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7; 
long long binpow(long long a, long long b, long long mod)
{
    long long res = 1; // Start with identity (anything^0 = 1)
    a %= mod;          // If a > mod, bring it within mod
    while (b > 0)
    {
        if (b & 1)               // If current bit is 1
            res = res * a % mod; // Multiply result by current base
        a = a * a % mod;         // Square the base for the next bit
        b >>= 1;                 // Go to the next bit (divide b by 2)
    }
    return res;
}

signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        cout << binpow(a, b, MOD) << '\n';
    }
    return 0;
}