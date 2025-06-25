


#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    int cnt = 0;
    for (int i = 1; i * i <= x; i++)
    {
        int a = i, b = x / i;
        if (a <= n && b <= n)
        {
            if (x % a == 0 ){
                cnt++;
                if(a!=b) cnt++;
            }
        }
    }
    cout << cnt << '\n';

    return 0;
}