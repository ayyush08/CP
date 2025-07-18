//THIS QUESTION USES BINARY LIFTING CONCEPt
//Binary lifting is a technique used to answer queries about the ancestors of nodes in a tree or graph efficiently.
//It allows us to preprocess the tree so that we can find the k-th ancestor of a node in logarithmic time using a precomputed table of powers of two.
//This is particularly useful in problems where we need to find the k-th ancestor of a node


#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 200005;
const int LOG = 20;

int up[MAXN][LOG];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;

    for (int i = 2; i <= n; i++)
    {
        cin >> up[i][0]; // direct boss 2^0th
    }

    up[1][0] = -1; // general direct boss to -1

    // Precompute up[i][j] for j from 1 to LOG-1
    for (int j = 1; j < LOG; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1]; // up[i][j] is the 2^j-th boss of i
            else
                up[i][j] = -1; // If there's no boss, set it to -1
        }
    }


    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i=0;i<LOG;i++){
            if(k & (1LL << i)){ // Check if the i-th bit of k is set
                x = up[x][i]; // Move to the 2^i-th boss
                if(x == -1) break; // If we reach the top boss
            }
        }
        cout << x << '\n'; // Output the k-th boss of x
    }

    return 0;
}