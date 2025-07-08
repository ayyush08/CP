#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9+7;

int binpow(int a, int b, int mod)
{
    int res = 1;
    a = a % mod;
    while (b > 0)
    {
        if(b&1) res = res * a % mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int exp = binpow(b, c, MOD - 1);
        cout << binpow(a, exp, MOD) << endl;
    }
    return 0;
}