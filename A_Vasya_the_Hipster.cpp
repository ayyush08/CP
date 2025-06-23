#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int mn = min(a, b);
    int leftOverSocks = abs(a - b);
    int daysDifferentSocks = mn;
    int daysSameSocks = leftOverSocks / 2;
    cout << daysDifferentSocks << " " << daysSameSocks << endl;
    return 0;
}