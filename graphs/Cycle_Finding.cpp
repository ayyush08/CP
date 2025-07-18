#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        edges.emplace_back(a, b, w);
    }

    vector<int> dist(n, 0), parent(n, -1);

    for (int src = 0; src < n; ++src) {
        int x = -1;
        // For each component, re-initialize distances for new source!
        for (int i = 0; i < n; ++i) dist[i] = 1e13;
        dist[src] = 0;
        parent[src] = -1;
        for (int i = 0; i < n; ++i) {
            x = -1;
            for (auto [u, v, w] : edges) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                    x = v;
                }
            }
        }
        if (x != -1) {
            // Get cycle
            for (int i = 0; i < n; ++i) x = parent[x];
            vector<int> cycle;
            int cur = x;
            do {
                cycle.push_back(cur);
                cur = parent[cur];
            } while (cur != x || cycle.size() == 1);
            cycle.push_back(cur);
            reverse(cycle.begin(), cycle.end());
            cout << "YES\n";
            for (int v : cycle) cout << v + 1 << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
