#include <bits/stdc++.h>
using namespace std;


long long  getSumOfDigits(long long n)
{
    long long  sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{

    int tc; cin >> tc;
    while(tc--){
        long long n; cin >> n;
        long long  curr = n;
        long long  ans = -1;
        while(true){
            long long sum = getSumOfDigits(curr);
            if(__gcd(curr,sum)>1){
                ans = curr;
                break;
            }
            curr++;
        }
        cout << ans << endl;
    }

    return 0;
}

