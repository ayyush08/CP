#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;

int binpow(int a, int b, int mod)
{
    int res = 1;
    a%=mod;
    while(b>0){
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

signed main()
{
int tc; cin >> tc;
while(tc--)
{
    int a,b,c;cin >> a >> b >> c;
    int exp = binpow(b,c,MOD-1); // Fermat's Little Theorem for modular exponentiation
    cout << binpow(a, exp, MOD) << '\n';
}
return 0;
}

//Fermat's Little Theorem: a^k mod m = a^(k mod (m-1)) mod m when m is prime
// This is used to reduce the exponent in modular exponentiation when the exponent is large.