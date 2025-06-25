#include <bits/stdc++.h>
using namespace std;
int main()
{

    int tc;
    cin >> tc;
    while (tc--)
    {
        int m, n;
        cin >> m >> n;
        int mat[m][n];
        int mx = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
                mx = max(mx, mat[i][j]);
            }
        }
        int row[m] = {0}, col[n] = {0};
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == mx)
                {
                    row[i]++;
                    col[j]++;
                    count++;
                }
            }
        }
        
        bool flag = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int total = row[i] + col[j] - ( mat[i][j] == mx );
                if(total == count){
                    flag = true;
                    break;
                }
            }
        }
        cout << (flag ? mx - 1 : mx) << '\n';

    }
    return 0;
}

/*

1. Find max
2. Store count of max in each column and row
3. check total max count per R & C
4. If total == max then ans=max-1 else ans = max
*/