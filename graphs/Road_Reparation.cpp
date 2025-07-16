#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P pair<int, int>

// 1. Using Prim's algorithm
//  signed main()
//  {
//      ios::sync_with_stdio(false);
//      cin.tie(nullptr);
//      int n, m;
//      cin >> n >> m;
//      vector<vector<P>> adj(n);

//     for (int i = 0; i < m; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         a--;b--;
//         adj[a].push_back({b, c});
//         adj[b].push_back({a, c});
//     }

//     priority_queue<P, vector<P>, greater<P>> pq;
//     vector<int> visited(n, 0);
//     pq.push({0, 0});
//     int s = 0;
//     while (!pq.empty())
//     {
//         auto [weight, node] = pq.top();
//         pq.pop();

//         if (visited[node])
//             continue;
//         visited[node] = 1;
//         s += weight;
//         for (auto [adjNode, edgeWt] : adj[node])
//         {
//             if (!visited[adjNode])
//                 pq.push({edgeWt, adjNode});
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (!visited[i])
//         {
//             cout << "IMPOSSIBLE";
//             return 0;
//         }
//     }
//     cout << s;

//     return 0;
// }

// 2. Using Kruskal's algorithm
struct DSU
{
    vector<int> parent;
    vector<int> rank;
    void init(int n)
    {
        parent.assign(n, 0);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n, 0);
    }
    int find(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
    void merge(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    DSU dsu;
    dsu.init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {c, a, b};
    }

    sort(edges.begin(), edges.end());

    int s=0, cnt=0;

    for(auto &e:edges){
        int w = e[0];
        int u = e[1];
        int v = e[2];
        if(dsu.find(u) != dsu.find(v)){ //if not a common ancestor meaning they are not connected hence we can merge them (as already sorted by weight in non-decreasing order)
            dsu.merge(u, v);
            s += w;
            cnt++;
        }

        if(cnt == n-1) break;
    }
    if(cnt < n-1){
        cout << "IMPOSSIBLE";
    } else {
        cout << s;
    }
}