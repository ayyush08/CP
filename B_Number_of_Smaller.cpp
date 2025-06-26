#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    vector<int> ans(m, 0);

    int cnt = 0, down = 0,up=0;
    while (down < m)
    {
        while(a[up]<b[down] && up<n){
            cnt++;
            up++;
        }
        ans[down]=cnt;
        down++;

    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}