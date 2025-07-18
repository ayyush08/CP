#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n; cin >> n;
vector<vector<int>> dist(n, vector<int>(n,-1));

for(int i = 0; i < n; i++)
{
    for(int j = 0; j < n; j++)
    {
        int val;
        cin >> val;
        dist[i][j] = val;
    }
}

vector<int> greg_deletes(n);
for(int i = 0; i < n; i++)
{
    cin >> greg_deletes[i];
    greg_deletes[i]--;
}

reverse(greg_deletes.begin(), greg_deletes.end());
vector<bool> visited(n, false);
vector<int>ans;

for(int k=0;k<n;k++){
    int v = greg_deletes[k];
    visited[v] = true;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][v]==-1 || dist[v][j]==-1) continue;
            if(dist[i][j] == -1) dist[i][j] = dist[i][v] + dist[v][j];
            else
            dist[i][j] = min(dist[i][j], dist[i][v] + dist[v][j]);
        }
    }


    int tot = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]) continue;
        for(int j=0;j<n;j++){
            if(!visited[j]) continue;
            tot+= dist[i][j];
        }
    }

    ans.push_back(tot);
}

reverse(ans.begin(), ans.end());

for(int a:ans) {
    cout << a << " ";
}

return 0;
}