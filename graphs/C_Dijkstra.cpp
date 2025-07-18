#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // because undirected
    }

vector<int>dist(n+1, LLONG_MAX),parent(n+1, -1);
vector<int>path;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
pq.push({0,1});
dist[1] = 0;
while(!pq.empty()){
    auto it = pq.top();
    pq.pop();

    int node = it.second;
    int wt = it.first;

    if(node==n) break; // reached destination

    for(auto it: adj[node]){
        int adjNode = it.first;
        int edgeWt = it.second;
        if(wt+edgeWt<dist[adjNode]){
            dist[adjNode] = wt + edgeWt;
            pq.push({dist[adjNode], adjNode});
            parent[adjNode] = node;
        }
    }
}

if(dist[n] == LLONG_MAX) {
    cout << -1;
}else{
    for(int i = n; i != -1; i = parent[i]) {
        path.push_back(i);
    }
    reverse(path.begin(), path.end());
    for(auto p:path){
        cout << p << " ";
    }

}
return 0;
}