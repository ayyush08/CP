#include <bits/stdc++.h>
using namespace std;

const int N1 = 101;
const int N2 = 101;
const int K1 = 11;
const int K2 = 11;
const int MOD = 1e8;
// i1 - number of footmen standing
// i2 - number of horsemen standing
// c1 - number of footmen so far consecutively in the legion
// c2 - number of horsemen so far consecutively in the legion
int dp[N1][N2][K1][K2];
int fun(int i1, int i2, int c1, int c2, int dp[][N2][K1][K2], int k1, int k2, int n1, int n2)
{
    if (i1 > n1 || i2 > n2) return 0;  // if we have more than n1 or n2 footmen or horsemen, return 0
    if (c1 > k1 || c2 > k2) return 0; // if we have more than k1 or k2 consecutive footmen or horsemen
    if(c1 > 0 && c2 > 0) return 0;  // if we have both footmen and horsemen in the legion, return 0
    if(i1+i2 == n1 + n2) return 1;  // if we have used all footmen and horsemen, return 1
    if (dp[i1][i2][c1][c2] != -1) return dp[i1][i2][c1][c2]; 

    int ans = 0;
    if (i1<n1 && c1+1 <=k1) // if we can add another footman to the legion
    {
        ans += fun(i1 + 1, i2, c1 + 1, 0, dp, k1, k2, n1, n2); //add a footman then proceed to next state
        ans %= MOD;
    }
    if(i2<n2 && c2+1 <=k2) // if we can add another horseman to the legion
    {
        ans += fun(i1, i2 + 1, 0, c2 + 1, dp, k1, k2, n1, n2); //add a horseman then proceed to next state
        ans %= MOD;
    }
    return dp[i1][i2][c1][c2] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int footmen, horsemen, max_footmen, max_horsemen;
    cin >> footmen >> horsemen >> max_footmen >> max_horsemen;


    memset(dp, -1, sizeof(dp));

cout << fun(0, 0, 0, 0, dp, max_footmen, max_horsemen, footmen, horsemen) ;
    return 0;
}