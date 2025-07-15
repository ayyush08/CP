#include <bits/stdc++.h>
using namespace std;

int maxDiameter = 0;
vector<int> depth;

void dfs(int node, vector<vector<int>>& graph, vector<int>& visited) {
    visited[node] = 1;
    int best1 = 0, best2 = 0;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
            int d = depth[neighbor] + 1;

            if (d > best1) {
                best2 = best1;
                best1 = d;
            } else if (d > best2) {
                best2 = d;
            }
        }
    }

    depth[node] = best1;
    maxDiameter = max(maxDiameter, best1 + best2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;  
        adj[u].push_back(v);
        adj[v].push_back(u);         // ⭐ undirected!
    }

    depth.assign(n, 0);
    vector<int> visited(n, 0);

    dfs(0, adj, visited);

    cout << maxDiameter << endl;
}
